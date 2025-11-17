#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void display(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data;
}
int main() {
    Node* head = new Node{20};
    Node* n1 = new Node{100};
    Node* n2 = new Node{40};
    Node* n3 = new Node{80};
    Node* n4 = new Node{60};
    head->next = n1; n1->next = n2; n2->next = n3; n3->next = n4; n4->next = head;
    display(head);
    return 0;
}
