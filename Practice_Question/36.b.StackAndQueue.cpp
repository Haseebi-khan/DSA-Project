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


// In computer science, a stack is an abstract data type that serves as a collection of elements, with two main operations:

// Push, which adds an element to the collection, and
// Pop, which removes the most recently added element that was not yet removed.
// Stacks entered the computer science literature in 1946, when Alan M. Turing used the terms "bury" and "unbury" as a means of calling and returning from subroutines. Stack follows LIFO data structure type.

// 1. Write a C++ program to implement a stack using an array with push and pop operations. Find the top element of the stack and check if the stack is empty or not.
// 2. Write a C++ program to implement a stack using an array with push and pop operations. Check if the stack is full.
// 3. Write a C++ program to sort a given stack (using an array) using another stack.
// Test Data:
// Input some elements onto the stack:
// Stack elements: 0 1 5 2 4 7
// Sort the elements in the stack:
// Display the sorted elements of the stack:
// Stack elements: 0 1 2 4 5 7
// Remove two elements:
// Stack elements: 2 4 5 7
// Input two more elements
// Stack elements: 10 -1 2 4 5 7
// Sort the elements in the stack:
// Display the sorted elements of the stack:
// Stack elements: -1 2 4 5 7 10
// 4. Write a C++ program that reverses the stack (using an array) elements.
// Test Data:
// Input some elements onto the stack:
// Stack elements: 0 1 5 2 4 7
// Display the reverse elements of the stack:
// Stack elements: 7 4 2 5 1 0
// Remove two elements:
// Stack elements: 2 5 1 0
// Input two more elements
// Stack elements: 10 -1 2 5 1 0
// Display the reverse elements of the stack:
// Stack elements: 0 1 5 2 -1 10
// Click me to see the sample solution

// 5. Write a C++ program to calculate the average value of the stack (using an array) elements.
// Test Data:
// Input some elements onto the stack:
// Stack elements: 0 1 5 2 4 7
// Average of the said stack values: 3.17
// Remove two elements:
// Stack elements: 5 2 4 7
// Input two more elements
// Stack elements: 10 -1 5 2 4 7
// Average of the said stack values: 4.50
// Click me to see the sample solution

// 6. Write a C++ program to find the maximum element in a stack (using an array).
// Test Data:
// Input some elements onto the stack:
// Stack elements: 0 1 5 2 4 7
// Maximum value: 7
// Remove two elements: Stack elements: 5 2 4 7
// Input two more elements
// Stack elements: 10 -1 5 2 4 7
// Maximum value: 10
// Click me to see the sample solution

// 7. Write a C++ program to find the minimum element in a stack (using an array).
// Test Data:
// Input some elements onto the stack:
// Stack elements: 0 1 5 2 4 7
// Minimum value: 0
// Remove two elements:
// Stack elements: 5 2 4 7
// Input two more elements
// Stack elements: 10 -1 5 2 4 7
// Minimum value: -1
// Click me to see the sample solution

// 8. Write a C++ program to find the middle element of a stack (using an array).
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 5 2 4 7
// Middle element of the stack: 2
// Input three more elements
// Stack elements are: -3 -2 -1 5 2 4 7
// Middle element of the stack: 5
// Click me to see the sample solution

// 9. Write a C++ program to delete the middle element of a stack (using an array).
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 5 2 4 7
// Delete the middle element of the stack:
// Stack elements are: 5 4 7
// Input two more elements
// Stack elements are: -2 -1 5 4 7
// Delete the middle element of the stack:
// Stack elements are: -2 -1 4 7
// Click me to see the sample solution

// 10. Write a C++ program to find and remove the largest element in a stack.
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 5 2 4 7
// Find and remove the largest element 7 from the stack.
// Stack elements are: 5 2 4
// Input two more elements
// Stack elements are: 20 -1 5 2 4
// Find and remove the largest element 20 from the stack.
// Stack elements are: -1 5 2 4
// Click me to see the sample solution

// 11. Write a C++ program to find and remove the lowest element in a stack.
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 5 2 4 7
// Find and remove the lowest element 2 from the stack.
// Stack elements are: 5 4 7
// Input two more elements
// Stack elements are: 2 -1 5 4 7
// Find and remove the lowest element -1 from the stack.
// Stack elements are: 2 5 4 7
// Click me to see the sample solution

