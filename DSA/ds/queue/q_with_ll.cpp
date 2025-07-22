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

struct Queue {
    Node* head;
    Node* tail;
    int count;

    Queue() {
        head = tail = nullptr;
        count = 0;
    }

    void push(int data) {
        Node* newNode = makeNode(data);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void pop() {
        if (empty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        count--;
        if (head == nullptr) tail = nullptr;
    }

    int front() {
        if (empty()) throw runtime_error("Queue is empty");
        return head->data;
    }

    int back() {
        if (empty()) throw runtime_error("Queue is empty");
        return tail->data;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Queue: ";
    q.display();

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    q.pop();
    cout << "After pop, front: " << q.front() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
