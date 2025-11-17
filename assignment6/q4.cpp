#include <iostream>
#include <string>
using namespace std;
struct Node {
    char data;
    Node* next;
    Node* prev;
};
bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* end=head;
    while (end->next) end=end->next;
    while (head && end && head!=end && end->next!=head) {
        if (head->data!=end->data) return false;
        head=head->next;
        end=end->prev;
    }
    return true;
}
int main() {
    string s;
    cin>>s;
    if (s.empty()) return 0;
    Node* head=new Node{s[0],nullptr,nullptr};
    Node* temp=head;
    for (int i=1;i<s.size();i++) {
        Node* n=new Node{s[i],nullptr,temp};
        temp->next=n;
        temp=n;
    }
    cout<<(isPalindrome(head)?"Palindrome":"Not Palindrome");
}
