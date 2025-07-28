
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

int depthOfTree (Tree t) {
    if (t == NULL) return -1;
    int leftHeight = depthOfTree (t -> l);
    int rightHeight = depthOfTree (t -> r);
    return 1 + max (leftHeight, rightHeight);
}

int isAVL (Tree t) {
    if (t == NULL) return 0;

    int ld = depthOfTree (t -> l);
    int rd = depthOfTree (t -> r);

    int a = ld - rd;
    if (a < 0) a = -a;

    if (a > 1) return 0;

    return isAVL (t -> l) && isAVL (t -> r);
}




int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}
