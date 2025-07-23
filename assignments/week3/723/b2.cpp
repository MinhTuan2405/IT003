
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int t; // t là chỉ số của phần tử cuối mảng, tức là đỉnh stack
};
void Init(Stack &S)
{
    S.t=-1; //Khi stack chưa có phần tử nào thì top được khởi tạo là -1,
            // nếu khởi tạo t = 0 là SAI vì khi đó sẽ hiểu top tại a[0]
}



void Push (Stack &s, int x) {
    s.arr[s.t + 1] = x;
    s.t += 1;
    return; 
}

void printStack (Stack &s) {
    if (s.t <= -1) {
        cout << "Stack is empty";
        return;
    }
    
    for (int i = 0; i <= s.t; ++i) {
        cout << s.arr[i] << " "; 
    }
    
}

void Pop (Stack &s) {
    s.arr[s.t] = NULLDATA;
    s.t -= 1;
    return;
}

int Top (Stack &s) {
    if (s.t <= -1) return -1;
    return s.arr[s.t];
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




