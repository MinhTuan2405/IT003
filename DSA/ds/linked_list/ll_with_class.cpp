#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor để giải phóng bộ nhớ
    ~LinkedList() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // Hiển thị danh sách
    void display() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp -> data << " (" << temp << ") -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
        return;
    }

    // Trả về độ dài
    int length() const {
        int len = 0;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    // Thêm đầu
    void unshift(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Thêm cuối
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Thêm tại vị trí
    void insert(int data, int position) {
        if (position <= 0 || !head) {
            unshift(data);
        } else if (position >= length()) {
            append(data);
        } else {
            Node* newNode = new Node(data);
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Xoá đầu
    void shift() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
    }

    // Xoá cuối
    void pop_back() {
        if (!head) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    // Xoá tại vị trí
    void remove(int position) {
        if (position < 0 || !head) return;
        if (position == 0) {
            shift();
        } else if (position >= length() - 1) {
            pop_back();
        } else {
            Node* prev = head;
            for (int i = 0; i < position - 1; i++) {
                prev = prev->next;
            }
            Node* del = prev->next;
            prev->next = del->next;
            delete del;
        }
    }

    // Tìm vị trí phần tử
    int search(int target) const {
        int index = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == target) return index;
            index++;
            temp = temp->next;
        }
        return -1;
    }

    // Sắp xếp
    void sort(bool desc = false) {
        if (!head || !head->next) return;

        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                bool cond = desc ? (i->data < j->data) : (i->data > j->data);
                if (cond) std::swap(i->data, j->data);
            }
        }
    }
};

int main() {
    LinkedList myList;

    myList.append(30);
    myList.append(10);
    myList.append(50);
    myList.unshift(5);
    myList.insert(20, 2);

    std::cout << "now: ";
    myList.display();

    std::cout << "len: " << myList.length() << "\n";

    int pos = myList.search(10);
    if (pos != -1)
        std::cout << "find 10 at: " << pos << "\n";
    else
        std::cout << "can not find 10\n";

    std::cout << "del el at pos 2\n";
    myList.remove(2);
    myList.display();

    std::cout << "asc sort:\n";
    myList.sort();
    myList.display();

    std::cout << "desc sort:\n";
    myList.sort(true);
    myList.display();

    return 0;
}
