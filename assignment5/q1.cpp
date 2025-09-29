#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertAtEnd(int value) {
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

void insertBeforeAfter(int key, int value, bool before) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (before && head->data == key) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with value " << key << " not found.\n";
        return;
    }

    Node* newNode = new Node{value, nullptr};

    if (before) {
        prev->next = newNode;
        newNode->next = temp;
    } else { 
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteSpecific(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Node with value " << key << " not found.\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void searchNode(int key) {
    Node* temp=head;
    int pos=1;
    if(head==nullptr){
        cout<<"empty list\n";
        return;
    }
    while(temp!=nullptr && temp->data!=key){
        temp=temp->next;
        pos++;
    }
    if(temp==nullptr)
        cout<<"not found\n";
    else
        cout<<"element found at "<<pos<<endl;
    
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, key;
    bool beforeAfter;

    do {
        cout << "\n--- Singly Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter key (existing node value): ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertBeforeAfter(key, value, true);
                break;
            case 4:
                cout << "Enter key (existing node value): ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> value;
                insertBeforeAfter(key, value, false);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter node value to delete: ";
                cin >> key;
                deleteSpecific(key);
                break;
            case 8:
                cout << "Enter node value to search: ";
                cin >> key;
                searchNode(key);
                break;
            case 9:
                displayList();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
