#include <iostream>
#include <string>
using namespace std;

struct Node {
    string book_name;
    Node* next;
    Node* prev;
    
    Node(string name) : book_name(name), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add_front(const string& name) {
        Node* newNode = new Node(name);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok" << endl;
    }

    void add_back(const string& name) {
        Node* newNode = new Node(name);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok" << endl;
    }

    void erase_front() {
        if (!head) {
            cout << "error" << endl;
            return;
        }
        cout << head->book_name << endl;
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr; 
        }
        delete temp;
    }

    void erase_back() {
        if (!tail) {
            cout << "error" << endl;
            return;
        }
        cout << tail->book_name << endl;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr; 
        }
        delete temp;
    }

    void front() {
        if (!head) {
            cout << "error" << endl;
            return;
        }
        cout << head->book_name << endl;
    }

    void back() {
        if (!tail) {
            cout << "error" << endl;
            return;
        }
        cout << tail->book_name << endl;
    }

    void clear() {
        while (head) {
            erase_front();
        }
        cout << "ok" << endl;
    }

    ~DoublyLinkedList() {
        clear();
    }
};

int main() {
    DoublyLinkedList list;
    string command;

    while (true) {
        cin >> command;
        if (command == "add_front") {
            string name;
            cin >> name;
            list.add_front(name);
        } else if (command == "add_back") {
            string name;
            cin >> name;
            list.add_back(name);
        } else if (command == "erase_front") {
            list.erase_front();
        } else if (command == "erase_back") {
            list.erase_back();
        } else if (command == "front") {
            list.front();
        } else if (command == "back") {
            list.back();
        } else if (command == "clear") {
            list.clear();
        } else if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }

    return 0;
}
