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
class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    bool isFull()
    {
        Node *ptr = new Node;
        return (ptr == NULL);
    }
    void push(int item)
    {
        Node *newNode = new Node;
        newNode->data = item;
        if (isEmpty())
        {
            top = newNode;
            // newNode->next = NULL;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    int pop()
    {
        int value;
        value = top->data;
        Node *delPtr = top;
        top = top->next;
        delete delPtr;
        return value;
    }
    int Peek()
    {
        return top->data;
    }
    int count()
    {
        int counter = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        cout << "\n";
        return counter;
    }
    bool isFound(int item)
    {
        bool found = false;
        Node *temp = top;
        while (temp != NULL)
        {
            if (item == temp->data)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
    void Display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main()
{

    Stack s;
    int item;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter item to push\n";
        cin >> item;
        s.push(item);
    }
    s.Display();

    cout << s.pop() << " Was deleted from stack\n";
    s.Display();

    cout << "Peek is " << s.Peek() << "\n"; // dont forget check isEmpty

    cout << "Enter item to search for :";
    cin >> item;
    cout << (s.isFound(item) ? "Item is found\n" : "item not found\n");

    cout << "conter in stack: " << s.count() << "\n";
}