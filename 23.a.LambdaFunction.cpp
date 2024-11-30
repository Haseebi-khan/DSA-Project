// Lambda is also knows as Inline Aynonmous Function or Aynonmous Function
// it allow you to write inline aynonmous function.
// what are Inline Aynonmous function
// in regular funtion you write code for once and put it int to a function and then whenever you need that code you just invoke that function.so no need to retype the code again
// on the other hand An Inline Function is a function that has very small defination. inline function are usually very simple and they are often use for
// small snippets code that are very simple they are not going to be used like regular functions and then they are not worth to be name
// thats the reason its called as Anonymous Function
// A lambda is an unnamed func that is not going to be reused  like regular func are
// Lambdas are often used for small snippets of code that  are so simple and not worth to be named they keep your code clean
// they are easy to use and they are fast to execute

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Explanation of the Code
// This C++ code defines a struct (a custom data type) that overloads the function call operator (operator()). The struct is then instantiated as an object named something.
// Here's a breakdown of the code:
// The struct is defined anonymously, meaning it doesn't have a name. This is allowed in C++.
// The struct overloads the function call operator (operator()) to take an int parameter x. When this operator is invoked, it will print the value of x to the console.
// An instance of the struct, named something, is created.
// The typeid operator is used to get the type information of something. The name() member function of the resulting type_info object returns a string representing the type name.
// The program prints the type name of something to the console, followed by the result of invoking the function call operator on something with an argument of x (which is not actually done in this code snippet).
// Output Explanation
// The output Z4mainEUt_ is the mangled name of the anonymous struct. This is because the typeid operator returns a type_info object that contains information about the type, including its name. The name is mangled by the compiler to include additional information, such as the scope and namespace.
// In this case, the mangled name Z4mainEUt_ can be roughly deciphered as follows:
// Z indicates that this is a type name.
// 4main indicates that this type is defined within the main function.
// E indicates that this is an anonymous struct (i.e., it has no name).
// Ut_ is a suffix added by the compiler to indicate that this is a struct type.
// Note that the exact mangling scheme used by the compiler may vary depending on the compiler and platform being used.

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <typeinfo>
// using namespace std;

// int main()
// {
//     struct
//     {
//         void operator()(int x)
//         {
//             cout << x << endl;
//         }
//     } something;

//     cout << typeid(something).name() << endl; // Display the type information

//     // [cc] Capture Claws
//     // (p) Parametter
//     // {fd} Function deffinition
//     // [](){};
//     // vector<int> v = {2, 3, 4, 7, 14, 23};
//     // the below for_each will Iterate for all value of vectors
//     // for_each(v.begin(), v.end(), something);

//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <typeinfo>
// using namespace std;

// int main()
// {
// //     struct
// //     {
// //         void operator()(int x)
// //         {
// //             cout << x << endl;
// //         }
// //     } something;

// //     cout << typeid(something).name() << endl; // Display the type information

//     // [cc] Capture Claws
//     // (p) Parametter
//     // {fd} Function deffinition
//     // [](int x){ cout << x << endl; };
//     vector<int> v = {2, 3, 4, 7, 14, 23};
//     // the below for_each will Iterate for all value of vectors
//     for_each(v.begin(), v.end(), [](int x){ cout << x << endl; });

//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <typeinfo>
// using namespace std;

// int main()
// {
// //     struct
// //     {
// //         void operator()(int x)
// //         {
// //             cout << x << endl;
// //         }
// //     } something;

// //     cout << typeid(something).name() << endl; // Display the type information

//     // [cc] Capture Claws
//     // (p) Parametter
//     // {fd} Function deffinition
//     auto something = [](int x){ cout << x << endl; };
//     vector<int> v = {2, 3, 4, 7, 14, 23};
//     // the below for_each will Iterate for all value of vectors
//     for_each(v.begin(), v.end(), something);

//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <typeinfo>
// using namespace std;

// int main()
// {
//     //     struct
//     //     {
//     //         void operator()(int x)
//     //         {
//     //             cout << x << endl;
//     //         }
//     //     } something;

//     //     cout << typeid(something).name() << endl; // Display the type information

//     // [cc] Capture Claws
//     // (p) Parametter
//     // {fd} Function deffinition
//     auto something = [](int x)
//     {
//         if (x % 2 == 0)
//         {
//             cout << x << " is Even." << endl;
//         }
//         else
//         {
//             cout << x << " is Odd." << endl;
//         }
//     };
//     vector<int> v = {2, 3, 4, 7, 14, 23};
//     // the below for_each will Iterate for all value of vectors
//     for_each(v.begin(), v.end(), something);

//     return 0;
// }

// ///////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <typeinfo>
// using namespace std;

// int main()
// {
//     //     struct
//     //     {
//     //         void operator()(int x)
//     //         {
//     //             cout << x << endl;
//     //         }
//     //     } something;

//     //     cout << typeid(something).name() << endl; // Display the type information

//     // [cc] Capture Claws
//     // (p) Parametter
//     // {fd} Function deffinition
//     int d = 7;
//     auto something = [&d](int x)
//     {
//         if (x % d == 0)
//         {
//             cout << x << " is Divisible by " << d << endl;
//         }
//         else
//         {
//             cout << x << "  not is Divisible by " << d << endl;
//             d =2;
//         }
//     };
//     vector<int> v = {2, 3, 4, 7, 14, 23};

//     // the below for_each will Iterate for all value of vectors
//     for_each(v.begin(), v.end(), something);

//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
using namespace std;

int main()
{
    //     struct
    //     {
    //         void operator()(int x)
    //         {
    //             cout << x << endl;
    //         }
    //     } something;

    //     cout << typeid(something).name() << endl; // Display the type information

    // [cc] Capture Claws
    // (p) Parametter
    // {fd} Function deffinition

    int d = 7;

    //     unction.cpp: In lambda function:
    // /home/noneo/Desktop/codes/DSA-Project/23.a.LambdaFunction.cpp:246:15: error: assignment of read-only variable ‘d’
    //   246 |             d = 2;
    //       |             ~~^~~

    auto something = [=](int x)
    {
        if (x % d == 0)
        {
            cout << x << " is Divisible by " << d << endl;
        }
        else
        {
            cout << x << "  not is Divisible by " << d << endl;
            // d = 2;
            cout << "D: " << d << endl;
        }
    };

    vector<int> v = {21, 3, 4, 7, 14, 23};

    // the below for_each will Iterate for all value of vectors
    for_each(v.begin(), v.end(), something);

    return 0;
}