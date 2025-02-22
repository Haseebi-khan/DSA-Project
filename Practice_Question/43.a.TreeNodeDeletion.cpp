
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d = 0) : data(d), left(nullptr), right(nullptr) {}
};

Node *root = nullptr;

void insert(int value)
{
    Node *newNode = new Node(value);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node *temp = root;
    while (temp)
    {
        if (value < temp->data)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
        else if (value > temp->data)
        {
            if (temp->right == nullptr)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            cout << "Value is already available.";
            return;
        }
    }
}

void DeletionOfNodes(int value)
{
    if (!root)
    {
        return;
    }

    Node *parent = nullptr;
    Node *temp = root;
    bool found = false;

    while (temp && temp->data != value)
    {
        parent = temp;
        if (value < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (!temp)
    {
        cout << "Value is not Found.\n";
        return;
    }

    // case 1: Node with no children. leaf node
    if (!temp->left && !temp->right)
    {
        if (!root)
        {
            return;
        }
        else if (parent->left == temp)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }
        delete temp;
    }
    // case 2: Node with one child
    else if (!temp->left || !temp->right)
    {
        Node *child = nullptr;
        if (!temp->left)
        {
            child = temp->left;
        }
        else
        {
            child = temp->right;
        }

        if (temp == root)
        {
            root = child;
        }
        else if (parent->left == temp)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        delete temp;
    }
    // Case 3: Node with two children
    else
    {

        Node *successorParent = temp;
        Node *successor = temp->right;
        while (successor->left)
        {
            successorParent = successor;
            successor = successor->left;
        }
        temp->data = successor->data;
        if (successorParent->left = successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }
        delete successor;
    }
}

void preshow(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preshow(root->left);
    preshow(root->right);
}

int main()
{
    insert(30);
    insert(18);
    insert(45);
    insert(10);
    insert(42);
    insert(57);
    cout << "List: ";
    preshow(root);
    cout << "\n";

    DeletionOfNodes(10);
    DeletionOfNodes(30);
    DeletionOfNodes(57);
    DeletionOfNodes(45);

    cout << "List: ";
    preshow(root);
    cout << "\n";

    cout << "\n";
    return 0;
}
