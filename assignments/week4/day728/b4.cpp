
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


void LNR(Tree t) {
    if (t == NULL) return;
    LNR(t->l);
    cout << t->data << " ";
    LNR(t->r);
}

Node* Search (Tree t, int x) {
    if (t == NULL) return NULL;
    Node* tmp = t;
    if (tmp -> data == x) return tmp;
    else if (tmp -> data < x) return Search (tmp -> r, x);
    else return Search (tmp -> l, x);
}

int minValue (Tree t) {
    if (t -> l) return minValue (t -> l);
    return t -> data;
}

int maxValue (Tree t) {
    if (t -> r) return maxValue ( t-> r);
    return t -> data;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
