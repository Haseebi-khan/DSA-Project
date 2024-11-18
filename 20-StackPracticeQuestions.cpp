// Question no 1: 

// #include <iostream>
// #include <stack>
// using namespace std;

// void fun(int n) {
//     stack<int> S;  // Creates an empty stack S

//     while (n > 0) {
//         // Pushes the value of n % 2 to stack S
//         S.push(n % 2);
//         n = n / 2;
//     }

//     // Run while Stack S is not empty
//     while (!S.empty()) {
//         cout << S.top() << " ";  // Get the top element
//         S.pop();                 // Pop the top element
//     }
// }

// int main()
// {
//     fun(5);

//     cout << endl;

//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

// Question no 2: 

// declare a stack of characters
//    while ( there are more characters in the word to read )
//    {
//       read a character
//       push the character on the stack
//    }
//    while ( the stack is not empty )
//    {
//       pop a character off the stack
//       write the character to the screen
//    }

// #include <iostream>
// #include <stack>
// using namespace std;

// int main()
// {

//     stack<char> s;
//     string word = "haseeb";
//     int i = 0;
//     while (i < word.length())
//     {
//         s.push(word[i]);
//         i++;
//     }

//     i = 0;

//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }

//     cout << endl;
//     return 0;
// }


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

// Question no 3: 



