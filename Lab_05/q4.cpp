#include<iostream>
#include<limits>
using namespace std;

class Heap
{
    int heap_size;
    int length;

public:
    Heap(int sizeofarr)
    {
        heap_size = sizeofarr;
        length = sizeofarr;
    }

    int Parent(int index)
    {
        return (index-1)/2;
    }

    int Left(int index)
    {
        return 2*index+1;
    }

    int Right(int index)
    {
        return 2*index+2;
    }

    void print_arr(int A[])
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    void print_heap(int A[])
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    void Min_Heapify(int A[], int index)
    {
        int left = Left(index);
        int right = Right(index);
        int smallest = index;
        if (A[index]>A[left] && left<=heap_size-1)
        {
            smallest = left;
        }
        else if (A[index]>A[right] && right<=heap_size-1)
        {
            smallest = right;
        }
        if (smallest!=index)
        {
            swap(A[smallest], A[index]);
            Min_Heapify(A, smallest);
        }
    }
};

int main()
{
    int arr[] = {4,1,3,2,16,9,10,14,8,7};
    int size = sizeof(arr)/sizeof(int);
    Heap myHeap(size);
    myHeap.Min_Heapify(arr, 0);
    myHeap.print_heap(arr);
    return 0;
}