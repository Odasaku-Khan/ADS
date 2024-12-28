#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
struct Node {
    string word;
    Node* next;
    Node(string w) : word(w), next(nullptr) {}
};

int main() {
    int n, m;
    cin >> n >> m;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        Node* newNode = new Node(word);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    m = m % n;

    if (m == 0) {
        Node* temp = head;
        while (temp) {
            cout << temp->word << " ";
            temp = temp->next;
        }
        cout << endl;
        return 0;
    }

    Node* prev = nullptr;
    Node* current = head;
    for (int i = 0; i < m; i++) {
        prev = current;
        current = current->next;
    }

    prev->next = nullptr;

    tail->next = head;

    head = current;

    Node* temp = head;
    while (temp) {
        cout << temp->word << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}