#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    int getFront()
    {
        return front->data;
    }
    int getRear()
    {
        return rear->data;
    }
    void enQueue(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << "\t";
                temp = temp->next;
            }
        }
        cout << endl;
    }
    int Dequeue()
    {
        int value = front->data;
        Node *delPtr = front;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
        delete delPtr;
        return value;
    }
    int count()
    {
        int counter = 0;
        Node *temp = front;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    bool isFound(int item)
    {
        bool found = false;
        Node *temp = front;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
    void Clear()
    {
        while(!isEmpty())  // front != NULL
        {
            Dequeue();
        }
    }
};
int main()
{
    Queue q;
    int item;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter item to  Enqueue\n";
        cin >> item;
        q.enQueue(item);
    }
    q.display();

    if (q.isEmpty())
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        cout << "done EnQueue: " << q.Dequeue() << "\n";
        cout << "Queue after enqueue\n";
        q.display();
    }

    cout << "Enter item for search\n";
    cin >> item;
    cout << (q.isFound(item) ? "item found\n" : "item not found\n");

    cout << "counter of Queue = " << q.count() << endl;

    cout<<"Clear All items\n";
    q.Clear();

    cout<<"Display after clear --> ";
    q.display();



}