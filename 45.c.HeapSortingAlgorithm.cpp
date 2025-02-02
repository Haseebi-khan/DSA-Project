#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class MinHeap
{
private:
public:
    int *harr;
    int capacity;
    int size;

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }

    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    MinHeap(int cap) : capacity(cap), size(0)
    {
        harr = new int[cap];
    }

    void unSortInsert(int value)
    {
        if (size >= capacity)
        {
            cout << "Heap Overflow\n";
            return;
        }
        harr[size] = value;
        size++;
    }

    void minHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && harr[l] < harr[smallest])
            smallest = l;
        if (r < size && harr[r] < harr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            minHeapify(smallest);
        }
    }

    void HeapSorting()
    {
        int originalSize = size;
        int *temp = new int[originalSize];

        for (int j = 0; j < originalSize; j++)
        {
            temp[j] = extractMin();
            cout << temp[j] << " ";
        }

        delete[] temp;
    }

    int extractMin()
    {
        if (size <= 0)
            return INT_MAX;
        int root = harr[0];
        harr[0] = harr[size - 1];
        size--;
        minHeapify(0);
        return root;
    }

    void printArry()
    {
        for (int i = 0; i < size; i++)
            cout << harr[i] << " ";
        cout << "\n";
    }

    // Fix decreaseKey syntax
    void decreaseKey(int i, int newValue)
    {
        harr[i] = newValue;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
};

int main()
{
    MinHeap heap(10);

    heap.unSortInsert(7);
    heap.unSortInsert(4);
    heap.unSortInsert(3);
    heap.unSortInsert(9);
    heap.unSortInsert(8);

    cout << "Initial Array: ";
    heap.printArry();

    for (int i = (heap.size / 2) - 1; i >= 0; i--)
    {
        heap.minHeapify(i);
    }

    cout << "After Heapify: ";
    heap.printArry();

    cout << "Sorted Order: ";
    heap.HeapSorting();

    cout << "\n\n\n";
    return 0;
}