// 12. Write a C++ program to remove duplicates from a stack using arrays.
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 5 2 2 4 7
// Remove duplicates from the said stack:
// Stack elements are: 5 2 4 7
// Input two more elements onto the stack:
// Stack elements are: 5 7 5 2 4 7
// Remove duplicates from the said stack:
// Stack elements are: 5 7 2 4
// Click me to see the sample solution

////==================================================================================================


// 14. Write a C++ program to get the Kth element of a stack from top position.
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 4 3 2 1
// Remove 2 from the said stack:
// 2nd element from the top of the stack: 3
// Input two more elements onto the stack:
// Stack elements are: 0 -1 4 3 2 1
// 1st element from the top of the stack: 0
// 3rd element from the top of the stack: 4
// 6th element from the top of the stack: 1
// Click me to see the sample solution

// 15. Write a C++ program to replace the kth element with new value in a stack (using an array).
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 5 2 2 4 7
// Replace the kth element with new value:
// k = 2 New val = 14
// Stack elements are: 5 14 2 4 7
// Replace the kth element with new value:
// k = 5 New val = 56
// Stack elements are: 5 14 2 4 56
// Click me to see the sample solution

// 16. Write a C++ program to implement a stack using a linked list with push, pop operations.
// Test Data:
// Input some elements onto the stack (using linked list):
// Stack elements are: 1 3 5 6
// Remove 2 elements from the stack:
// Stack elements are: 5 6
// Input 2 more elements:
// Stack elements are: 9 8 5 6
// Click me to see the sample solution

// 17. Write a C++ program to check a stack's size and whether it is empty or not. The stack is implemented using a linked list.
// Test Data:
// Check a stack (using linked list) is empty or not!
// Stack is empty!
// Input some elements onto the stack:
// Stack elements are: 0 1 3 5 6
// Size of the stack is 5
// Remove two elements form the said stack:
// Stack elements are: 3 5 6
// Size of the stack is 3
// Click me to see the sample solution

// 18. Write a C++ program to reverse the elements of a stack (using a linked list).
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 0 1 3 5 6
// Display the reverse elements of the stack:
// Stack elements are: 6 5 3 1 0
// Input two more elements:
// Stack elements are: 45 35 6 5 3 1 0
// Display the reverse elements of the stack:
// Stack elements are: 0 1 3 5 6 35 45
// Click me to see the sample solution

// 19. Write a C++ program to sort the elements of a stack (using a linked list).
// Test Data:
// Input some elements onto the stack:
// Stack elements are: 0 1 3 5 6
// Sorted elements of the said stack:
// Stack elements are: 6 5 3 1 0
// Input two more elements:
// Stack elements are: 29 35 6 5 3 1 0
// Sorted elements of the said stack:
// Stack elements are: 35 29 6 5 3 1 0
// Click me to see the sample solution

// 20. Write a C++ program to implement a stack using a dynamic array with push and pop operations. Find the top element of the stack and check if the stack is empty or not.
// Test Data:
// Input the size of the stack: 8 Is the stack empty? Yes Input some elements onto the stack: Stack elements are: 9 7 5 3 1 Is the stack full? No Remove two elements from the said stack: Stack elements are: 5 3 1 Top element is 5
// Click me to see the sample solution

// 21. Write a C++ program that sorts the stack (using a dynamic array) elements.
// Test Data:
// Input the size of the stack: 5
// Input some elements onto the stack:
// Stack elements are: 4 7 5 3 1
// After sorting the said stack elements:
// Stack elements are: 1 3 4 5 7
// Click me to see the sample solution

// 22. Write a C++ program that reverses the stack (using a dynamic array) elements.
// Test Data:
// Input the size of the stack: 8
// Input some elements onto the stack:
// Stack elements are: 4 7 5 3 1
// Reverse the said stack elements:
// Stack elements are: 1 3 5 7 4
// Input 2 more elements onto the said stack:
// Stack elements are: 40 70 1 3 5 7 4
// Reverse the said stack elements:
// Stack elements are: 4 7 5 3 1 70 40
// Click me to see the sample solution

