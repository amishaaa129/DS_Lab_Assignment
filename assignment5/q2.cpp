#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head=nullptr;

void insertAtEnd(int value){
    Node* newNode=new Node{value,nullptr};
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
}

int deleteAllOccurrences(int key){
    int count=0;
    while(head!=nullptr && head->data==key){
        Node* temp=head;
        head=head->next;
        delete(temp);
        count++;
    }

    Node* curr=head;
    Node* prev=nullptr;
    while(curr!=nullptr){
        if(curr->data==key){
            Node* temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            delete(temp);
            count++;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return count;
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << "\n";
}
int main() {
    int n;
    cout<<"number of nodes\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter element\n";
        cin>>arr[i];
        insertAtEnd(arr[i]);
    }

    cout << "Original Linked List: ";
    displayList();

    int key = 1;
    int count = deleteAllOccurrences(key);

    cout << "Count: " << count << "\n";
    cout << "Updated Linked List: ";
    displayList();

    return 0;
}
