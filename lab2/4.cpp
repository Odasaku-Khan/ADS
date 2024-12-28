#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    int frequency;
    Node* next;

    Node(int val) : value(val), frequency(1), next(nullptr) {}
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    Node* head = nullptr;
    unordered_map<int, Node*> frequencyMap;
    for (int num : nums) {
        if (frequencyMap.find(num) != frequencyMap.end()) {
            frequencyMap[num]->frequency++;
        } else {
            Node* newNode = new Node(num);
            newNode->next = head;
            head = newNode;
            frequencyMap[num] = newNode;
        }
    }

    int maxFreq = 0;
    vector<int> modes;

    Node* current = head;
    while (current != nullptr) {
        if (current->frequency > maxFreq) {
            maxFreq = current->frequency;
            modes.clear();
            modes.push_back(current->value);
        } else if (current->frequency == maxFreq) {
            modes.push_back(current->value);
        }
        current = current->next;
    }
    sort(modes.begin(), modes.end(), greater<int>());
    for (int mode : modes) {
        cout << mode << " ";
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