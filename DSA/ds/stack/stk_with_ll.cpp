#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* makeNode(int data) {
    Node* newNode = new Node{data, nullptr};
    return newNode;
}

struct Stack {
    Node* topNode;
    int count;

    Stack() {
        topNode = nullptr;
        count = 0;
    }

    void push(int data) {
        Node* newNode = makeNode(data);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    void pop() {
        if (empty()) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        temp = NULL;
        count--;
    }

    int top() {
        if (empty()) throw runtime_error("Stack is empty");
        return topNode->data;
    }

    bool empty() {
        return topNode == nullptr;
    }

    int size() {
        return count;
    }

    void display() {
        Node* temp = topNode;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.display();

    cout << "Top: " << s.top() << endl;

    s.pop();
    cout << "After pop, top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
