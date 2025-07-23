
#include <iostream>
using namespace std;

struct node {
    int data;
    node* pNext;
};

node* makeNode (int data) {
    node* newNode = new node;
    newNode -> data = data; 
    newNode -> pNext = nullptr; 
    return newNode;
}

struct List {
    node* head;
};


void Init (List &l){
    l.head = NULL;
}

void inputList (List &l, int sz) {
    node* curr = NULL;
    for (int i = 0; i < sz; ++i) {
        int x; cin >> x;
        node* newNode = makeNode (x);
        if (l.head == NULL) l.head = newNode;
        else {
            curr -> pNext = newNode;
        }
        curr = newNode;
    }
}

void mergeList(List &l1, List &l2, List &l3) {
    node* t1 = l1.head;
    node* t2 = l2.head;
    node* tail = NULL;  

    while (t1 && t2) {
        node* newNode;
        if (t1->data <= t2->data) {
            newNode = makeNode(t1->data);
            t1 = t1->pNext;
        } else {
            newNode = makeNode(t2->data);
            t2 = t2->pNext;
        }

        if (l3.head == NULL) {
            l3.head = newNode;
            tail = newNode;
        } else {
            tail->pNext = newNode;
            tail = newNode;
        }
    }

    while (t1) {
        node* newNode = makeNode(t1->data);
        if (l3.head == NULL) {
            l3.head = newNode;
            tail = newNode;
        } else {
            tail->pNext = newNode;
            tail = newNode;
        }
        t1 = t1->pNext;
    }

    while (t2) {
        node* newNode = makeNode(t2->data);
        if (l3.head == NULL) {
            l3.head = newNode;
            tail = newNode;
        } else {
            tail->pNext = newNode;
            tail = newNode;
        }
        t2 = t2->pNext;
    }
}


void outputList(List L)
{
	for(node* p = L.head; p!=NULL; p=p->pNext)
		cout << p->data << " ";

}
int main()
{
    List L1, L2, L3;
    Init(L1);Init(L2);Init(L3);

    int n,m; cin>>n;
    inputList(L1,n);
    cin>>m;
    inputList(L2,m);


    mergeList(L1,L2,L3);
    outputList(L3);

    return 0;
}