// 23. Write a C++ program to find the middle element of a stack (using a dynamic array).
// Test Data:
// Input the size of the stack: 8
// Input some elements onto the stack:
// Stack elements are: 11 10 9 7 5 3 1
// Middle element = 7
// Remove one element from the said stack:
// Stack elements are: 10 9 7 5 3 1
// Middle element = 5
// Click me to see the sample solution

// 24. Write a C++ program to implement a stack using a vector with push and pop operations. Check if the stack is empty or not and find the top element of the stack.
// Test Data:
// Create a stack object:
// Is the stack empty? Yes
// Input and store (using vector) some elements onto the stack:
// Stack elements are: 1 2 3 4 5
// Top element is 5
// Remove two elements from the said stack:
// Stack elements are: 1 2 3
// Top element is 3
// Click me to see the sample solution

// 25. Write a C++ program that sorts the stack (using a vector) elements.
// Test Data:
// Create a stack object:
// Input and store (using vector) some elements onto the stack:
// Stack elements are: 1 3 2 6 5 -1 0
// Sort the stack items in ascending order:
// Stack elements are: -1 0 1 2 3 5 6
// Remove two elements from the stack:
// Stack elements are: -1 0 1 2 3
// Input three elements onto the stack:
// Stack elements are: -1 0 1 2 3 4 7 -2
// Sort the said items in ascending order:
// Stack elements are: -2 -1 0 1 2 3 4 7
// Click me to see the sample solution

// 26. Write a C++ program that reverses the stack (using a vector) elements.
// Test Data:
// Create a stack object:
// Input and store (using vector) some elements onto the stack:
// Stack elements are: 1 3 2 6 5 -1 0
// Reverse the elements of the said stack:
// Stack elements are: 0 -1 5 6 2 3 1
// Remove two elements from the stack:
// Stack elements are: 0 -1 5 6 2
// Input three elements onto the stack:
// Stack elements are: 0 -1 5 6 2 4 7 -2
// Reverse the elements of the said stack:
// Stack elements are: -2 7 4 2 6 5 -1 0
// Click me to see the sample solution

// 27. Write a C++ program to find the middle element(s) of a stack (using a vector).
// Test Data:
// Create a stack object:
// Input and store (using vector) some elements onto the stack:
// Stack elements are: 1 3 2 6 5 -1
// Middle element(s) of the said stack elements:
// 2 6
// Input one more element:
// Stack elements are: 1 3 2 6 5 -1 0
// Middle element(s) of the said stack elements:
// 6
// Click me to see the sample solution

// 28. Write a C++ program to implement a stack using a Deque with push and pop operations. Check if the stack is empty or not and find the top element of the stack.
// Test Data:
// Initialize a stack using deque:
// Is the stack empty? Yes
// Input some elements onto the stack:
// Deque elements are: 1 5 3 4 2
// Top element is 2
// Remove two elements from the stack:
// Deque elements are: 1 5 3
// Top element is 3
// Input two more elements onto the stack:
// Deque elements are: 1 5 3 8 9
// Top element is 9
// Click me to see the sample solution

// 29. Write a C++ program that sorts the stack (using a Deque) elements.
// Test Data:
// Create a stack object:
// Input and store (using Deque) some elements onto the stack:
// Stack elements are: 1 3 2 6 5 -1 0
// Sort the stack items in ascending order:
// Stack elements are: -1 0 1 2 3 5 6
// Remove two elements from the stack:
// Stack elements are: -1 0 1 2 3
// Input three elements onto the stack:
// Stack elements are: -1 0 1 2 3 4 7 -2
// Sort the said items in ascending order:
// Stack elements are: -2 -1 0 1 2 3 4 7
// Click me to see the sample solution

