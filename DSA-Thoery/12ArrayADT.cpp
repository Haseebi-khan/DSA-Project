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