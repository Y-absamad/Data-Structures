#include <iostream>
using namespace std;
class Array
{
private:
    int size;
    int length;
    int *items;

public:
    Array(int arrsize)
    {
        size = arrsize;
        length = 0;
        items = new int[arrsize];
    }
    void Fill()
    {
        int no_of_items;
        cout << "How many items you want to fill ? \n";
        cin >> no_of_items;
        if (no_of_items > size)
        {
            cerr << "You cannot exceed the array size\n";
            return;
        }
        else
        {
            for (int i = 0; i < no_of_items; i++)
            {
                cout << "Enter item no " << i + 1 << endl;
                cin >> items[i];
                length++;
            }
        }
    }
    void display()
    {
        cout << "Display Array content\n";
        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }
    int getSize()
    {
        return size;
    }
    int getLength()
    {
        return length;
    }
    int Search(int key)
    {
        int index = -1;
        for (int i = 0; i < length; i++)
        {
            if (key == items[i])
            {
                index = i;
                break;
            }
        }
        return index;
    }
    void Append(int newItem)
    {
        if (length < size)
        {
            items[length] = newItem;
            length++;
        }
        else
        {
            cerr << "Array is full\n";
        }
    }
    void Insert(int index, int newItem)
    {
        if (index >= 0 && index < size)
        {
            for (int i = length; i > index; i--)
            {
                items[i] = items[i - 1];
            }
            items[index] = newItem;
            length++;
        }
        else
            cout << "Index out of Rang\n";
    }
    void Delete(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < length - 1; i++)
            {
                items[i] = items[i + 1];
            }
            length--;
        }
        else
            cout << "index out of Rang\n";
    }
    void Enlarge(int newSize)
    {
        if (newSize <= size)
        {
            cout << "New size must be larger than current size\n";
            return;
        }
        else
        {
            size = newSize;
            int *oldArray = items;
            items = new int[newSize];
            for (int i = 0; i < length; i++)
            {
                items[i] = oldArray[i];
            }
            delete oldArray;
        }
    }
    void Merge(Array other)
    {
        int newSize = size + other.getSize();
        size = newSize;
        int *old = items;
        int i = 0;
        items = new int[newSize];
        for (i; i < length; i++)
        {
            items[i] = old[i];
        }
        delete[] old;
        int j = i;
        for (int i = 0; i < other.getLength(); i++)
        {
            items[j++] = other.items[i];
            length++;
        }
    }
};

int main()
{
    cout << "\t\t Hello this is Array\n";
    int arrsize;
    cout << "Enter the array size :";
    cin >> arrsize;
    Array myArray(arrsize);
    myArray.Fill();
    cout << "Array size = " << myArray.getSize() << "\t length = " << myArray.getLength() << endl;
    myArray.display();
    // int key;
    // cout << "Enter the value to search for: ";
    // cin >> key;
    // int index = myArray.Search(key);
    // if (index == -1)
    //     cout << "item not found\n";
    // else
    //     cout << "item found @ position " << index << endl;
    // int newItem;
    // cout << "Enter new item to add the array\n";
    // cin >> newItem;
    // myArray.Append(newItem);
    // myArray.display();
    //    cout << "Enter index to delete its item\n";
    //     int index;
    //     cin >> index;
    //     myArray.Delete(index);
    // cin >> newItem;
    // myArray.Insert(index, newItem);
    cout << "Array size = " << myArray.getSize() << "\t length = " << myArray.getLength() << endl;
    // myArray.display();

    // int newsize;
    // cout<<"Enter new size \n";
    // cin>>newsize;
    // myArray.Enlarge(newsize);
    Array other(3);
    other.Fill();
    myArray.Merge(other);
    cout << "Array size = " << myArray.getSize() << "\t length = " << myArray.getLength() << endl;
    myArray.display();
}