#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

class MaxHeap
{
private:
    int *harr;
    int capacity;
    int heap_size;

public:
    MaxHeap(int cap) : capacity(cap), heap_size(0)
    {
        harr = new int[cap];
    }

    void linearSearch(int Value)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == Value)
            {
                cout << "Value Found!\n";
                return;
            }
        }
        cout << "Value Not Found!\n";
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << harr[i] << " ";
        }
        cout << endl;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i) + 1;
    }

    int right(int i)
    {
        return (2 * i) + 2;
    }

    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
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

        while (i != 0 && harr[parent(i)] < harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

    void maxHeapify(int i)
    {
        int l = left(i), r = right(i), largest = i;

        if (l < heap_size && harr[l] > harr[i])
        {
            largest = l;
        }
        if (r < heap_size && harr[r] > harr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(harr[i], harr[largest]);
            maxHeapify(largest);
        }
    }

    int extractMax()
    {
        if (heap_size <= 0)
        {
            cout << "Heap is Empty.\n";
            return INT_MIN;
        }
        else if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        maxHeapify(0);
        return root;
    }

    void deleteKey(int i)
    {
        increaseKey(i, INT_MAX);
        extractMax();
    }

    void increaseKey(int i, int newValue)
    {
        harr[i] = newValue;
        while (i != 0 && harr[parent(i)] < harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    int getMax()
    {
        return (heap_size > 0) ? harr[0] : INT_MIN;
    }
};

int main()
{
    MaxHeap heapArray(5);

    heapArray.insert(10);
    heapArray.insert(20);
    heapArray.insert(30);
    heapArray.insert(5);
    heapArray.insert(25);

    cout << "Max Heap elements: ";
    heapArray.printArray();

    cout << "Extracted max: " << heapArray.extractMax() << endl;

    cout << "Heap after extraction: ";
    heapArray.printArray();

    return 0;
}
