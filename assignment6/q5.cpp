#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp=head->next;
    while (temp && temp!=head) temp=temp->next;
    return temp==head;
}
int main() {
    int n,x;
    cin>>n;
    if(n<=0) return 0;
    Node* head=new Node;
    cin>>x;
    head->data=x;
    Node* temp=head;
    for(int i=1;i<n;i++){
        cin>>x;
        Node* t=new Node{x,nullptr};
        temp->next=t;
        temp=t;
    }
    int makeCircular;
    cin>>makeCircular;
    if(makeCircular==1) temp->next=head;
    cout<<(isCircular(head)?"Circular":"Not Circular");
}
