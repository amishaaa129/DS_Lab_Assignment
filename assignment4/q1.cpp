#include <iostream>
using namespace std;
#define MAX 100

int q[MAX];
int front = -1;
int rear = -1;
int n = MAX;

bool isempty()
{
    if (front == -1)
        return true;
}
bool isfull()
{
    if (rear == n - 1)
    {
        return true;
    }
}
void enqueue(int value)
{
    if (isfull())
    {
        cout << "queue overflow";
    }
    if (front == -1) {      
        front = 0;
        rear  = 0;
    } else {
        rear = rear + 1;    
    }
    q[rear] = value;
}
void dequeue()
{
    if (isempty())
    {
        cout << "queue underflow";
    }
    cout << q[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
        front++;
}

void peek()
{
    if (isempty())
    {
        cout << "queue underflow";
    }
    else
        cout << q[front];
}

void display()
{
    if (isempty())
    {
        cout << "queue underflow";
    }
    else
    {

        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << " ";
        }
    }
}
int choice = 0, val;
int main()
{
    while (choice != 5)
    {

        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting";
            break;
        default:
            cout << "Invalid choice!";
        }
    }
}