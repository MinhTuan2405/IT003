
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void xuat(List &l){
    for(Node *p = l.head; p != NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
}

void reverse_list(List &l){
    Node* prev = NULL;
    Node* curr = l.head;
    Node* next = NULL;

    l.tail = curr;

    while (curr) {
        next = curr->next;   
        curr->next = prev;   
        prev = curr;        
        curr = next;
    }

    l.head = prev;
}


int main()
{
    List l; list_initializing(l);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int x;
    do{
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while(true);

    for(int i = 0; i < 51; i++) reverse_list(l);

    xuat(l);

    return 0;
}
