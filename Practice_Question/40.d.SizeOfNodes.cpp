
#include <iostream>
#include <cmath>
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

int height(Node *root)
{
    if (!root)
    {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
    {
        return 1 + leftHeight;
    }
    else
    {
        return 1 + rightHeight;
    }
}

int countNodes(Node *root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    insert(10);
    insert(5);
    insert(15);
    insert(6);
    insert(8);
    insert(9);
    insert(14);
    insert(13);
    insert(12);
    cout << "Height of the Tree is: " << height(root) << endl;
    int Treeheight = height(root);

    int size = countNodes(root);
    int totalNodes = pow(2, Treeheight + 1) - 1;

    cout << "Number of Nodes for Height " << Treeheight << " is: " << totalNodes << endl;

    cout << "\n";
    return 0;
}
