/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct node {
    int data;
    node* left;
    node* right;
};

typedef node* Tree;

node* newNode(int val) {
    node* n = new node;
    n->data = val;
    n->left = 0;
    n->right = 0;
    return n;
}

void insert(Tree &root, int data) {
    if (root == 0) {
        root = newNode(data);
        return;
    }
    if (data < root->data) insert(root->left, data);
    else if (data > root->data) insert(root->right, data);
}

void inputTree(Tree &root) {
    int n; cin  >> n;
    int value, i = 0;
    while (std::cin >> value && i <= n) {
        insert(root, value);
        ++i;
    }
}

struct el {
    node* data;
    el* next;
};

el* makenode(node* data) {
    el* n = new el;
    n->data = data;
    n->next = 0;
    return n;
}

struct queue {
    el* root;
    el* tail;
};

void init(queue* &q) {
    q = new queue;
    q->root = 0;
    q->tail = 0;
}

void pop(queue* &q) {
    if (q->root == 0) return;
    el* tmp = q->root;
    q->root = q->root->next;
    delete tmp;
}

node* top(queue* q) {
    if (q->root == 0) return 0;
    return q->root->data;
}

void append(queue* &q, node* newdata) {
    el* newnode = makenode(newdata);
    if (q->root == 0) {
        q->root = q->tail = newnode;
    } else {
        q->tail->next = newnode;
        q->tail = newnode;
    }
}

void nodesWithLevel(Tree root, int level) {
    if (root == 0) return;
    queue* q;
    init(q);
    append(q, root);
    int current_level = 0;

    while (q->root != 0 && current_level < level) {
        int size = 0;
        el* temp = q->root;
        while (temp) {
            ++size;
            temp = temp->next;
        }

        for (int i = 0; i < size; ++i) {
            node* front = top(q);
            pop(q);
            if (front->right) append(q, front->right);
            if (front->left) append(q, front->left);
        }
        ++current_level;
    }

    el* tmp = q->root;
    while (tmp) {
        std::cout << tmp->data->data << " ";
        tmp = tmp->next;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
	Tree T = NULL;
	inputTree(T);
    int k; cout<<"Enter k: "; cin >>k;
    cout<<"\nList of nodes with level "<<k<<" (R->L) : ";
    nodesWithLevel(T, k);

	return 0;
}