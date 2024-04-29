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
        for (int i = (heap_size/2); i >=0; i--)
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
            print_arr(A);
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
            cout << "smaller" << endl;
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
};

int main() {
    
    return 0;
}