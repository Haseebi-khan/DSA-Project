#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height = 0;
    Node(int value = 0) : data(value), left(nullptr), right(nullptr) {}
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
            cout << "New Node Already Attached.\n";
            return;
        }
    }
}

void printorder(Node *root)
{
    if (root == nullptr)
        return;
    printorder(root->left);
    printorder(root->right);
    cout << root->data << " ";
}

void findMax()
{
    if (root == nullptr)
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
    if (root == nullptr)
        return;
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    cout << "Min is: " << temp->data << endl;
}

// Function to find the in-order successor (minimum value node in the right subtree)
Node* findMinNode(Node* node)
{
    while (node && node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

// Function to delete a node
Node* deleteNode(Node* root, int key)
{
    if (root == nullptr)
        return root;

    // Recur down the tree to find the node to be deleted
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        Node* temp = findMinNode(root->right);

        // Copy the in-order successor's content to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    insertion(100);
    insertion(20);
    insertion(200);
    insertion(10);
    insertion(30);
    insertion(150);
    insertion(300);

    cout << "Tree before deletion: ";
    printorder(root);
    cout << endl;

    // Delete node
    int valueToDelete = 20;
    cout << "Deleting node: " << valueToDelete << endl;
    root = deleteNode(root, valueToDelete);

    cout << "Tree after deletion: ";
    printorder(root);
    cout << endl;

    findMin();
    cout << endl;

    return 0;
}
