#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};
int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* current = head;
    Node* prev = nullptr;
    int count = 0;
    while (current != nullptr) {
        count++;
        if (count % 2 == 0) {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
            continue;
        }
        prev = current;
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}