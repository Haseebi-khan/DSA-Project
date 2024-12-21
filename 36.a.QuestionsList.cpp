// Q1: a. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in
// reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked
// list. [You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Moreover, keep in mind the concept of carry in addition]
// Example:
// Enter the First number: 342
// Enter the Second Number: 465
// Linked List for the first number: (2 -> 4 -> 3)
// Linked List for the second number: (5 -> 6 -> 4)
// Add the Linked Lists: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Answer: 807
// Explanation: 342 + 465 = 807.


// Q5:

// Department of Computer SciencePage 2

// A biotonic doubly linked list is a doubly linked list which is first increasing and then decreasing. A
// strictly increasing or a strictly decreasing list is also a biotonic doubly linked list. For example, the given
// list is an example of biotonic doubly linked list.

// 2<-> 5 <-> 7 <-> 12 <-> 10 <-> 6 <-> 4 <-> 1

// Write down a code in C++ to sort the biotonic list. The algorithm must be as efficient as possible.


// Q2: Remove Nth Node From End of List : Given a linked list, remove the n-th node from the end of list
// and return its head.
// Example:
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.



// Q3: Merge two sorted lists
// Linked List 1 : 23-> 45-> 65
// Linked List 2 : 12->67->78
// Department of Computer SciencePage 1


// Merge Linked List: 12 -> 23 ->45 ->65 ->67 ->78
// Q4: Given a linked list, swap every two adjacent nodes and return its head. Example:
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Q5: Given a linked list, rotate the list to the right by k places, where k is non-negative.
// Example 1:
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL



// Q6: Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
// from the original list.
// Example 1:
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5



// Question 7:

// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// Example:
// Input: head = 1->4->3->2->5->2 1  and x = 3
// Output: 1->2->2->4->3->5 
// Tasks:
// a. Write down an algorithm for the aforementioned problem.
// b. Write down code in C++ to accomplish the aforementioned task.
// Let me know if you have any other questions or need further clarification!

// Question 8:
// Partition a linked list: Given a linked list and a value x, rearrange the nodes in the list such that all nodes with values less than x come before nodes with values greater than or equal to x.
// Provide an algorithm: Describe a step-by-step procedure to solve this partitioning problem.
// Implement in C++: Write C++ code to implement the algorithm and perform the linked list partitioning.
// The example given in all images is the same:
// Input: head = 1->4->3->2->5->2 and x = 3
// Output: 1->2->2->4->3->5


// Question 9:
// Write a recursive function to DLL class that returns true if the doubly link list is a palindrome. Think carefully about the input parameter of your function IsDLL.Palindrome
// Analysis:
// Doubly Linked List: A doubly linked list is a data structure where each node has pointers to both the next and previous nodes. This allows for efficient traversal in both directions.
// Palindrome: A palindrome is a sequence that reads the same forward and backward. In the context of a linked list, it means the values of the nodes are the same when traversed from head to tail and from tail to head.
// Recursive Approach:
// Base Case:
// If the list is empty or has only one node, it's trivially a palindrome. Return true.
// Recursive Step:
// Compare the data of the first node (head) and the last node (tail).
// If they are different, the list is not a palindrome. Return false.
// Otherwise, recursively check the remaining sublist.


// Question 10: 
// Consider a function findTopPlayers which receives a list of N players with in a tournament and returns
// top 3 players based on their scores.
// void sort(Player** playersList, int N) {
// int largest;
// for (int j = 0; j < N - 1; j++) {
// largest = j;
// for (int i = j + 1; i < N; i++) {
// if (playersList[i]->getScore() > playersList[largest]->getScore())
// largest = i;
// }
// swap(playersList[j], playersList[largest]);
// }
// }
// void findTopPlayers(Player** playersList, int N, Player** topPlayersList) {
// sort(playersList, N);
// for (int i = 0; i < 3; ++i) {
// topPlayersList[i] = playersList[i];
// }
// }
// (a) Do the time complexity analysis of the function findTopPlayers.
// (b) Devise a better solution for this problem (and write its pseudocode) to improve the running time of this
// algorithm. What will be the time complexity of your improved algorithm?

// Question 11: 
// Given a string containing only lowercase letters and spaces, remove pairs of matching characters. This
// matching starts from the end of the string. 
// For example:
// Input: “assassin”
// Output: “in“
// Input: “pacific ocean”
// Output: “pcf oen“
// Input: “an assassin sins”
// Output: “an“

// Question 12:

