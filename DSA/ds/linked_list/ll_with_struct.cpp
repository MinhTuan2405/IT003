#include <iostream>

struct Node {
    int data;
    Node* next;
};

// create a new node that independent from others
Node* makeNode (int data) {
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

struct LinkedList {
    Node* head;
    Node* tail;
};

// iniitalize the list
void init (LinkedList *&list) {
    list = new LinkedList;
    list -> head = list -> tail = NULL;
    return;
}
 
// display list
void display (LinkedList *list) {
    Node* temp = list -> head;
    while (temp) {
        std::cout << temp -> data << " (" << temp << ") -> "; // data
        temp = temp -> next;
    }
    std::cout << "NULL";
    return;
}

// length
int length (LinkedList *list) {
    int len = 0;
    Node* temp = list -> head;
    while (temp) {
        len++;
        temp = temp -> next;
    }
    return len;
}

// INSERT OPERATION
// front
void unshift(LinkedList*& list, int data) {
    Node* newNode = makeNode(data);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
}

// back
void append(LinkedList*& list, int data) {
    Node* newNode = makeNode(data);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// in specific position                     - treat the list as an array, the fist element has the index is 0
void insert(LinkedList*& list, int data, int position) {
    if (position <= 0 || list->head == NULL) {
        unshift(list, data);
    } else if (position >= length(list)) {
        append(list, data);
    } else {
        Node* newNode = makeNode(data);
        Node* temp = list->head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


// DELETE OPERATION
// front
void shift (LinkedList *&list) {
    if (list -> head == NULL) return;

    Node* temp = list -> head;
    list -> head = list -> head -> next;

    // free the unused space
    delete temp;
    temp = NULL;
    return;
}

// back
void pop_back (LinkedList *&list) {
    if (list -> head == NULL) return;

    if (list->head == list->tail) {
        delete list->head;
        list->head = list->tail = NULL;
        return;
    }

    Node* temp = list -> head;
    while (temp -> next -> next) {
        temp = temp -> next;
    }

    Node* tmpStorage = temp -> next;
    temp -> next = NULL;

    list -> tail = temp;
    delete tmpStorage;
    tmpStorage = NULL;

    return;
}


// in the specific postion
void remove (LinkedList *&list, int position) {
    if (position < 0 || list->head == NULL) return;

    if (position == 0) {
        shift (list);
        return;
    }

    if (position >= length (list) - 1) {
        pop_back (list);
        return; 
    }

    Node* prevNode = NULL;
    Node* curr = list -> head;
    Node* nextNode = curr -> next;
    for (int i = 0; i < position; i++) {
        prevNode = curr;
        curr = curr -> next;
        nextNode = curr -> next;
    }

    prevNode -> next = nextNode;
    delete curr;
    curr = NULL;
}


// SEARCH OPERATION
int search (LinkedList *&list, int target) {
    int index = 0;
    Node* temp = list -> head;
    while (temp) {
        index++;
        if (temp -> data == target) {
            return index;
        }
        temp = temp -> next;
    }

    return -1;
}

// SORT OPERATION
void sort(LinkedList*& list, bool desc = false) {
    if (list->head == NULL || list->head->next == NULL) return;

    for (Node* i = list->head; i->next; i = i->next) {
        for (Node* j = i->next; j; j = j->next) {
            bool condition = desc ? (i->data < j->data) : (i->data > j->data);
            if (condition) {
                std::swap(i->data, j->data);
            }
        }
    }
}


// MAIN kiểm thử
int main() {
    LinkedList* myList;
    init(myList);

    append(myList, 30);
    append(myList, 10);
    append(myList, 50);
    unshift(myList, 5);
    insert(myList, 20, 2);

    std::cout << "now: ";
    display(myList);

    std::cout << "len: " << length(myList) << "\n";

    int pos = search(myList, 10);
    if (pos != -1)
        std::cout << "find 10 at: " << pos << "\n";
    else
        std::cout << "can not find 10\n";

    std::cout << "del el at pos 2\n";
    remove(myList, 2);
    display(myList);

    std::cout << "asc sort:\n";
    sort(myList);
    display(myList);

    std::cout << "desc sort:\n";
    sort(myList, true);
    display(myList);

    return 0;
}