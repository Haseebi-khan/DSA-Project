#include <iostream>
#include <math.h>
#include <limits.h>
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
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    int height(int i)
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

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }
    void minHeapify(int i)
    {
        int l = left(i), r = right(i), smallest = i;
        if (i < heap_size && harr[l] < harr[i])
        {
            smallest = l;
        }
        if (r < heap_size && harr[r] < harr[smallest])
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
        if (heap_size <= 0)
        {
            cout << "Heap is Empty.\n";
            return INT_MAX;
        }
        else if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
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
        return harr[heap_size - 1];
    }
};

int main()
{
    MinHeap heapArray(5);

    cout << endl;
    return 0;
}