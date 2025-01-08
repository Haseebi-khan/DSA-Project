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
    insertNode(100);
    insertNode(20);
    insertNode(10);
    insertNode(30);
    insertNode(200);
    insertNode(150);
    insertNode(300);
    
    cout << "PreOrder Tree:";
    preshow(root);

    cout << "\nInOrder Tree:";
    show(root);

    cout << "\nPostOrder Tree:";
    postshow(root);
    
    maxNode();
    minNode();

    


    cout << endl;
    return 0;
}




// #include <iostream>
// using namespace std;

// struct Node
// {
//     int key;
//     Node *left;
//     Node *right;
//     Node(int item)
//     {
//         key = item;
//         left = NULL;
//         right = NULL;
//     }
// };

// // A utility function to insert a new node with
// // the given key
// Node *insert(Node *node, int key)
// {

//     // If the tree is empty, return a new node
//     if (node == NULL)
//         return new Node(key);

//     // If the key is already present in the tree,
//     // return the node
//     if (node->key == key)
//         return node;

//     // Otherwise, recur down the tree/ If the key
//     // to be inserted is greater than the node's key,
//     // insert it in the right subtree
//     if (node->key < key)
//         node->right = insert(node->right, key);

//     // If the key to be inserted is smaller than
//     // the node's key,insert it in the left subtree
//     else
//         node->left = insert(node->left, key);

//     // Return the (unchanged) node pointer
//     return node;
// }

// // A utility function to do inorder tree traversal
// void inorder(Node *root)
// {
//     if (root != NULL)
//     {
//         inorder(root->left);
//         cout << root->key << " ";
//         inorder(root->right);
//     }
// }

// // Driver program to test the above functions
// int main()
// {
//     // Creating the following BST
//     //      50
//     //     /  \
//     //    30   70
//     //   / \   / \
//     //  20 40 60 80

//     Node *root = new Node(50);
//     root = insert(root, 30);
//     root = insert(root, 20);
//     root = insert(root, 40);
//     root = insert(root, 70);
//     root = insert(root, 60);
//     root = insert(root, 80);

//     // Print inorder traversal of the BST
//     inorder(root);

//     cout << endl;
//     return 0;
// }