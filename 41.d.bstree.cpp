#include <iostream>
using namespace std;

// Construct a BSTree that stores the information about books (Title, Authors, Rating).

// Rating is a numeric value.

// Authors is a linked list, and Title is a string.

// The BSTree is constructed based on Rating.

// You have to implement the following operations:
// The above function shows all the titles that have a rating greater than or equal to the parameter.
//     • void show_books(Rating)

// The above function adds a new book into the BSTree with the given data.
//     • void insert_book(Title, Authors, Rating)

class Authors
{
public:
    string Name;
    Authors *next;
    Authors(string n) : Name(n), next(nullptr) {}
};

class TreeNode
{
public:
    string title;
    Authors *authors;
    float rating;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string title, string authorName, float rating = 0) : title(title), rating(rating), left(nullptr), right(nullptr)
    {
        authors = nullptr;
        insertAtEnd(authors);
    }

    void insertAtEnd(Authors *&newNode)
    {
        if (authors == nullptr)
        {
            authors = newNode;
        }
        else
        {
            Authors *temp = authors;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};

TreeNode *books = nullptr;

void insert_book(string title, string authorname, float rating)
{
    TreeNode *book = new TreeNode(title, authorname, rating);

    if (books == nullptr)
    {
        books = book;
        return;
    }

    TreeNode *temp = books;

    while (temp)
    {
        if (rating > temp->rating)
        {
            if (temp->right == nullptr)
            {
                temp->right = book;
                return;
            }
            else
            {
                temp = temp->right;
            }
        }
        else if (rating < temp->rating)
        {
            if (temp->left == nullptr)
            {
                temp->left = book;
                return;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            return;
        }
    }
}

void show_books(TreeNode *node, double rating)
{
    if (!node)
        return;

    if (node->rating >= rating)
    {
        show_books(node->left, rating);
        cout << "Title: " << node->title << "  Rating: " << node->rating << endl;
    }

    // Always traverse right subtree regardless of current node's rating
    show_books(node->right, rating);
}

int main()
{
    string title, author;
    float rating;
    char input = '\0';

    string s1[] = {"48LawsofPower", "itEndWithUs", "SilentPaient", "Focus"};
    string s2[] = {"Robert_Greene", "Collbey", "Alex", "Elbareet"};
    double r[] = {5.56, 3.65, 7.6, 5.66};

    for (int i = 0; i < 4; i++)
    {
        insert_book(s1[i], s2[i], r[i]);
    }

    cout << "Add another book press y: ";
    cin >> input;

    while (input == 'y')
    {
        cout << "Enter the Book title: ";
        cin >> title;
        cout << "Enter the Book Author: ";
        cin >> author;
        cout << "Enter the Book Rating: ";
        cin >> rating;

        insert_book(title, author, rating);

        cout << "Add another book press y: ";
        cin >> input;
    }

    cout << endl;
    cout << endl;
    cout << "Books with rating > 4.5: " << endl;

    cout << endl;
    cout << endl;

    show_books(books, 4.5);

    cout << endl;
    return 0;
}

// 48_Laws_of_Power
// Robert_Greene

// itEndWithUs
// Collbey

// SilentPaient
// Alex

// Focus
// Elbareet