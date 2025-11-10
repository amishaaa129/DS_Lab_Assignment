#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* insert(Node* root,int val) {
    if(!root) {
        Node* n=new Node{val,nullptr,nullptr};
        return n;
    }
    if(val<root->data) root->left=insert(root->left,val);
    else if(val>root->data) root->right=insert(root->right,val);
    return root;
}
Node* searchRec(Node* root,int key) {
    if(!root||root->data==key) return root;
    if(key<root->data) return searchRec(root->left,key);
    return searchRec(root->right,key);
}
Node* searchNonRec(Node* root,int key) {
    while(root) {
        if(root->data==key) return root;
        else if(key<root->data) root=root->left;
        else root=root->right;
    }
    return nullptr;
}
Node* findMin(Node* root) {
    while(root && root->left) root=root->left;
    return root;
}
Node* findMax(Node* root) {
    while(root && root->right) root=root->right;
    return root;
}
Node* inorderSuccessor(Node* root,Node* x) {
    if(x->right) return findMin(x->right);
    Node* succ=nullptr;
    while(root) {
        if(x->data<root->data){succ=root;root=root->left;}
        else if(x->data>root->data) root=root->right;
        else break;
    }
    return succ;
}
Node* inorderPredecessor(Node* root,Node* x) {
    if(x->left) return findMax(x->left);
    Node* pred=nullptr;
    while(root) {
        if(x->data>root->data){pred=root;root=root->right;}
        else if(x->data<root->data) root=root->left;
        else break;
    }
    return pred;
}
int main() {
    Node* root=nullptr;
    int arr[]={50,30,70,20,40,60,80};
    for(int x:arr) root=insert(root,x);
    int key; cin>>key;
    Node* node=searchRec(root,key);
    cout<<(node?"Found Rec":"Not Found Rec")<<endl;
    node=searchNonRec(root,key);
    cout<<(node?"Found NonRec":"Not Found NonRec")<<endl;
    cout<<"Max: "<<findMax(root)->data<<endl;
    cout<<"Min: "<<findMin(root)->data<<endl;
    Node* xptr=searchRec(root,40);
    cout<<"Successor: "<<(inorderSuccessor(root,xptr)?inorderSuccessor(root,xptr)->data:-1)<<endl;
    cout<<"Predecessor: "<<(inorderPredecessor(root,xptr)?inorderPredecessor(root,xptr)->data:-1)<<endl;
}
