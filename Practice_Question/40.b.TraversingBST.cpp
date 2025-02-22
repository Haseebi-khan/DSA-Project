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

void insertNode(int value)
{
    Node *newNode = new Node(value);
    if (!root)
    {
        root = newNode;
        return;
    }

    Node *temp = root;
    while (temp)
    {
        if (value > temp->data)
        {
            if (!temp->right)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        else if (value < temp->data)
        {
            if (!temp->left)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            cout << "Node is Allready exist.\n";
        }
    }
}

void show(Node *root)
{
    if (!root)
    {
        return;
    }
    show(root->left);
    cout << root->data << " ";
    show(root->right);
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
void postshow(Node *root)
{
    if (!root)
    {
        return;
    }
    postshow(root->left);
    postshow(root->right);
    cout << root->data << " ";
}

void maxNode()
{
    if (!root)
    {
        cout << "Empty.\n";
        return;
    }
    Node *temp = root;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    cout << "\nMax is: " << temp->data << endl;
}

void minNode()
{
    if (!root)
    {
        cout << "Empty.\n";
        return;
    }
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    cout << "\nMin is: " << temp->data << endl;
}

int main()
{
    insertNode(10);
    insertNode(8);
    insertNode(11);
    insertNode(2);
    insertNode(14);
    insertNode(1);
    insertNode(6);
    insertNode(13);
    insertNode(16);
    
    cout << "\nInOrder Tree:";
    show(root);
    cout << endl;
    
    cout << "PreOrder Tree:";
    preshow(root);

    cout << "\nPostOrder Tree:";
    postshow(root);
    
    maxNode();
    minNode();

    


    cout << endl;
    return 0;
}
