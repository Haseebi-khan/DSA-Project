// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val = 0)
//     {
//         data = val;
//         left = right = nullptr;
//     }
// };

// Node *root = nullptr;

// // void Add(int value)
// // {
// //     Node *newNode = new Node(value);
// //     if (root == nullptr)
// //     {
// //         root = newNode;
// //         return;
// //     }
// // }
// void preorderRecursive(Node* root) {
//     if (root == nullptr) return;

//     cout << root->data << " ";    // Process the root
//     preorderRecursive(root->left);  // Traverse the left subtree
//     preorderRecursive(root->right); // Traverse the right subtree
// }

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Define a TreeNode class
class TreeNode
{
public:
    int data;        // Value of the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int val) : left(nullptr), right(nullptr), data(val) {}
};

void preorderIterative(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();

        cout << curr->data << " "; // Process the root

        if (curr->right)
        {

            st.push(curr->right); // Push right child first
        }
        if (curr->left)
        {
            st.push(curr->left); // Push left child later
        }
    }
}

void inorderIterative(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr); // Push all left nodes
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " "; // Process the root
        curr = curr->right;        // Move to the right subtree
    }
}

void postorderIterative(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        TreeNode *curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left)
            st1.push(curr->left); // Push left child
        if (curr->right)
            st1.push(curr->right); // Push right child
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " "; // Process the root
        st2.pop();
    }
}

// Level-order Traversal (Breadth-First Search)
void levelOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        cout << curr->data << " "; // Process the current node

        if (curr->left)
        {
            q.push(curr->left); // Enqueue left child
        }
        if (curr->right)
        {
            q.push(curr->right); // Enqueue right child
        }
    }
}

int main()
{
    // Create nodes
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // root->right->right = new TreeNode(8);
    // root->right->right = new TreeNode(9);
    // root->right->right = new TreeNode(10);
    // root->right->right = new TreeNode(11);
    // root->right->right = new TreeNode(12);
    // root->right->right = new TreeNode(13);
    // root->right->right = new TreeNode(14);
    // root->right->right = new TreeNode(15);

    // Demonstrate Preorder Traversal
    // cout << "Preorder Traversal (Recursive): ";
    // preorderRecursive(root);
    cout << "\nPreorder Traversal (Iterative): ";
    preorderIterative(root);

    // Demonstrate Inorder Traversal
    // cout << "\nInorder Traversal (Recursive): ";
    // inorderRecursive(root);
    cout << "\nInorder Traversal (Iterative): ";
    inorderIterative(root);

    // Demonstrate Postorder Traversal
    // cout << "\nPostorder Traversal (Recursive): ";
    // postorderRecursive(root);
    cout << "\nPostorder Traversal (Iterative): ";
    postorderIterative(root);

    // Demonstrate Level-order Traversal
    cout << "\nLevel-order Traversal: ";
    levelOrder(root);

    cout << endl;

    return 0;
}

// Postorder Traversal (Left, Right, Root)
// void postorderRecursive(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     postorderRecursive(root->left);  // Traverse the left subtree
//     postorderRecursive(root->right); // Traverse the right subtree
//     cout << root->data << " ";       // Process the root
// }

// Inorder Traversal (Left, Root, Right)
// void inorderRecursive(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     inorderRecursive(root->left);  // Traverse the left subtree
//     cout << root->data << " ";     // Process the root
//     inorderRecursive(root->right); // Traverse the right subtree
// }

// Preorder Traversal (Root, Left, Right)
// void preorderRecursive(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     cout << root->data << " ";      // Process the root
//     preorderRecursive(root->left);  // Traverse the left subtree
//     preorderRecursive(root->right); // Traverse the right subtree
// }
