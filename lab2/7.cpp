#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* insert(Node* head, int x, int p) {
    Node* newNode = new Node(x);
    if (p == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    for (int i = 0; i < p - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* remove(Node* head, int p) {
    if (!head) return nullptr;
    if (p == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    Node* current = head;
    for (int i = 0; i < p - 1; i++) {
        current = current->next;
    }
    Node* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
    return head;
}

void print(Node* head) {
    if (!head) {
        cout << "-1" << endl;
        return;
    }
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* replace(Node* head, int p1, int p2) {
    Node* current = head;
    Node* nodeToMove = nullptr;
    Node* prevToMove = nullptr;

    for (int i = 0; i < p1; i++) {
        prevToMove = current;
        current = current->next;
    }
    nodeToMove = current;

    if (prevToMove) {
        prevToMove->next = current->next;  // Remove node from p1
    } else {
        head = current->next;  // Moving the head
    }

    if (p2 == 0) {
        nodeToMove->next = head;
        return nodeToMove;  // New head
    }

    current = head;
    for (int i = 0; i < p2 - 1; i++) {
        current = current->next;
    }
    nodeToMove->next = current->next;
    current->next = nodeToMove;
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;  // New head
}

Node* cyclicLeft(Node* head, int x) {
    if (!head || !head->next || x <= 0) return head;
    
    Node* current = head;
    int length = 1;
    
    while (current->next) {
        current = current->next;
        length++;
    }
    current->next = head;  // Make it circular

    x %= length;  // In case x > length
    for (int i = 0; i < x; i++) {
        current = current->next;
    }
    
    head = current->next;
    current->next = nullptr;  // Break the cycle
    return head;
}

Node* cyclicRight(Node* head, int x) {
    if (!head || !head->next || x <= 0) return head;

    Node* current = head;
    int length = 1;

    while (current->next) {
        current = current->next;
        length++;
    }
    current->next = head;  // Make it circular

    x %= length;  // In case x > length
    for (int i = 0; i < length - x; i++) {
        current = current->next;
    }
    
    head = current->next;
    current->next = nullptr;  // Break the cycle
    return head;
}

int main() {
    Node* head = nullptr;
    int command;

    while (cin >> command) {
        if (command == 0) break;

        if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, x, p);
        } else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x;
            cin >> x;
            head = cyclicLeft(head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            head = cyclicRight(head, x);
        }
    }

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
//i copied it
    return 0;
}