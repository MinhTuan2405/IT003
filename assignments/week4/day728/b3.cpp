
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

void LRN(Tree t) {
    if (t == NULL) return;
    LRN(t->l);
    LRN(t->r);
    cout << t->data << " ";
}

void LNR(Tree t) {
    if (t == NULL) return;
    LNR(t->l);
    cout << t->data << " ";
    LNR(t->r);
}

void listLeafs (Tree t) {
    if (t == NULL) return;
    listLeafs (t -> l);
    listLeafs (t -> r);
    if (t -> l == NULL && t -> r == NULL) cout << t -> data << " ";
}

void listNodesWithOneChild (Tree t) {
    if (t == NULL) return;
    if (t -> l == NULL && t -> r
    || t -> r == NULL && t -> l) cout << t -> data << " ";
    listNodesWithOneChild (t -> l);
    listNodesWithOneChild (t -> r);
}

void listNodesWithTwoChildren (Tree t) {
    if (t == NULL) return;
    if (t -> l && t -> r) cout << t -> data << " ";
    listNodesWithTwoChildren (t -> l);
    listNodesWithTwoChildren (t -> r);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
