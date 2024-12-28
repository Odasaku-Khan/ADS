#include <bits/stdc++.h> 
using namespace std; 
 
struct Node { 
    int key; 
    Node* left; 
    Node* right; 
   
    Node(int item) { 
        key = item; 
        left = right = nullptr; 
    } 
}; 
 
Node* insert(Node* node,int key){ 
    if(node==nullptr){ 
        return new Node(key); 
    } 
    else if(node->key>key){ 
        node->left=insert(node->left,key); 
    } 
    else  if (node->key<key){ 
        node->right=insert(node->right,key); 
    } 
    return node; 
} 
int size(Node* root){ 
    if(root==nullptr){ 
        return 0; 
    } 
    else{ 
        return 1+size(root->left)+size(root->right); 
    } 
 
} 
Node* find(Node* root,int key){ 
    if(root==nullptr||root->key==key){ 
        return root; 
    } 
    if(root->key>key){ 
        return find(root->left,key); 
    } 
    return find(root->right,key); 
}; 
int main(){ 
    Node* root=nullptr; 
    int n,k; 
    cin>>n; 
    vector<int>sandar(n); 
    vector<string>sozder(k); 
    for(int i=0;i<n;i++){ 
        cin>>sandar[i]; 
       root= insert( root,sandar[i]); 
    } 
    cin>>k; 
    Node* target=find(root,k); 
 
    if(target!=nullptr){ 
        cout<<size(target); 
    } 
    else{ 
        cout<<0; 
    } 
    return 0; 
     
 
   
}