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

    void printArry()
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

    int height() { return ceil(log2(heap_size + 1)) - 1; }

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
        if (l < heap_size && harr[l] < harr[i])
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

    void decreaseKey(int i, int newValue)
    {
        harr[i] = newValue;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    int getMini()
    {
        return harr[0];
    }

    int getMax()
    {
        int maxVal = harr[heap_size / 2];
        for (int i = (heap_size / 2) + 1; i < heap_size; i++)
        {
            if (harr[i] > maxVal)
            {
                maxVal = harr[i];
            }
        }
        return maxVal;
    }
    // Prints the elements of the heap array in heap order (level order)
    void printHeapOrder()
    {
        cout << "Heap in heap order (linearly): ";
        for (int i = 0; i < heap_size; i++)
            cout << harr[i] << " ";
        cout << endl;
    }
};
int main()
{
    MinHeap heap(10);
    heap.insert(564);
    heap.insert(2);
    heap.insert(34);
    heap.insert(4);
    heap.insert(6);
    heap.insert(3);
    heap.insert(78);
    heap.insert(98);
    cout << "Minimum element in the heap: " << heap.getMini() << endl;
    heap.printArry();
    cout << "\n";
    heap.printHeapOrder();
    return 0;
}