// 30. Write a C++ program that reverse the stack (using a Deque) elements.
// Test Data:
// Create a stack object:
// Input and store (using Deque) some elements onto the stack:
// Stack elements are: 1 3 2 6 5 -1 0
// Reverse the stack items in ascending order:
// Stack elements are: 0 -1 5 6 2 3 1
// Remove two elements from the stack:
// Stack elements are: 0 -1 5 6 2
// Input three elements onto the stack:
// Stack elements are: 0 -1 5 6 2 4 7 -2
// Reverse the said items in ascending order:
// Stack elements are: -2 7 4 2 6 5 -1 0
// Click me to see the sample solution



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//1. Write a C++ program to implement a queue using an array with enqueue and dequeue operations. 
// Find the top element of the stack and check if the stack is empty, full or not.
// 2. Write a C++ program to reverse the elements of a queue.
// 3. Write a C++ program to sort the elements of a queue.
// 4. Write a C++ program to find the sum of all elements of a queue.
// 5. Write a C++ program to find the average of all elements of a queue.
// 6. Write a C++ program to find the median of all elements of a queue.
// 7. Write a C++ program to find the mode of all elements of a queue.
// 8. Write a C++ program to find the mean, variance and standard deviation of all elements of a queue.
// 9. Write a C++ program to find the maximum element of a queue.
// 10. Write a C++ program to find the minimum element of a queue.
// 11. Write a C++ program to find the second highest element of a queue.
// 12. Write a C++ program to find the second lowest element of a queue.
// 13. Write a C++ program to remove a given element from a queue.
// 14. Write a C++ program to remove all the elements from a queue.
// 15. Write a C++ program to remove all even elements from a queue.
// 16. Write a C++ program to remove all odd elements from a queue.
// 17. Write a C++ program to remove all duplicate elements from a queue.
// 18. Write a C++ program to remove all elements greater than a number from a queue.
// 19. Write a C++ program to concatenate two queues.
// 20. Write a C++ program to copy one queue to another.
// 21. Write a C++ program to find the top and bottom elements of a queue.
// 22. Write a C++ program to get the Nth element from the bottom of a queue.
// 23. Write a C++ program to get the Nth element from the top of a queue.
// 24. Write a C++ program to find the position of an element in a queue.
// 25. Write a C++ program to check if two queues are equal.
// 26. Write a C++ program to find the intersection of two queues.
// 27. Write a C++ program to find the union of two queues.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Design a method for keeping two stacks within a single linear array stack[max_size] , so that neither stack
// overflows until all of memory is used and an entire stack is never shifted to a different location within the
// array. Write C++ routines, push1, push2, pop1, pop2 to manipulate the two stacks.
// Q2:
// The FAST PARKING GARAGE contains a single lane that can hold up to 10 cars. There is only a single
// entrance/exit to the garage at one end of the lane. If a customer arrives to pickup a car that is not nearest
// to the exit, all cars blocking the path are moved out, the customer’s car is driven out, and the other cars
// are restored in the same order that they were in originally. Write a program that processes a group of
// input lines. Each input line contains an ‘A’ for arrival and ‘D’ for departure, and a license plate number.
// Cars are assumed to arrive and depart in the order specified by the input. The program should print a
// message whenever a car arrives and departs. When a car arrives, the message should specify whether or
// not there is a room for the car in the garage. If there is no room, the car leaves without entering the
// garage. When a car departs, the message should include the number of times that the car was moved out
// of the garage, to allow other cars to depart.
// a. Write a program in C++ that accepts a postfix expression containing single-letter operands and the
// operators +, -, * , and / , and prints a sequence of the instructions to evaluate the expression and leave
// the result in the register.
// Use variables of the form AUXn as temporary variables. For example, using the post expression
// ABC*+DE-/ should print the following:

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Double ended queue, deque (usually pronounced like "deck") is an irregular acronym of double-
// ended queue. Double-ended queues are sequence containers with dynamic sizes that can be expanded or

// contracted on both ends (either its right or its left). Call two ends of the deque as left and right. How can a
// deque be represented as a data structure in C++.
// a. Write four C++ routines

// remLeft, remRight, insertLeft, insertRight

// to remove and insert elements to the right and left ends of the deque. Make sure that the routines work
// properly for the empty deque and underflow and overflow conditions are properly implemented.
// b. cDefine an input-restricted deque as a deque for which only the operations remLeft, remRight, and
// insertRight are valid.
// c. Define an output-restricted deque as a deque for which only the operations remLeft, insertLeft, and
// insertRight are valid.


//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
