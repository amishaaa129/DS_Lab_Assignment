#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int findMiddle() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         
        fast = fast->next->next;   
    }
    return slow->data;
}

void displayList() {
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
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtEnd(val);
    }
    cout << "Linked List: ";
    displayList();

    int middle = findMiddle();
    if (middle != -1) {
        cout << "Middle element: " << middle << "\n";
    }
    return 0;
}
