#include <iostream>

using namespace std;


struct Node {
    int key;
    Node* left;
    Node* right;

    Node (int key) {
        this->key = key;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    static Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key){
            node->right = insert(node->right, key);
        }
        return node;
    } 

    void insert(int key) {
        root = insert(root, key);
    }

    static Node* search(Node* node, int key) {
        if (node == nullptr)
            return nullptr;
        if (key < node->key)
            return search(node->left, key);
        else if (key > node->key)
            return search(node->right, key);
        return node;
    }

    Node* search(int key) {
        return search(root, key);
    }

    static int getTrianglesCount(Node* node) {
        if (node == nullptr)
            return 0;
        return getTrianglesCount(node->left) + getTrianglesCount(node->right) + (node->left && node->right);
    }

    int getTrianglesCount() {
        return getTrianglesCount(root);
    }
};


int main() {
    int n;
    cin >> n;
    BST tree;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        tree.insert(temp);
    }
    
    cout << tree.getTrianglesCount();

    return 0;
}