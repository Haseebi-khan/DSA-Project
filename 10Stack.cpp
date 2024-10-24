#include <iostream> 
#include <stack>
using namespace std;
int main() {
    stack<int> stack;
    stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack.push(22);
    stack.push(24);
    stack.push(25);
    int num=0;
      stack.push(num);
    stack.pop();
    stack.pop();
      stack.pop();
  
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }
}
// Code Explanation:

// Include the iostream header file or <iostream> in our code to use its functions.
// Include the stack header file in our code to use its functions if already included <iostream> then no need of stack header file because it has already inbuilt function in it.
// Include the std namespace in our code to use its classes without calling it.
// Call the main() function. The program logic should be added within this function.
// Create a stack to store integer values.
// Use the push() function to insert the value 21 into the stack.
// Use the push() function to insert the value 22 into the stack.
// Use the push() function to insert the value 24 into the stack.
// Use the push() function to insert the value 25 into the stack.
// Use a integer variable “num” to enter a variable value. Here its value is 0, but we can assign any integer value using cin >> num.
// Use the push() function to insert the value of “num” variable.
// Use the pop() function to remove the top element from the stack, that is, 25. The top element now becomes 24.
// Use the pop() function to remove the top element from the stack, that is, 24. The top element now becomes 22.
// Use a while loop and empty() function to check whether the stack is NOT empty. The ! is the NOT operator. So, when stack is not empty then empty() function will return false and NOT operator convert it in true and the while loop keep running. But, when the stack become empty then empty() function will return true and NOT operator will make it false and the loop come to an end.
// Printing the current contents of the stack on the console.
// Call the pop() function on the stack.
// End of the body of the while loop.
// End of the main() function body.