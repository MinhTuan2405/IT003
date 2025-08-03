/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
#define MAX 2000
#define NULLDATA -1
using namespace std;

struct Stack1
{
    char arr[MAX];
    int n; // so luong phan tu cua stack
};

struct node
{
    char info;
    node *next;
};
struct Stack2
{
    node *pHead; // pTail khong co cung duoc

};

//###INSERT CODE HERE -
void init(Stack2 &s) {
    s.pHead = NULL;
}

node* createNode(char x) {
    node* p = new node;
    if (p) {
        p->info = x;
        p->next = NULL;
    }
    return p;
}

void push(Stack2 &s, char x) {
    node* p = createNode(x);
    if (p) {
        p->next = s.pHead;
        s.pHead = p;
    }
}

char pop(Stack2 &s) {
    if (s.pHead == NULL) return NULLDATA;
    node* temp = s.pHead;
    char x = temp->info;
    s.pHead = s.pHead->next;
    delete temp;
    return x;
}

bool isEmpty(Stack2 s) {
    return s.pHead == NULL;
}

void reverseWords(string str) {
    Stack2 st;
    init(st);

    for (int i = 0; i <= str.length(); ++i) {
        char ch = str[i];
        if (ch != ' ' && ch != '\0') {
            push(st, ch);
        } else {
            while (!isEmpty(st)) {
                cout << pop(st);
            }
            if (ch == ' ') cout << ' ';
        }
    }
}

int main()
{
	string str;
	getline(cin, str);
	reverseWords(str);
	return 0;
}

