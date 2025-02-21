// Implement queue as linked list.

#include <iostream>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;

        Node(int data) 
        {
            val = data;
            next = NULL;
        }
};

class Queue 
{
    private:
        Node* front;
        Node* rear;

    public:
        Queue() 
        {
            front = NULL;
            rear = NULL;
        }

    void enqueue(int val)
    {
        Node* newNode = new Node(val);
        if (rear == NULL) 
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() 
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        if (front == NULL) 
        {
            rear = NULL;
        }
        delete temp;
    }

    void peek()
    {
        if (front == NULL) 
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Top element is " << front->val << endl;
        }
    }

    void isEmpty() 
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue is not empty" << endl;
        }
    }

    void display() 
    {
        if (front == NULL) 
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        while (temp != NULL) 
        {
            cout << "<-" << temp->val;
            temp = temp->next;
            //if (temp != NULL) cout << "->";  // Add "->" only between elements
        }
        //cout << endl;
    }
};

int main() 
{
    Queue q;
    int choice, value;

    while (true) 
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.isEmpty();
                break;

            case 5:
                q.display();
                break;

            case 6:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
