
#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

struct node
{
    int info;
    node *next;
};

struct Stack
{
    node *pHead; 
};

void Init (Stack &s) {
    s.pHead = NULL;
    return;
}

void printStack (Stack s) {
    node* tmp = s.pHead;
    while (tmp) {
        cout << tmp -> info;
        tmp = tmp -> next;
    }
    return;
}


void DecimaltoBinary1 (int n, Stack &s) {
    node* tmp = s.pHead;

    if (n == 0) {
        node* newNode = new node;
        newNode -> info = 0;
        newNode -> next = s.pHead;
        s.pHead =newNode;
    }

    while (n) {
        int a = n % 2;
        node* newNode = new node;
        newNode -> info = a;
        newNode -> next = s.pHead;
        s.pHead =newNode;
        n /= 2;
    }
    
}



int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

