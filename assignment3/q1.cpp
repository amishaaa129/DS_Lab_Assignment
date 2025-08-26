#include <iostream>
using namespace std;

#define SIZE 5  
class Stack {
private:
    int arr[SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == SIZE - 1;
    }
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n=== Stack Operations Menu ===\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Peek\n6. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 4:
            cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 5:
            s.peek();
            break;
        case 6:
            s.display();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
