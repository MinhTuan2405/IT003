/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;



//###INSERT CODE HERE -
struct node {
    int data;
    node* left;
    node* right;
};

node* makenode (int data) {
    node* newnod = new node;
    newnod -> data = data;
    newnod -> left = NULL;
    newnod -> right = NULL;
    return newnod;
}

void insert (node* &root, int data) {
    if (root == NULL) {
        root = makenode (data);
        return;
    }

    if (data < root -> data) insert (root -> left, data);
    else if (data > root -> data) insert (root -> right, data);
}

// bool find (node* root, int data) {
//     if (root == NULL) return false;

//     if (root -> data == data) return true;
//     else if (root -> data < data) return find (root -> right, data);
//     else return find (root -> left, data);
// }

// node* findmin (node* root) {
//     if (!root -> left) return root;
//     else return findmin (root -> left);
// }


bool find(node* root, int data) {
    node* cur = root;
    while (cur != NULL) {
        if (cur->data == data) return true;
        else if (data < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return false;
}

node* findmin(node* root) {
    node* cur = root;
    while (cur && cur->left != NULL) {
        cur = cur->left;
    }
    return cur;
}

void remove (node* &root, int data) {
    if (root == NULL) return;

    if (root -> data < data) remove (root -> right, data);
    else if (root -> data > data) remove (root -> left, data);

    else if (root -> data == data) {
        if (!root -> left && !root -> right) {
            delete root;
            root = NULL;
        }

        else if (root -> left == NULL) {
            node* tmp = root;
            root = root -> right;
            delete tmp;
            tmp = NULL;
        }

        else if (root -> right == NULL) {
            node* tmp = root;
            root = root -> left;
            delete tmp;
            tmp = NULL;
        }
        // root -> left && root -> right
        else {
            node* minnode = findmin (root -> right);
            root -> data = minnode -> data;
            remove (root -> right, minnode -> data);
        }
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    node* tree = NULL;
    int command;
    while (cin >> command) {
        if (command == 1) {
            int newuser; cin >> newuser;
            insert (tree, newuser);
        }
        
        else if (command == 2) {
            int user; cin >> user;
            if (find (tree, user)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }

        else if (command == 3) {
            int user; cin >> user;
            remove (tree, user);
        }
    }
}