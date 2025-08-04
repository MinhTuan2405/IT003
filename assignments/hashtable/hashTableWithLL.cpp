/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

//###INSERT CODE HERE -
struct node {
    int data;
    node* next;
};

struct Hash {
    int m;
    node* bucket[MAX];
};

void initHash (Hash &H) {
    for (int i = 0; i < H.m; ++i) {
        H.bucket[i] = NULL;
    }
}

int getKey (int x, Hash H) {
    return x % H.m;
}

node* createNode(int x) {
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void insertHash(Hash &H, int x) {
    int key = getKey(x, H);
    node* &head = H.bucket[key]; 

    node* newNode = createNode(x);

    if (head == NULL || x < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    node* prev = NULL;
    node* curr = head;
    while (curr != NULL && curr->data < x) {
        prev = curr;
        curr = curr->next;
    }

    newNode->next = curr;
    prev->next = newNode;
}

void traverseAllHash(Hash H) {
    for (int i = 0; i < H.m; ++i) {
        cout << "Bucket " << i << ": ";
        node* p = H.bucket[i];
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

