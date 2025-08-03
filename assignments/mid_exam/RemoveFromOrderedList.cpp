/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};
struct List
{
    node *head,*tail;
};
node* getNode(int x)
{
    node *p=new node;
    if (p)
    {
        p->info=x;
        p->next=NULL;
    }
    return p;
}


//###INSERT CODE HERE -
void Init(List &L)
{
    L.head = L.tail = NULL;
}

void inputList(List &L, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        node *p = getNode(x);
        if (L.head == NULL)
        {
            L.head = L.tail = p;
        }
        else
        {
            L.tail->next = p;
            L.tail = p;
        }
    }
}

void outputList(List L)
{
    if (L.head == NULL) {
        cout << "List is empty";
        return;
    }
    for (node *p = L.head; p != NULL; p = p->next)
    {
        cout << p->info << " ";
    }
}

int removeElement(List &L, int x)
{
    node *p = L.head, *prev = NULL;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (p == L.head)
            {
                L.head = L.head->next;
                if (p == L.tail) L.tail = NULL;
            }
            else
            {
                prev->next = p->next;
                if (p == L.tail) L.tail = prev;
            }
            delete p;
            return 1;
        }
        prev = p;
        p = p->next;
    }
    return 0;
}

int main()
{
    List L;
    Init(L);
    int n,x; cin>>n;
    inputList(L,n);
    cout<<"Created List: ";
    outputList(L);
    cout<<"\nEnter a number to remove: ";
    cin>>x;
    if(removeElement(L,x)==0) cout<<"\nnot found";
    else
    {
        cout<<"\nUpdated List: ";
        outputList(L);
    }
    return 0;
}

