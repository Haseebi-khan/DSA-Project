#include <iostream>

using namespace std;

// (a) Draw the BST where the data value at each node is an integer and the values are entered in the following order: 36, 22, 10, 44, 42
// (b) Draw the BST after the following insertions have been done in the tree of part (a): 16, 25, 3, 23, 24 (there is no attempt at being tricky; parts (a) and (b) could be combined into a single one but we want you to check your work so that you don't make a silly mistake) (c) Now draw the tree after deletions of 42, 23 and 22 in this order
// (d) Write down the order on which the node values are reached when the BST of part (c) is traversed (I) in in order (ii) in post order (iii) in preorder
// (e) What is the height of the tree of part

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct StackNode
{
    Node *treeNode;
    StackNode *next;

    StackNode(Node *tNode) : treeNode(tNode), next(nullptr) {}
};

class Stack
{
private:
    StackNode *top;

public:
    Stack() : top(nullptr) {}

    void push(Node *tNode)
    {
        StackNode *newNode = new StackNode(tNode);
        newNode->next = top;
        top = newNode;
    }

    Node *pop()
    {
        if (isEmpty())
            return nullptr;

        Node *tNode = top->treeNode;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return tNode;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    Node *peek()
    {
        if (isEmpty())
            return nullptr;
        return top->treeNode;
    }
};

struct QueueNode
{
    Node *data;
    QueueNode *next;
    QueueNode(Node *node) : data(node), next(nullptr) {}
};

class Queue
{
    QueueNode *front;
    QueueNode *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(Node *data)
    {
        QueueNode *newNode = new QueueNode(data);
        if (front == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    Node *dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return nullptr;
        }
        QueueNode *temp = front;
        Node *value = front->data;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }
        return value;
    }
    Node *peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            return nullptr;
        }
        return front->data;
    }
    bool empty()
    {
        return front == nullptr;
    }
};

void insert(Node *&root, int value)
{
    Node *newNode = new Node(value);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node *current = root;
    while (true)
    {
        if (value < current->data)
        {
            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else if (value > current->data)
        {
            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            current = current->right;
        }
        else
        {
            return;
        }
    }
}

int findMinimum(Node *root)
{
    while (root && root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}

int findMaximum(Node *root)
{
    while (root && root->right != nullptr)
    {
        root = root->right;
    }
    return root->data;
}

// (a) Draw the BST where the data value at each node is an integer and the values are entered in the following order: 36, 22, 10, 44, 42
// (b) Draw the BST after the following insertions have been done in the tree of part (a): 16, 25, 3, 23, 24 (there is no attempt at being tricky; parts (a) and (b) could be combined into a single one but we want you to check your work so that you don't make a silly mistake) (c) Now draw the tree after deletions of 42, 23 and 22 in this order
// (d) Write down the order on which the node values are reached when the BST of part (c) is traversed (I) in in order (ii) in post order (iii) in preorder
// (e) What is the height of the tree of part

Node *deleteNodeSuccessor(Node *root, int value)
{
    Node *parent = nullptr;
    Node *current = root;

    while (current && current->data != value)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (!current)
    {
        cout << "Value not found in BST: " << value << endl;
        return root;
    }

    if (!current->left || !current->right)
    {
        Node *child = current->left ? current->left : current->right;

        if (!parent)
        {
            root = child;
        }
        else if (parent->left == current)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        delete current;
    }
    else
    {
        Node *successorParent = current;
        Node *successor = current->right;

        while (successor->left)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }
        delete successor;
    }

    return root;
}

Node *deleteNodePredecessor(Node *root, int value)
{
    Node *parent = nullptr;
    Node *current = root;

    while (current && current->data != value)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (!current)
    {
        cout << "Value not found in BST: " << value << endl;
        return root;
    }

    if (!current->left || !current->right)
    {
        Node *child = current->left ? current->left : current->right;

        if (!parent)
        {
            root = child;
        }
        else if (parent->left == current)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        delete current;
    }
    else
    {
        Node *predecessorParent = current;
        Node *predecessor = current->left;

        while (predecessor->right)
        {
            predecessorParent = predecessor;
            predecessor = predecessor->right;
        }

        current->data = predecessor->data;

        if (predecessorParent->right == predecessor)
        {
            predecessorParent->right = predecessor->left;
        }
        else
        {
            predecessorParent->left = predecessor->left;
        }
        delete predecessor;
    }

    return root;
}

// Preorder Traversal D + L + R
void preorderTraversal(Node *root)
{
    if (!root)
        return;

    Stack s;
    cout << "Preorder traversal: ";

    s.push(root);
    while (!s.isEmpty())
    {
        Node *cur = s.pop();
        cout << cur->data << " ";
        if (cur->right)
        {
            s.push(cur->right);
        }
        if (cur->left)
        {
            s.push(cur->left);
        }
    }
}

// Inorder Traversal L + D + R
void inorderTraversal(Node *root)
{
    Stack st;
    Node *current = root;
    cout << "InOrder traversal: ";

    while (current != nullptr || !st.isEmpty())
    {
        while (current)
        {
            st.push(current);
            current = current->left;
        }

        current = st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void postorderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << "Postorder traversal: ";

    Stack st1, st2;
    st1.push(root);

    while (!st1.isEmpty())
    {
        Node *current = st1.pop();
        st2.push(current);

        if (current->left)
            st1.push(current->left);
        if (current->right)
            st1.push(current->right);
    }

    while (!st2.isEmpty())
    {
        cout << st2.pop()->data << " ";
    }
}
int heightofTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = heightofTree(root->left);
    int rightHeight = heightofTree(root->right);

    if (leftHeight > rightHeight)
    {
        return 1 + leftHeight;
    }
    else
    {
        return 1 + rightHeight;
    }
}

void LevelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tress is Empty.\n";
        return;
    }
    cout << "Level Order: ";
    Queue q;
    q.enqueue(root);
    while (!q.empty())
    {
        Node *cur = q.peek();
        q.dequeue();
        cout << cur->data << " ";

        if (cur->left)
        {
            q.enqueue(cur->left);
        }
        if (cur->right)
        {
            q.enqueue(cur->right);
        }
    }
}

int main()
{

    Node *root = nullptr;

    // 36, 22, 10, 44, 42

    insert(root, 36);
    insert(root, 22);
    insert(root, 10);
    insert(root, 44);
    insert(root, 42);
    LevelOrderTraversal(root);
    cout << endl;
    cout << endl;

    cout << "After Insertion\n";

    insert(root, 16);
    insert(root, 25);
    insert(root, 3);
    insert(root, 23);
    insert(root, 24);
    LevelOrderTraversal(root);
    cout << endl;
    cout << endl;

    deleteNodePredecessor(root, 42);
    deleteNodeSuccessor(root, 23);
    deleteNodeSuccessor(root, 22);

    cout << "Using Predecessor and Successor Concept \n";
    cout << "After Deletion\n";
    cout << endl;
    LevelOrderTraversal(root);
    cout << endl;
    cout << endl;
    cout << endl;

    inorderTraversal(root);
    cout << endl;

    postorderTraversal(root);
    cout << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "Height of the tree: " << heightofTree(root) << endl;

    return 0;
}