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

    while (n) {
        int a = n % 2;
        node* newNode = new node;
        newNode -> info = a;
        newNode -> next = s.pHead;
        s.pHead =newNode;
        n /= 2;
    }
    
}