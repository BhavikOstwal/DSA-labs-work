#include<iostream>
using namespace std;

// template <typename my_dtype>
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

    void Max_Heapify(int A[], int index)
    {
        int left = Left(index);
        int right = Right(index);
        int largest = index;

        if (A[index]<A[right] && (right<=heap_size))
        {
            largest = right;
        }
        if(A[largest]<A[left] && (left<=heap_size))
        {
            largest = left;
        }

        if (largest!=index)
        {
            swap(A[index], A[largest]);
            // print_arr(A);
            Max_Heapify(A, largest);
        }
    }

    void Build_max_heap(int A[])
    {
        heap_size = length;
        for (int i = heap_size/2 - 1; i >=0; i--)
        {
            Max_Heapify(A, i);
        }
    }

    void HeapSort(int A[])
    {
        Build_max_heap(A);
        for (int i = length; i >=2; i--)
        {
            swap(A[0], A[i]);
            heap_size--;
            Max_Heapify(A,0);
        }
    }

    int extractMax(int A[])
    {
        if (heap_size <= 0)
        {
            cout << "Heap underflow!" << endl;
            return -1;
        }
        int maxVal = A[0];
        A[0] = A[heap_size - 1];
        heap_size--;
        Max_Heapify(A, 0);
        return maxVal;
    }
};

int main() {
    // int A[] = {16,4,10,14,7,9,3,2,8,1};
    int A[] = {4,1,3,2,16,9,10,14,8,7};
    int size = sizeof(A)/sizeof(int);
    Heap myHeap(size);
    // myHeap.Max_Heapify(A,1);
    myHeap.HeapSort(A);
    myHeap.print_arr(A);


    return 0;
}