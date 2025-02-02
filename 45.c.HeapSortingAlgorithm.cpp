#include <iostream>

using namespace std;

#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

class MinHeap
{
private:
    int *harr;
    int capacity;

public:
    int size;

    MinHeap(int cap) : capacity(cap), size(0)
    {
        harr = new int[cap];
    }
    void linearSearch(int Value)
    {
        bool found = false;
        for (int i = 0; i < size; i++)
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
        for (int i = 0; i < size; i++)
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
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    int height(int i)
    {
        return ceil(log2(size + 1)) - 1;
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap OverFlow.\n";
            return;
        }

        size++;
        int i = size - 1;
        harr[i] = value;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }
    void minHeapify(int i)
    {
        int l = left(i), r = right(i), smallest = i;
        if (i < size && harr[l] < harr[i])
        {
            smallest = l;
        }
        if (r < size && harr[r] < harr[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            minHeapify(smallest);
        }
    }
    int extractMin()
    {
        if (size <= 0)
        {
            cout << "Heap is Empty.\n";
            return INT_MAX;
        }
        else if (size == 1)
        {
            size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[size - 1];
        size--;
        minHeapify(0);
        return root;
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    void decreaseKey(int i, int newValue)
    {
        harr[i] = newValue;
        while (i != 0 && harr[parent(i) > harr[i]])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
    int getMini(int i)
    {
        return harr[0];
    }
    int getMax(int i)
    {
        return harr[size - 1];
    }

    // void HeapSoting()
    // {
    //     int temp[capacity];
    //     for (int j = 0; j < capacity; j++)
    //     {
    //         temp[j] = extractMin();
    //         cout << temp[j];
    //     }
    // }

    // MinHeap::HeapSorting() corrected implementation
    void HeapSorting()
    {
        int *temp = new int[size]; // Use dynamic array
        int originalSize = size;   // Preserve original size

        for (int j = 0; j < originalSize; j++)
        {
            temp[j] = extractMin();
            cout << temp[j] << " ";
        }

        delete[] temp; // Free memory
    }
};

int main()
{
    MinHeap heap(10);

    heap.insert(7);
    heap.insert(4);
    heap.insert(3);
    heap.insert(9);
    heap.insert(8);
    heap.printArry();
    cout << "\n\n";

    for (int i = 10 / 5 - 1; i >= 0; i--)
    {
        heap.minHeapify(i);
    }

    heap.HeapSorting();

    cout << endl;
    return 0;
}

// #include <iostream>
// #include "45.a.MinHeapDataSture.h"

// using namespace std;

// int main()
// {
//     MinHeap heap(10);

//     heap.insert(7);
//     heap.insert(4);
//     heap.insert(3);
//     heap.insert(9);
//     heap.insert(8);

//     cout << "Initial Heap: ";
//     heap.printArry();

//     // Build heap correctly
//     for (int i = (heap.size / 2) - 1; i >= 0; i--)
//     {
//         heap.minHeapify(i);
//     }

//     cout << "After Heapify: ";
//     heap.printArry(); // Output: 3 4 7 9 8

//     cout << "Sorted Order: ";
//     heap.HeapSorting(); // Output: 3 4 7 8 9

//     cout << "\n";

//     return 0;
// }