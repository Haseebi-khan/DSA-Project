#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d = 0) : left(nullptr), right(nullptr), data(d) {}
};

Node *root = nullptr;

void insertion(int value)
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
        if (value > temp->data)
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
        else if (value < temp->data)
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
        else
        {
            cout << "New Node Already Atteched.\n";
            return;
        }
    }
}

void printInorder(Node *root)
{
    if (root == NULL)
        return;
    Node *temp = root;

    printInorder(temp->left);

    cout << temp->data << " ";

    printInorder(temp->right);
}

void printPpstorder(Node *root)
{
    if (root == NULL)
        return;
    Node *temp = root;
    cout << temp->data << " ";

    printInorder(temp->left);
    printInorder(temp->right);
}

void search(int value)
{
    bool found = false;
    Node *temp = root;

    while (temp)
    {
        if (temp->data == value)
        {
            found = true;
            break;
        }
        else if (temp->data > value)
        {
            temp = temp->left;
        }
        else if (temp->data < value)
        {
            temp = temp->right;
        }
    }

    if (found)
    {
        cout << "\nData found: " << temp->data << endl;
    }
    else
    {
        cout << "Not found.\n";
    }
}
void findMax()
{
    if (root == NULL)
        return;
    Node *temp = root;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    cout << "Max is: " << temp->data << endl;
}

void findMin()
{
    if (root == NULL)
        return;
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    cout << "Min is: " << temp->data << endl;
}

int main()
{
    insertion(12);
    insertion(11);
    insertion(9);
    insertion(22);
    insertion(56);
    insertion(66);

    printPpstorder(root);

    search(11);
    findMax();
    findMin();
    return 0;
}
