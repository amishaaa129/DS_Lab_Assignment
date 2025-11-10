#include <iostream>
#include <climits>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int val){return new Node{val,nullptr,nullptr};}
bool isBST(Node* root,int minv,int maxv){
    if(!root) return true;
    if(root->data<=minv||root->data>=maxv) return false;
    return isBST(root->left,minv,root->data)&&isBST(root->right,root->data,maxv);
}
int main(){
    Node* root=newNode(10);
    root->left=newNode(5);
    root->right=newNode(15);
    root->left->left=newNode(2);
    root->left->right=newNode(8);
    cout<<(isBST(root,INT_MIN,INT_MAX)?"BST":"Not BST");
}
