#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
    string sname;
    Node* next;
    Node(string n) : sname(n), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        string sname;
        cin >> sname;

        Node* newNode = new Node(sname);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->sname == current->next->sname) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    int count = 0;
    current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    cout << "All in all: " << count << endl;

    stack<string> namesStack;
    current = head;
    while (current != nullptr) {
        namesStack.push(current->sname);
        current = current->next;
    }

    cout << "Students:\n";
    while (!namesStack.empty()) {
        cout << namesStack.top() << endl;
        namesStack.pop();
    }

    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}