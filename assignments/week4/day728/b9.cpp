#include <iostream>
using namespace std;

struct Node {
    string book_name;
    int book_price;
    int book_weight;
    int book_npage;
    Node* l;
    Node* r;
};

typedef Node* Tree;

Tree makeNode(string book_name, int book_price, int book_weight, int book_npage) {
    Tree n = new Node;
    n->book_name = book_name;
    n->book_price = book_price;
    n->book_weight = book_weight;
    n->book_npage = book_npage;
    n->l = n->r = NULL;
    return n;
}

void insert(Tree &t, string book_name, int book_price, int book_weight, int book_npage, bool &out) {
    if (t == NULL) {
        t = makeNode(book_name, book_price, book_weight, book_npage);
        return;
    }

    if (t->book_name == book_name) {
        out = true;
        return;
    } else if (book_name < t->book_name) insert(t->l, book_name, book_price, book_weight, book_npage, out);
    else  insert(t->r, book_name, book_price, book_weight, book_npage, out);
}

void inputTree(Tree &t) {
    int n;
    cin >> n;
    cin.ignore(); 
    for (int i = 0; i < n; ++i) {
        string book_name;
        int book_price, book_weight, book_npage;
        getline(cin, book_name);
        cin >> book_price >> book_weight >> book_npage;
        cin.ignore(); 

        bool out = false;
        insert(t, book_name, book_price, book_weight, book_npage, out);
        if (out) {
            cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
            return;
        }
    }
}

int depthOfTree(Tree t) {
    if (t == NULL) return -1;
    int leftHeight = depthOfTree(t->l);
    int rightHeight = depthOfTree(t->r);
    return 1 + max(leftHeight, rightHeight);
}

void LNR(Tree t) {
    if (t == NULL) return;
    LNR(t->l);
    cout << t->book_name << " " << t->book_price << " " << t->book_weight << " " << t->book_npage << '\n';
    LNR(t->r);
}

void listLeftBook(Tree t, string bn) {
    if (t == NULL) return;

    if (t->book_name == bn) {
        if (t->l == NULL) {
            cout << "Node nay la node la'" << endl;
        } else {
            LNR(t->l);
        }
        return;
    }

    if (bn < t->book_name) {
        listLeftBook(t->l, bn);
    } else {
        listLeftBook(t->r, bn);
    }
}

int main() {
    Tree T = NULL;
    inputTree(T);

    string book_name;
    getline(cin, book_name);

    cout << depthOfTree(T) << "\n";
    listLeftBook(T, book_name);

    return 0;
}
