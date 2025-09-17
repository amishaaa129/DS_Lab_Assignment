#include <iostream>
using namespace std;

#define MAX 5
int cq[MAX];
int front = -1, rear = -1;

bool isEmpty()
{
    return (front == -1);
}
bool isfull()
{
    return (front == (rear + 1) % MAX);
}
void enqueue(int value)
{
    if (isfull())
    {
        cout << "queue overflow";
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = value;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Circular Queue Underflow!";
        return;
    }
    cout << cq[front] << " dequeued";
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void peek()
{
    if (isEmpty())
        cout << "Queue empty";
    else
        cout << "Front element: " << cq[front];
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue empty";
        return;
    }
    cout << "Queue: ";
    int i = front;
    while (true)
    {
        cout << cq[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << "\n";
}

int main()
{
    int choice=0, val;
    while (choice != 5)
    {

        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
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
            cout << "Exiting...\n";
            break;
        }
    }
}