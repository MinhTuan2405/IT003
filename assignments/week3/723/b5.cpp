#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* makeNode(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack {
    Node* root;
};

void init(Stack *&s) {
    s = new Stack;
    s->root = NULL;
}

void push(Stack *&s, string data) {
    Node* newNode = makeNode(data);
    newNode->next = s->root;
    s->root = newNode;
}

void pop(Stack *&s) {
    if (s->root == NULL) return;
    Node* temp = s->root;
    s->root = s->root->next;
    delete temp;
}

Node* top(Stack *s) {
    return s->root;
}

int main() {
    Stack *s;
    init(s);

    string name;
    while (getline(cin, name)) {
        if (name == "-1") break;
        push(s, name);
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pop(s);
    }

    Node* t = top(s);
    cout << t -> data;

    return 0;
}
