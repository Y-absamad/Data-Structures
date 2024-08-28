#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
    // Node(int value) : data(value), left(NULL), right(NULL) {}
};
class BST
{
private:
    Node *root;

    Node *Insert(Node *roo, int item)
    {
        if (roo == NULL)
        {
            Node *newnode = new Node(item);
            roo = newnode;
            // return new Node(item);
        }
        else if (item < roo->data)
            roo->left = Insert(roo->left, item);
        else
            roo->right = Insert(roo->right, item);

        return roo;
    }
    void PreOrder(Node *temp) // root -> left -> right
    {
        if (temp == NULL)
            return;
        cout << temp->data << "\t";
        PreOrder(temp->left);
        PreOrder(temp->right);
    }
    void inOrder(Node *temp) // left -> root -> right
    {
        if (temp == NULL)
            return;
        inOrder(temp->left);
        cout << temp->data << "\t";
        inOrder(temp->right);
    }
    void postOrder(Node *temp) // left -> right -> root
    {
        if (temp == NULL)
            return;
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data << "\t";
    }
    Node *search(Node *temp, int key)
    {
        if (temp == NULL)
            return NULL;
        else if (key == temp->data)
            return temp;
        else if (key < temp->data)
            return search(temp->left, key);
        else
            return search(temp->right, key);
    }
    Node *Delete(Node *temp, int key)
    {
        if (temp == NULL)
            return NULL;
        else if (key < temp->data)
            temp->left = Delete(temp->left, key);
        else if (key > temp->data)
            temp->right = Delete(temp->right, key);
        else
        {
            if (temp->left == NULL && temp->right == NULL) // leaf node
            {
                delete temp;
                temp = NULL;
            }
            else if (temp->left != NULL && temp->right == NULL) // one child on the left
            {
                temp->data = temp->left->data;
                delete temp->left;
                temp->left = NULL;
            }
            else if (temp->left == NULL && temp->right != NULL) // one child on the right
            {
                temp->data = temp->right->data;
                delete temp->right;
                temp->right = NULL;
            }
            else // node has two childern
            {
                // max number on the left
                Node *max = findMax(temp->left);
                temp->data = max->data;
                temp->left = Delete(temp->left, max->data);

                // min number on the right
                /*
                Node *min = findMin(temp->right);
                temp->data = min->data;
                temp->right = Delete(temp->right, min->data);
                */
            }
        }
        return temp;
    }

public:
    BST()
    {
        root = NULL;
    }
    Node *gitRoot()
    {
        return root;
    }
    void Insert(int item)
    {
        root = Insert(root, item);
    }
    void add(int item) // iterative method
    {
        Node *newnode = new Node(item);
        if (root == NULL)
        {
            root = newnode;
            return;
        }
        Node *temp = root;
        Node *parent = NULL;
        while (temp != NULL)
        {
            parent = temp;
            if (item <= temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (item <= parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }
    void displayPreOrder()
    {
        cout << "\nPre Order traversal \n";
        PreOrder(root);
    }
    void displayInOrder()
    {
        cout << "\nIn Order traversal \n";
        inOrder(root);
    }
    void displayPostOrder()
    {
        cout << "\nPost Order traversal \n";
        postOrder(root);
    }
    bool search(int key)
    {
        Node *result = search(root, key);
        return (result == NULL ? false : true);
    }
    Node *findMin(Node *temp)
    {
        if (temp == NULL)
            return NULL;
        else if (temp->left == NULL)
            return temp;
        else
            return findMin(temp->left);
    }
    Node *findMinByIterative(Node *temp)
    {
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    Node *findMax(Node *temp)
    {
        if (temp == NULL)
            return NULL;
        else if (temp->right == NULL)
            return temp;
        else
            return findMax(temp->right);
    }
    Node *findMaxByIterative(Node *temp)
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }
    void Delete(int key)
    {
        root = Delete(root, key);
    }
};
int main()
{
    BST tree;
    tree.Insert(45);
    tree.Insert(20);
    tree.Insert(79);
    tree.Insert(90);
    tree.Insert(120);
    tree.Insert(75);
    tree.Insert(73);
    tree.Insert(74);
    tree.Insert(10);
    tree.Insert(15);
    tree.Insert(7);
    tree.Insert(70);
    tree.Insert(27);
    tree.Insert(30);
    tree.Insert(35);
    tree.Insert(32);





    
    tree.displayPreOrder();
    //tree.displayInOrder();
    //tree.displayPostOrder();
    
    // cout << tree.search(22); // 0
    //Node *min = tree.findMin(tree.gitRoot());
    //Node *max = tree.findMaxByIterative(tree.gitRoot());
    // Node *min = tree.findMinByIterative(tree.root);

    //cout << max->data;
    tree.Delete(79);
    tree.displayPreOrder();
    // tree.Delete(15);
    // tree.displayPreOrder();
    return 0;
}
/*
        45
     /     \
   15       79
  / \      /  \
10   16   55  90

         20
       /    \
     10      30
    /  \    /  \
   5   15  25  35

*/
