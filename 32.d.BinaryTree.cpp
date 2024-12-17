#include <iostream>
using namespace std;

// Definition of TreeNode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Node of our Stack (to hold TreeNode pointers)
struct StackNode
{
    TreeNode *treeNode; // Pointer to TreeNode
    StackNode *next;    // Pointer to the next StackNode

    StackNode(TreeNode *tNode) : treeNode(tNode), next(nullptr) {}
};

// Custom Stack Class
class Stack
{
private:
    StackNode *top; // Pointer to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Push a TreeNode pointer onto the stack
    void push(TreeNode *tNode)
    {
        StackNode *newNode = new StackNode(tNode);
        newNode->next = top;
        top = newNode;
    }

    // Pop a TreeNode pointer from the stack
    TreeNode *pop()
    {
        if (isEmpty())
            return nullptr;

        TreeNode *tNode = top->treeNode;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return tNode;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Peek the top TreeNode without popping
    TreeNode *peek()
    {
        if (isEmpty())
            return nullptr;
        return top->treeNode;
    }

    // Destructor
    ~Stack()
    {
        while (!isEmpty())
            pop();
    }
};

// Preorder Traversal
void preorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    Stack st;
    st.push(root);

    while (!st.isEmpty())
    {
        TreeNode *current = st.pop();
        cout << current->val << " ";

        // Push right first so left is processed next
        if (current->right)
        {
            st.push(current->right);
        }
        if (current->left)
        {
            st.push(current->left);
        }
    }
}

// Inorder Traversal
void inorderTraversal(TreeNode *root)
{
    Stack st;
    TreeNode *current = root;

    while (current != nullptr || !st.isEmpty())
    {
        while (current)
        {
            st.push(current);
            current = current->left;
        }

        current = st.pop();
        cout << current->val << " ";
        current = current->right;
    }
}

// Postorder Traversal
void postorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    Stack st1, st2;
    st1.push(root);

    while (!st1.isEmpty())
    {
        TreeNode *current = st1.pop();
        st2.push(current);

        if (current->left)
            st1.push(current->left);
        if (current->right)
            st1.push(current->right);
    }

    // Print nodes from the second stack
    while (!st2.isEmpty())
    {
        cout << st2.pop()->val << " ";
    }
}

// Function to execute the desired traversal
void treeTraversal(TreeNode *root, int order)
{
    if (order == 1)
    {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
    }
    else if (order == 2)
    {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
    }
    else if (order == 3)
    {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
    }
    else
    {
        cout << "Invalid option! Choose 1, 2, or 3.";
    }
    cout << endl;
}

int main()
{
    // Example Binary Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Choose Traversal Order:" << endl;
    cout << "1. Preorder" << endl;
    cout << "2. Inorder" << endl;
    cout << "3. Postorder" << endl;

    int choice;
    cin >> choice;

    treeTraversal(root, choice);

    return 0;
}
