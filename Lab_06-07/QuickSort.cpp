#include<iostream>
using namespace std;

int Partition(int A[], int strt_ind, int end_ind)
{
    int i = strt_ind-1;
    for (int j = strt_ind; j < end_ind; j++)
    {
        if (A[j]<=A[end_ind])
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[end_ind]);
    return i+1;
}

void QuickSort(int A[], int strt_ind, int end_ind)
{
    if (strt_ind<end_ind)
    {
        int partitioner = Partition(A,strt_ind, end_ind);
        QuickSort(A, strt_ind, partitioner-1);
        QuickSort(A, partitioner+1, end_ind);
    }
}



int main() {
    int A[] = {5, 2, 9, 1, 7, 3, 6, 4, 8};
    int size = sizeof(A)/sizeof(int);
    QuickSort(A,0,size-1);

    // printing
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}