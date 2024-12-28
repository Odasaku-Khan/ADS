#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int newData;
    cin >> newData;
    int position;
    cin >> position;

    Node* newNode = new Node(newData);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    printList(head);
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}