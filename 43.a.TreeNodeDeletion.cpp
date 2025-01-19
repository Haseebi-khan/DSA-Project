
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

    Node *temp = root;
    bool found = false;
    while (temp)
    {
        if (value == temp->data)
        {
            if (!temp->left  && !temp->right )
            {
                delete temp;
                temp = nullptr;
                return;
            }
            
        }
        else if (value < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (!found)
    {
        cout << "Value is not Found.\n";
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

    cout << "List: ";
    preshow(root);
    cout << "\n";

    cout << "\n";
    return 0;
}
