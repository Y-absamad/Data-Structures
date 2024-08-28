#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Linkedlist
{
public:
    Node *head;
    Linkedlist()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    void InsertFirst(int newValue)
    {
        Node *newNode = new Node;
        newNode->data = newValue;
        if (isEmpty())
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void Display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
    int count()
    {
        int counter = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    bool isFound(int key)
    {
        bool found = false;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        return found;
    }
    void inserdBefore(int item, int newVlaue)
    {
        if (isFound(item))
        {
            Node *newNode = new Node;
            newNode->data = newVlaue;
            Node *temp = head;
            while (temp != NULL && temp->next->data != item)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Sorry , item not found\n";
        }
    }
    void Append(int newVlaue)
    {
        if (isEmpty())
            InsertFirst(newVlaue);
        else
        {
            Node *newNode = new Node;
            newNode->data = newVlaue;
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
    }
    void Delete(int item)
    {
        if (isEmpty() || !isFound(item))
        {
            cout << "No item to delete\n";
            return;
        }

        Node *delPtr = head;
        Node *prev = NULL;
        if (head->data == item)
        {
            head = head->next;
            delete delPtr;
        }
        else
        {
            while (delPtr->data != item)
            {
                prev = delPtr;
                delPtr = delPtr->next;
            }
            prev->next = delPtr->next;
            delete delPtr;
        }
    }
   


};
int main()
{
    Linkedlist list;

    if (list.isEmpty())
        cout << "The list is empty\n";
    else
        cout << "The List contains " << list.count() << "\n";

    int no_of_items;
    cout << "How many items you want to fill ? ";
    cin >> no_of_items;

    int item;
    for (int i = 1; i <= no_of_items; i++)
    {
        cout << "\nEnter to inser: ";
        cin >> item;
        list.InsertFirst(item);
    }
    list.Display();

    cout << "\nThe List contains " << list.count() << "\n";

    cout << "Enter item to search for: ";
    cin >> item;

    if (list.isFound(item))
        cout << "Item is found\n";
    else
        cout << "Item is not found\n";

    int newVlaue;
    cout << "Enter item and new value to insert\n";
    cin >> item;
    cin >> newVlaue;
    list.inserdBefore(item, newVlaue);
    list.Display();

    cout << "\nEnter new value to append\n";
    cin >> newVlaue;
    list.Append(newVlaue);
    list.Display();


    cout << "\nEnter value to delete\n";
    cin >> item;
    list.Delete(item);
    list.Display();


}