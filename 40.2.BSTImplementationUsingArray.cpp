#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN

using namespace std;

class ArrayBST
{
private:
    vector<int> tree;

public:
    // Insert a value into the BST
    void insert(int value)
    {
        if (tree.empty())
        {
            tree.push_back(value);
            return;
        }

        int current = 0;
        while (true)
        {
            if (tree[current] == -1)
            {
                tree[current] = value;
                return;
            }

            if (value < tree[current])
            {
                int left = 2 * current + 1;
                if (left >= tree.size())
                {
                    // Resize and fill new positions with -1
                    tree.resize(left + 1, -1);
                }
                current = left;
            }
            else
            {
                int right = 2 * current + 2;
                if (right >= tree.size())
                {
                    tree.resize(right + 1, -1);
                }
                current = right;
            }
        }
    }

    bool search(int value)
    {
        if (tree.empty())
            return false;

        int current = 0;
        while (current < tree.size())
        {
            if (tree[current] == value)
            {
                return true;
            }
            else if (tree[current] == -1)
            {
                return false;
            }

            if (value < tree[current])
            {
                current = 2 * current + 1;
            }
            else
            {
                current = 2 * current + 2;
            }
        }
        return false;
    }

    void printTree()
    {
        cout << "BST Array: [ ";
        for (int val : tree)
        {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    ArrayBST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.printTree();

    cout << "Search 20: " << (bst.search(20) ? "Found" : "Not Found") << endl; // Found
    cout << "Search 45: " << (bst.search(45) ? "Found" : "Not Found") << endl; // Not Found
    cout << "INT_MIN: " << INT_MIN<<"\n";
    return 0;
}




// #include <iostream>
// #include <climits>  // For INT_MIN
// using namespace std;

// const int MAX_SIZE = 63;  // Supports up to height 5 (2⁶-1 nodes)

// class StaticArrayBST {
// private:
//     int tree[MAX_SIZE];  // Use INT_MIN to represent empty nodes

// public:
//     StaticArrayBST() {
//         // Initialize all nodes as empty
//         for (int i = 0; i < MAX_SIZE; i++) {
//             tree[i] = INT_MIN;
//         }
//     }

//     // Insert a value into the BST (returns success status)
//     bool insert(int value) {
//         return insertHelper(0, value);
//     }

//     bool insertHelper(int index, int value) {
//         if (index >= MAX_SIZE) return false;  // Tree full
        
//         if (tree[index] == INT_MIN) {
//             tree[index] = value;
//             return true;
//         }

//         if (value < tree[index]) {
//             return insertHelper(2 * index + 1, value);  // Left child
//         } else {
//             return insertHelper(2 * index + 2, value);  // Right child
//         }
//     }

//     // Search for a value in the BST
//     bool search(int value) {
//         return searchHelper(0, value);
//     }

//     bool searchHelper(int index, int value) {
//         if (index >= MAX_SIZE || tree[index] == INT_MIN) return false;
        
//         if (tree[index] == value) return true;
        
//         if (value < tree[index]) {
//             return searchHelper(2 * index + 1, value);
//         } else {
//             return searchHelper(2 * index + 2, value);
//         }
//     }

//     // Inorder traversal
//     void inorder() {
//         inorderHelper(0);
//         cout << endl;
//     }

//     void inorderHelper(int index) {
//         if (index >= MAX_SIZE || tree[index] == INT_MIN) return;
        
//         inorderHelper(2 * index + 1);  // Left
//         cout << tree[index] << " ";    // Current node
//         inorderHelper(2 * index + 2);  // Right
//     }

//     // Print array contents (for debugging)
//     void printArray() {
//         cout << "BST Array: [ ";
//         for (int i = 0; i < MAX_SIZE; i++) {
//             if (tree[i] != INT_MIN) {
//                 cout << tree[i] << " ";
//             } else {
//                 cout << "NULL ";
//             }
//         }
//         cout << "]\n";
//     }
// };

// int main() {
//     StaticArrayBST bst;

//     // Insert values
//     bst.insert(50);
//     bst.insert(30);
//     bst.insert(70);
//     bst.insert(20);
//     bst.insert(40);
//     bst.insert(60);
//     bst.insert(80);

//     // Print traversal
//     cout << "Inorder Traversal: ";
//     bst.inorder();

//     // Search examples
//     cout << "Search 40: " << (bst.search(40) ? "Found" : "Not found") << endl;
//     cout << "Search 99: " << (bst.search(99) ? "Found" : "Not found") << endl;

//     return 0;
// }