#include<iostream>
#include<limits>
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

        if (A[index]<A[right] && (right<=heap_size-1))
        {
            largest = right;
        }

        if(A[largest]<A[left] && (left<=heap_size-1))
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
        for (int i = (heap_size/2)-1; i >=0; i--)
        {
            Max_Heapify(A, i);
        }
    }

    void HeapSort(int A[])
    {
        Build_max_heap(A);
        for (int i = length-1; i >=1; i--)
        {
            swap(A[0], A[i]);
            heap_size--;
            Max_Heapify(A,0);
        }
    }

    int Extract_Max(int A[])
    {
        if (heap_size <= 0)
        {
            cout << "Heap underflow!" << endl;
            return -1;
        }
        int max = A[0];
        A[0] = A[heap_size - 1];
        heap_size--;
        Max_Heapify(A, 0);
        return max;
    }

    void Print_Max(int A[])
    {
        cout << ((heap_size<1) ? "Heap Underflow" : "Max value = " + to_string(A[0]));
        cout << endl;   
    }

    void Increase_key(int A[], int index, int new_key)
    {
        if (A[index]>=new_key)
        {
            cout << "New key is smaller that " << endl;
        }
        else
        {
            A[index] = new_key;
            int i = index;
            while (i>0 && A[Parent(i)]<A[i])
            {
                swap(A[Parent(i)], A[i]);
                i = Parent(i);
            }
        }
    }

    void Insert_key(int A[], int new_key)
    {
        heap_size++;
        A[heap_size-1] = numeric_limits<int>::min();
        Increase_key(A, heap_size-1, new_key);
    }
};

int main() {
    // int A[] = {16,4,10,14,7,9,3,2,8,1};
    int n = 16;
    int arr[] = {4,1,3,2,16,9,10,14,8,7};
    // int arr[] = {4,1,3};
    int size = sizeof(arr)/ sizeof(int);
    // int size = n;

    Heap myHeap(size);
    myHeap.Build_max_heap(arr);

    myHeap.print_arr(arr);
    myHeap.print_heap(arr);
    myHeap.Print_Max(arr);
    cout << myHeap.Extract_Max(arr) << endl;
    myHeap.print_arr(arr);
    myHeap.print_heap(arr);

    // myHeap.Increase_key(arr, 3, 15);
    // myHeap.print_heap(arr);

    myHeap.Insert_key(arr, 11);
    myHeap.print_heap(arr);

    // cout << size << endl;

    
    return 0;
}