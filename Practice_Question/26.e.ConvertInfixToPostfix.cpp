// Question 4:

// Convert Infix to Post-fix
// InfixToPostFix(exp)
// {
// 	crreate a stack
// 	res<-- empty
// 	for i <- 0 to len(exp)
// 		if exp[i] is operand
// 			res +=exp[i]
// 		else if exp[i] is operator
// 			while(stack != empty)
// 			{
// 				res +=stack.top;
// 				stack.pop;
// 			}
// 			stack push current operator
// 			}
// 		}
// 	while stack is not empty append the operators to res += stack.pops()
// 	return rest
// 	}
// 
#include <iostream>
using namespace std;

int main() {
    
    double num =(2+1)% 10;

    cout << num <<endl;

    
    
    cout << endl;
    return 0;
}