// Write a C++ implementation for the function removePairs to solve the above mentioned problem.
// You’re allowed to use only two stacks and a constant number of variables. The minimum program
// structure is shown below
// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;
// string removePairs(string input) {
// stack <char> stack1;
// stack <char> stack2;
// //Write code here
// }
// int main() {
// cout << removePairs("assassin") << endl;
// cout << removePairs("an assassin sins") << endl;
// cout << removePairs("pacific ocean") << endl;
// return 0;
// }
// b) What is the overall computational complexity of your program in terms of Big-Oh?
// c) Show the dry run of your algorithm with your name as the input string and write the final output of
// your algorithm. (Use your complete official name registered in FLEX at FAST-NU)


// Q3: [2]
// Three agents were working on a mission when they came across a secret message. They decided to deliver
// this message to their boss but they can’t deliver the message as it is because it’s very sensitive information.
// They decided to encrypt it and then send it to their boss. All of the three agents tried to encode it and came
// up with the following Huffman codes:
// Letter Frequency Agent 1 Agent 2 Agent 3
// a 15 00 11 01
// h 4 111 000 110
// m 8 10 01 10
// t 7 110 001 111
// space 12 01 10 00
// Choose one of the following options and Justify your answer:
// i. All codes are wrong
// ii. All codes are correct
// iii. Only one of them is correct (mention that agent)

// Question 1: 
// We wish to add a method called searchAndPromote to our singly linked list class. Each node in the list contains:

// An integer key
// A character value
// A next pointer
// Function Details
// The function searchAndPromote searches the list for a given key.
// If found, it promotes all nodes containing that key to the start of the list.
// The nodes must appear at the start of the list in the same order they were found during the search.
// The function must not delete or create new nodes; it should simply reconnect the existing nodes.
// Example
// Before calling: searchAndPromote(3)
// After calling: Nodes (3, Q) and (3, B) appear at the start of the list, maintaining their original order: (3, Q) -> (3, B) -> ...

// Node and List Definitions:

// cpp
// Copy code
// class LinkedList {
//     struct Node {
//         int key;
//         char value;
//         Node* next;
//     };
//     Node* head;

// public:
//     ...
//     bool searchAndPromote(int key);
// };
// Task
// Write the C++ definition of the function:

// cpp
// Copy code
// bool searchAndPromote(int key);
// Time Complexity
// Analyze the time complexity of the function given there are n nodes in the list.
// Answer: O(n)

// Question 2: (Marks: 12+3)
// Write a C++ implementation to determine whether an input string is in the following form:

// ruby
// Copy code
// s1 $ s1R $ s2 $ s2R ... sk $ skR
// Where:

// Each si is a string consisting of letters A and B.
// Each siR is the reverse of si.
// $ separates strings in the format.
// Constraints
// At each step, you can only read the next character of the string.
// If the string does not follow the above format, output: "The string is not in proper format".
// Otherwise, output: "The string is in proper format".
// Example Input/Output
// Input: ABAB$BABA$ABBBAB$BABBBA
// Output: "The string is in proper format"

// Input: ABAB$BABA$ABBBA$ABBAB
// Output: "The string is not in proper format"

// Task
// Write a C++ function:

// cpp
// Copy code
// bool checkFormat(char* str);
// Time Complexity
// Analyze the time complexity of the function if the input string has n characters.
// Answer: O(n)

// Question 3: (Marks: 10+5+5)
// Part (a)
// Perform a step count analysis of the following program and derive an equation for T(n) for the worst case:

// cpp
// Copy code
// void mystery(int A[], int n) {
//     int i = n - 1;
//     for (int i = n - 1; i > 0 && A[i] < A[i / 2];) {
//         swap(A[i], A[i / 2]);
//         i = i / 2;
//     }
//     res = 0;
//     for (i = 1; i < n; ++i)
//         for (j = 1; j < i; ++j)
//             for (k = 0; k < n; k * 2)
//                 ++res;
// }
// Solution:

// T(n) = 3 + 3log(n) = O(log(n))
// T(n) = 1 + 3n + n(n+1)/2 + n(n+1)/2 * n = O(n^2.5)
// Part (b)
// We want to implement a Queue class using a circular singly linked list as its data member.

// The circular linked list contains only one data member: tail, which is of type Node*.
// tail points to the last element of the list (or nullptr if the list is empty).
// Task:
// Explain how the enqueue and dequeue functions can be implemented using the circular singly linked list.

