#include <iostream>
using namespace std;

class MinHeap
{
private:
    int *harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int cap) : capacity(cap), heap_size(0)
    {
        harr = new int[cap];
    }
    void linearSearch(int Value)
    {
        bool found = false;
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == Value)
            {
                found = true;
                cout << "Value Found!\n";
                return;
            }
        }

        cout << "Value Not Found!\n";
    }
    void printArry()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << harr[i] << " ";
        }
    }

    int parent(int i)
    {
        return harr[(i - 1) / 2];
    }

    int left(int i)
    {
        return harr[(2 * i) + 1];
    }
    int right(int i)
    {
        return harr[(2 * i) + 2];
    }

    void insert(int value)
    {
        if (heap_size == capacity)
        {
            cout << "Heap OverFlow.\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = value;

        // while (i != 0 && harr[parent(i)] > harr[i])
        // {
        //     // 
        // }
        
    }

    int getMini(int i);
    int getMax(int i);
    int extractMin(int i);
    void deleteKey(int i, int newValue);
    void minHeapify(int i);
    int height(int i);
};

int main()
{
    MinHeap heapArray(5);

    cout << endl;
    return 0;
}