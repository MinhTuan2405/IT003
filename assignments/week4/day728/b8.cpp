
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* l;
    Node* r;
};

typedef Node* Tree;

void deleteNode(Tree &t, int x);


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


Tree findMin(Tree t) {
    while (t->l != NULL) t = t->l;
    return t;
}

void removeRoot(Tree &t) {
    if (t == NULL) return;

    if (t->l == NULL && t->r == NULL) {
        delete t;
        t = NULL;
    }
    else if (t->l == NULL) {
        Tree temp = t;
        t = t->r;
        delete temp;
    }
    else if (t->r == NULL) {
        Tree temp = t;
        t = t->l;
        delete temp;
    }
    else {
        Tree minRight = findMin(t->r);
        t->data = minRight->data;                  
        deleteNode(t->r, minRight->data);          
    }
}

void deleteNode(Tree &t, int x) {
    if (t == NULL) return;
    if (x < t->data) deleteNode(t->l, x);
    else if (x > t->data) deleteNode(t->r, x);
    else removeRoot(t); 
}



int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
    int x; cout<<"\nEnter the element you want to delete: ";cin>>x;
    deleteNode(T,x);
    cout<<"\nNLR: "; NLR(T);

	return 0;
}
