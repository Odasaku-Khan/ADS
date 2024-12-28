#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class A {
public:
    struct TreeNode {
        TreeNode* right;
        TreeNode* left;
        int data;
        TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    A() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    string solve(const string& path) {
        TreeNode* current = root;
        for (char dir : path) {
            if (dir == 'L') {
                if (current->left == nullptr) {
                    return "NO";
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    return "NO";
                } else {
                    current = current->right;
                }
            }
        }
        return "YES";
    }
};

int main() {
    A bst;
    int n, m;
    string line;

    getline(cin, line);
    stringstream ss(line);
    ss >> n >> m;

    getline(cin, line);
    ss.clear();
    ss.str(line);
    for (int i = 0; i < n; i++) {
        int val;
        ss >> val;
        bst.insert(val);
    }

    for (int i = 0; i < m; i++) {
        string path;
        getline(cin, path);
        cout << bst.solve(path) << endl;
    }

    return 0;
}