// Answer:
// Enqueue: Insert at the end of the circular linked list by updating tail->next.
// Dequeue: Remove the node pointed to by tail->next.
// Both operations can be performed in O(1) time.
// Part (c)
// We wish to implement an UNDO functionality in a text editor that remembers only the last 10 operations.
// Task:
// Which data structure would be most efficient (in terms of space and time) to implement this functionality?
// Answer:
// A Circular Array is the most efficient option because:
// It can implement all operations (insert, delete, access) in O(1) time.
// It uses a fixed amount of space, avoiding the overhead of pointers.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Question 1:

// Consider a singly linked list class with a head pointer already implemented for character datatype. You have to add a functionality in the class to balance out the number of consecutive occurrences of a particular character in the list.   

// Question 2:

// For that you will implement a function bool Equalize_Occurrences (char key, int maxcount) of the class list, that will take a character key and maximum count for the consecutive occurrences of the key in parameters. It will then traverse the list, verify and update the consecutive occurrences of the key according to maximum count and returns true. It returns false if no occurrence of key is found.   

// Question 3:

// Note: You can traverse the list only once for this task.

// Question 4:

// For Example, if the singly linked list L1 contains data as follows:

// Head -> C -> B -> C -> C -> A -> D -> C -> C -> C -> C -> C -> B -> NULL

// then after function call L1. Equalize_Occurrences ('C', 2); list will be updated as follows.

// Head -> C -> C -> B -> C -> C -> A -> D -> C -> C -> C -> B -> NULL

// if it occurs once, (insert another)
// if it occurs twice, (nothing)
// if it occurs > twice, (delete)

// 1. Write a C++ program to create and display a Singly Linked List.
// Test Data:
// The list contains the data entered:
// 11 9 7 5 3 1
// Click me to see the sample solution

// 2. Write a C++ program to create a singly linked list of n nodes and display it in reverse order.
// Test Data:
// Original Linked list:
// 11 9 7 5 3 1
// Reverse Linked list:
// 1 3 5 7 9 11
// Click me to see the sample solution

// 3. Write a C++ program to create a singly linked list of n nodes and count the number of nodes.
// Test Data:
// Original Linked list:
// 13 11 9 7 5 3 1
// Number of nodes in the said Linked list:
// 7
// Click me to see the sample solution

// 4. Write a C++ program to insert a new node at the beginning of a Singly Linked List.
// Test Data:
// Original Linked list:
// 13 11 9 7 5 3 1
// Insert a new node at the beginning of a Singly Linked List:
// 0 13 11 9 7 5 3 1
// Click me to see the sample solution

// 5. Write a C++ program to insert a new node at the end of a Singly Linked List.
// Test Data:
// Original Linked list:
// 13 11 9 7 5 3 1
// Insert a new node at the end of a Singly Linked List:
// 13 11 9 7 5 3 1 0
// Click me to see the sample solution

// 6. Write a C++ program to find the middle element of a given Linked List.
// Test Data:
// Original list:
// 7 5 3 1
// Middle element of the said list:
// 3
// Original list:
// 9 7 5 3 1
// Middle element of the said list:
// 5
// Click me to see the sample solution

// 7. Write a C++ program to insert a new node at the middle of a given Singly Linked List.
// Test Data:
// Original list:
// 7 5 3 1
// Singly Linked List: after insert 9 in the middle of the said list-
// 7 5 9 3 1
// Singly Linked List: after insert 11 in the middle of the said list-
// 7 5 9 11 3 1
// Singly Linked List: after insert 13 in the middle of the said list-
// 7 5 9 13 11 3 1
// Click me to see the sample solution

// 8. Write a C++ program to get Nth node in a given Singly Linked List.
// Test Data:
// Original list:
// 7 5 3 1
// Position: 1
// Value: 7
// Position: 2
// Value: 5
// Position: 3
// Value: 3
// Position: 4
// Value: 1
// Click me to see the sample solution

// 9. Write a C++ program to insert a new node at any position of a Singly Linked List.
// Test Data:
// Original list:
// 7 5 3 1
// Position: 1, Value: 12
// Updated list:
// 12 7 5 3 1
// Position: 4, Value: 14
// Updated list:
// 12 7 5 14 3 1
// Position: 7, Value: 18
// Updated list:
// 12 7 5 14 3 1 18
// Click me to see the sample solution

// 10. Write a C++ program to delete first node of a given Singly Linked List.
// Test Data:
// Original Linked list:
// 13 11 9 7 5 3 1
// Delete first node of Singly Linked List:
// 11 9 7 5 3 1
// Click me to see the sample solution

