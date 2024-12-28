#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

Node* insert(Node* head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int findMaxSum(Node* head) {
    if (!head) return 0;

    int maxSum = head->value;
    int currentSum = 0;
    Node* temp = head;

    while (temp) {
        currentSum += temp->value;
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
        temp = temp->next;
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        head = insert(head, value);
    }
    cout << findMaxSum(head) << endl;
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}