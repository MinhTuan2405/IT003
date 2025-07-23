
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};



void Init (Stack &s) {
    s.n = 0;
    for (int i = 0; i < MAX; ++i) {
        s.arr[i] = NULLDATA;
    }
    return;
}

void Push (Stack &s, int x) {
    s.arr[s.n] = x;
    s.n += 1;
    return; 
}

void printStack (Stack &s) {
    if (s.n <= 0) {
        cout << "Stack is empty";
        return;
    }
    
    for (int i = 0; i < s.n; ++i) {
        cout << s.arr[i] << " "; 
    }
    
}

void Pop (Stack &s) {
    s.arr[s.n] = NULLDATA;
    s.n -= 1;
    return;
}

int Top (Stack &s) {
    if (s.n <= 0) return -1;
    return s.arr[s.n -1];
}


int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}