// 11. Write a C++ program to delete a node from the middle of Singly Linked List.
// Test Data:
// Original list:
// 9 7 5 3 1
// After removing the middle element of the said list:
// 9 7 3 1
// After removing the middle element of the said list:
// 9 7 1
// After removing the middle element of the said list:
// 9 1
// After removing the middle element of the said list:
// 9
// Click me to see the sample solution

// 12. Write a C++ program to delete the last node of a Singly Linked List.
// Test Data:
// Original list:
// 7 5 3 1
// Remove the last node of the said list:
// Updated list:
// 7 5 3
// Again remove the last node of the said list:
// Updated list:
// 7 5
// Click me to see the sample solution

// 13. Write a C++ program to delete the nth node of a Singly Linked List from the end.
// Test Data:
// Original list:
// 7 5 3 1
// Remove the 2nd node from the end of the said list:
// Updated list:
// 7 5 1
// Remove the 3rd node from the end of the said list:
// Updated list:
// 5 1
// Click me to see the sample solution

// 14. Write a C++ program to find the kth node of a linked list by starting at the middle and moving towards the head.
// Test Data:
// Original list:
// 9 7 5 3 1
// kth node of a linked list by starting at
// the middle and moving towards the head:
// Position = 2
// Value = 9
// Click me to see the sample solution

// 15. Write a C++ program to create and display a doubly linked list.
// Test Data:
// Doubly linked list is as follows:
// Traversal in Forward direction:
// Orange White Green Red
// Traversal in Reverse direction:
// Red Green White Orange
// Click me to see the sample solution

// 16. Write a C++ program to create a doubly linked list of n nodes and display it in reverse order.
// Test Data:
// Doubly linked list is as follows:
// Traversal in Forward direction:
// Orange White Green Red
// Traversal in Reverse direction:
// Red Green White Orange
// Reverse Doubly linked list:
// Traversal in Forward direction:
// Red Green White Orange
// Traversal in Reverse direction:
// Orange White Green Red
// Click me to see the sample solution

// 17. Write a program in C++ to create a doubly linked list of n nodes and count the number of nodes.
// Test Data:
// Doubly linked list is as follows:
// Traversal in Forward direction:
// Orange White Green Red
// Traversal in Reverse direction:
// Red Green White Orange
// Total number of nodes = 4
// Click me to see the sample solution

// 18. Write a C++ program to insert a new node at the beginning of a Doubly Linked List.
// Test Data:
// Doubly linked list is as follows:
// ------------------------------
// Traversal in Forward direction: Orange White Green Red
// Traversal in Reverse direction: Red Green White Orange
// Insert a new node at the beginning of a Doubly Linked List:
// -------------------------------------------------------------
// Traversal in Forward direction: Pink Orange White Green Red
// Traversal in Reverse direction: Red Green White Orange Pink
// Click me to see the sample solution

// 19. Write a C++ program to insert a new node at the end of a Doubly Linked List.
// Test Data:
// Doubly linked list is as follows:
// ------------------------------
// Traversal in Forward direction: Orange White Green Red
// Traversal in Reverse direction: Red Green White Orange
// Insert a new node at the end of a Doubly Linked List:
// -------------------------------------------------------------
// Traversal in Forward direction: Orange White Green Red Pink
// Traversal in Reverse direction: Pink Red Green White Orange
// Click me to see the sample solution

// 20. Write a C++ program to find the middle element of a given Doubly Linked List.
// Test Data:
// Doubly linked list is as follows:
// ------------------------------
// Traversal in Forward direction: Orange White Green Red
// Traversal in Reverse direction: Red Green White Orange
// The middle element is: Green
// Insert a new node at the end of a Doubly Linked List:
// -------------------------------------------------------------
// Traversal in Forward direction: Pink Orange White Green Red
// Traversal in Reverse direction: Red Green White Orange Pink
// The middle element is: White
// Click me to see the sample solution

// 21. Write a C++ program to insert a new node at the middle of a given Doubly Linked List.
// Test Data:
// Doubly linked list is as follows:
// ---------------------------------
// Traversal in Forward direction: Orange White Green Red
// Traversal in Reverse direction: Red Green White Orange
// Insert a new node at the middle position of the said Doubly linked list:
// -----------------------------------------------------------------------
// Traversal in Forward direction: Orange White Pink Green Red
// Traversal in Reverse direction: Red Green Pink White Orange
// Insert another new node at the middle position of the said Doubly linked list:
// -----------------------------------------------------------------------------
// Traversal in Forward direction: Orange White Pink Black Green Red
// Traversal in Reverse direction: Red Green Black Pink White Orange