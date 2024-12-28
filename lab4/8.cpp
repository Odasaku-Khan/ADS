#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;
    int sum;

    BinarySearchTree() : root(nullptr), sum(0) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }
        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else {
            root->right = insertRec(root->right, key);
        }
        return root;
    }

    void newValuesForTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        newValuesForTree(node->right);
        sum += node->key;
        node->key = sum;
        newValuesForTree(node->left);
    }

    void printValues(Node* node) {
        if (node == nullptr) {
            return;
        }
        printValues(node->right);
        cout << node->key << " ";
        printValues(node->left);
    }
};

int main() {
    BinarySearchTree tree;
    int size;
    string line;

    getline(cin, line);
    stringstream ss(line);
    ss >> size;

    getline(cin, line);
    ss.clear();
    ss.str(line);
    vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        ss >> array[i];
    }

    for (int i : array) {
        tree.insert(i);
    }

    tree.newValuesForTree(tree.root);
    tree.printValues(tree.root);
    cout << endl;

    return 0;
}