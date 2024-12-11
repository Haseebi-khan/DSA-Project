#include <iostream>
#include <malloc.h>
using namespace std;

class myArray
{
private:
    int totalSize;
    int usedSize;
    int *ptr;

public:
    myArray(int t_size, int u_size)
    {
        this->totalSize = t_size;
        this->usedSize = u_size;
        this->ptr = (int *)malloc(t_size * sizeof(int));
    }
    void setValue()
    {
        for (int i = 0; i < usedSize; i++)
        {
            ptr[i] = i + 1;
        }
    }
    void show()
    {
        for (int i = 0; i < usedSize; i++)
        {
            cout << (ptr)[i] << " ";
        }
    }
};

int main()
{
    myArray marks(15, 5);
    marks.setValue();
    marks.show();

    cout << endl;
    return 0;
}

///////////////////////////////////////////////////////////////////////////


// #include <iostream>
// #include <malloc.h>
// using namespace std;

// class myArray
// {
// private:
//     int totalSize;
//     int usedSize;
//     int *ptr;

// public:
//     myArray(int t_size) : usedSize(0)
//     {
//         this->totalSize = t_size;
//         this->ptr = (int *)malloc(t_size * sizeof(int));
//     }

//     void Push(int value)
//     {
//         if (usedSize == totalSize)
//         {
//             cout << "Value: " << value << " is not pushed." << endl;
//             cout << "ARRAY is Full.\n";
//         }
//         else
//         {
//             ptr[usedSize++] = value;
//         }
//     }
//     void top()
//     {
//         if (usedSize < 0)
//         {
//             cout << "Empty.\n";
//         }
//         else
//         {
//             cout << ptr[usedSize - 1] << endl;
//         }
//     }
//     void show()
//     {
//         if (usedSize < 0)
//         {
//             cout << "Empty.\n";
//             return;
//         }

//         for (int i = 0; i < usedSize; i++)
//         {
//             cout << (ptr)[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     myArray marks(15);
//     marks.Push(45);
//     marks.Push(3);
//     marks.Push(34);
//     marks.Push(34);
//     marks.Push(43);
//     marks.show();
//     marks.top();
//     marks.show();

//     cout << endl;
//     return 0;
// }