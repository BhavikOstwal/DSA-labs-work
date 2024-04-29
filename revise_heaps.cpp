#include<iostream>
using namespace std;

class Heap
{
    int length;
    int heap_size;

public:
    Heap(int size)
    {
        heap_size=size;
        length = size;
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

    void Max_Heapify(int A[], int index)
    {
        int left = Left(index);
        int right = Right(index);
        int largest = index;

        if (left<=heap_size-1 && A[left]>=A[index])
        {
            largest = left;
        }

        if (right<=heap_size-1 && A[right]>=A[largest])
        {
            largest = right;
        }

        if (largest!=index)
        {
            swap(A[largest], A[index]);
            Max_Heapify(A,largest);
        }
    }
        
    void Build_Max_Heap(int A[])
    {
        heap_size = length;
        for (int i = (length-1)/2; i >=0; i--)
        {
            Max_Heapify(A,i);
        }
    }

    void Heapsort(int A[])
    {
        Build_Max_Heap(A);
        for (int i = length-1; i>0; i--)
        {
            // print_arr(A);
            swap(A[i], A[0]);
            heap_size--;
            Max_Heapify(A, 0);
        }
    }
};


int main() {
    int A[] = {4,1,3,2,16,9,10,14,8,7};
    int size = sizeof(A)/sizeof(int);
    Heap myheap(size);

    // myheap.Build_Max_Heap(A);
    myheap.Heapsort(A);

    myheap.print_arr(A);
    return 0;
}