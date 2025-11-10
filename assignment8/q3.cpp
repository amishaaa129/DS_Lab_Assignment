#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* insert(Node* root,int val) {
    if(!root) return new Node{val,nullptr,nullptr};
    if(val<root->data) root->left=insert(root->left,val);
    else if(val>root->data) root->right=insert(root->right,val);
    return root;
}
Node* findMin(Node* root) {
    while(root->left) root=root->left;
    return root;
}
Node* deleteNode(Node* root,int key) {
    if(!root) return root;
    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right=deleteNode(root->right,key);
    else {
        if(!root->left) {Node* t=root->right; delete root; return t;}
        else if(!root->right){Node* t=root->left; delete root; return t;}
        Node* t=findMin(root->right);
        root->data=t->data;
        root->right=deleteNode(root->right,t->data);
    }
    return root;
}
int maxDepth(Node* root) {
    if(!root) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}
int minDepth(Node* root) {
    if(!root) return 0;
    if(!root->left&&!root->right) return 1;
    if(!root->left) return 1+minDepth(root->right);
    if(!root->right) return 1+minDepth(root->left);
    return 1+min(minDepth(root->left),minDepth(root->right));
}
int main() {
    Node* root=nullptr;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){cin>>x; root=insert(root,x);}
    int del; cin>>del;
    root=deleteNode(root,del);
    cout<<"Max Depth: "<<maxDepth(root)<<endl;
    cout<<"Min Depth: "<<minDepth(root);
}
