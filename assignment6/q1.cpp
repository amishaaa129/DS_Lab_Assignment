#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() { head = NULL; }
    void insertFirst(int val) {
        Node* n = new Node{val};
        if (!head) {
            head = n;
            n->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            n->next = head;
            temp->next = n;
            head = n;
        }
    }
    void insertLast(int val) {
        Node* n = new Node{val};
        if (!head) {
            head = n;
            n->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = n;
            n->next = head;
        }
    }
    void insertAfter(int key, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* n = new Node{val};
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        Node *temp = head, *prev = NULL;
        do {
            if (temp->data == key) {
                Node* n = new Node{val};
                if (temp == head) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    n->next = head;
                    last->next = n;
                    head = n;
                } else {
                    n->next = temp;
                    prev->next = n;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }
    void deleteNode(int key) {
        if (!head) return;
        Node *temp = head, *prev = NULL;
        if (temp->data == key && temp->next == head) {
            delete temp;
            head = NULL;
            return;
        }
        while (temp->next != head && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data != key) return;
        if (temp == head) {
            Node* last = head;
            while (last->next != head) last = last->next;
            head = head->next;
            last->next = head;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }
    bool search(int key) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    void display() {
        if (!head) {
            cout << "Empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = NULL; }
    void insertFirst(int val) {
        Node* n = new Node{val, head, NULL};
        if (head) head->prev = n;
        head = n;
    }
    void insertLast(int val) {
        Node* n = new Node{val, NULL, NULL};
        if (!head) head = n;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* n = new Node{val, temp->next, temp};
        if (temp->next) temp->next->prev = n;
        temp->next = n;
    }
    void insertBefore(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* n = new Node{val, temp, temp->prev};
        if (temp->prev) temp->prev->next = n;
        else head = n;
        temp->prev = n;
    }
    void deleteNode(int key) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }
    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "Empty\n";
            return;
        }
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    CircularLinkedList cl;
    DoublyLinkedList dl;
    int choice, listType, val, key;
    while (true) {
        cout << "1. Circular List\n2. Doubly List\n3. Exit\n";
        cin >> listType;
        if (listType == 3) break;
        cout << "1.Insert First 2.Insert Last 3.Insert After 4.Insert Before 5.Delete 6.Search 7.Display 8.Back\n";
        while (true) {
            cin >> choice;
            if (choice == 8) break;
            switch (choice) {
                case 1: cin >> val;
                        if (listType == 1) cl.insertFirst(val); else dl.insertFirst(val); break;
                case 2: cin >> val;
                        if (listType == 1) cl.insertLast(val); else dl.insertLast(val); break;
                case 3: cin >> key >> val;
                        if (listType == 1) cl.insertAfter(key,val); else dl.insertAfter(key,val); break;
                case 4: cin >> key >> val;
                        if (listType == 1) cl.insertBefore(key,val); else dl.insertBefore(key,val); break;
                case 5: cin >> key;
                        if (listType == 1) cl.deleteNode(key); else dl.deleteNode(key); break;
                case 6: cin >> key;
                        cout << ((listType == 1 ? cl.search(key): dl.search(key)) ? "Found\n" : "Not Found\n"); break;
                case 7: if (listType == 1) cl.display(); else dl.display(); break;
            }
        }
    }
    return 0;
}
