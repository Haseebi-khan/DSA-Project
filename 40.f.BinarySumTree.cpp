
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d = 0) : left(nullptr), right(nullptr) {}
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

// Function convertToSumTree(node):
//     If node is null:
//         Return 0

//     // Recursively convert left and right subtrees to sum tree
//     leftSum = convertToSumTree(node.left)
//     rightSum = convertToSumTree(node.right)

//     // Store the original value of the current node
//     originalValue = node.data

//     // Update current node's value to the sum of left and right subtree sums
//     node.data = leftSum + rightSum

//     // Return the cumulative sum (original value + leftSum + rightSum) to parent
//     Return originalValue + node.data

int convertToSumTree(Node *node)
{
    if (node == nullptr)
        return 0 ;

    int leftSum = convertToSumTree(root->left);
    int rightSum = convertToSumTree(root->right);
    int originalValue = root->data;

    // Update the current node's value to the sum of the left and right subtrees
    root->data = leftSum + rightSum;

    return originalValue + root->data;
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

    cout << endl;
    return 0;
}