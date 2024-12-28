#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    char command;
    
    while (cin >> command) {
        if (command == '+') {
            int num;
            cin >> num;
            dq.push_front(num);
        } 
        else if (command == '-') {
            int num;
            cin >> num;
            dq.push_back(num);
        } 
        else if (command == '*') {
            if (dq.size() >= 2) {
                int sum = dq.front() + dq.back();
                cout << sum << endl;
                dq.pop_front();
                dq.pop_back();
            } 
            else if (dq.size() == 1) {
                cout << dq.front() + dq.front() << endl;  // Sum of the single element twice
                dq.pop_front();  // Remove the only element
            } 
            else {
                cout << "error" << endl;
            }
        } 
        else if (command == '!') {
            break;
        }
    }

    return 0;
}
