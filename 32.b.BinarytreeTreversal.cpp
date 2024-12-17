#include <iostream>
using namespace std;

struct TNode
{
    int data;
    TNode *left;
    TNode *right;
    TNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
TNode *root = nullptr;

struct Stack
{
    TNode *data;
    Stack *next;
    Stack(TNode *node) : data(node), next(nullptr) {}
};

Stack *top = nullptr;
void push(TNode *data)
{
    Stack *newNode = new Stack(data);
    if (!top)
    {
        top = newNode;
        return;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
void pop()
{
    if (!top)
    {
        cout << "Empty\n.";
        return;
    }
    else
    {
        Stack *temp = top;
        top = top->next;
        delete temp;
    }
}

TNode *peek()
{
    if (!top)
        return nullptr;
    return top->data;
}

void Traversal()
{
    if (!root)
    {
        return;
    }
    push(root);

    while (top != nullptr)
    {
        TNode *cur = peek();
        pop();
        cout << cur->data << " ";

        if (cur->right)
        {
            push(cur->right);
        }
        if (cur->left)
        {
            push(cur->left);
        }
    }
}

int main()
{
    root = new TNode(10);
    root->left = new TNode(9);
    root->right = new TNode(8);
    root->left->left = new TNode(7);
    root->left->right = new TNode(6);
    root->right->left = new TNode(5);
    root->right->right = new TNode(4);

    Traversal();

    cout << endl;
    return 0;
}