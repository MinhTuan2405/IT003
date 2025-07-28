#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* l;
    Node* r;
};

typedef Node* Tree;

Tree makeNode (int x) {
    Tree n = new Node;
    n -> data = x;
    n -> l = NULL;
    n -> r = NULL;
    return n;
}

void insert(Tree &t, int x, bool &out) {
    if (t == NULL) {
        t = makeNode (x); 
        return;
    }

    if (t->data == x) out = true; 
    else if (x < t->data) insert(t->l, x, out);
    else insert(t->r, x, out);
}

void inputTree(Tree &t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        bool out = false;
        insert(t, x, out);
        if (out) {
            cout<<"Bi trung gia tri, ket thuc qua trinh tao cay"<<endl;
            return;
        }
    }
}

void NLR(Tree t) {
    if (t == NULL) return;
    cout << t->data << " ";
    NLR(t->l);
    NLR(t->r);
}


void rotateLeft(Tree &t) {
    if (t == NULL) {
        cout << "\nKhong the xoay vi cay rong";
        return;
    }

    if (t->r == NULL) {
        cout << "\nKhong the xoay trai vi khong co nut con ben phai";
        return;
    }

    Tree newRoot = t->r;
    t->r = newRoot->l;
    newRoot->l = t;
    t = newRoot;
}


int main() {
    Tree T = NULL;
    inputTree(T); 
    cout << "NLR: ";
    NLR(T);
    rotateLeft (T);

    cout << "\nNLR: ";
    NLR(T);
    return 0;
}
