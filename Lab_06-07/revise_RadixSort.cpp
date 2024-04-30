#include<iostream>
using namespace std;

int get_max(int A[], int size)
{
    int max = A[0];
    for (int i = 0; i < size; i++)
    {
        if (max<A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void CountingSort(int A[], int size, int exp)
{
    int output[size];
    int C[10] = {0};

    for (int i = 0; i < size; i++)
    {
        C[int(A[i]/exp)%10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        C[i] += C[i-1];
    }

    for (int i = size-1; i >=0 ; i--)
    {
        output[C[int(A[i]/exp)%10]-1] = A[i];
        C[int(A[i]/exp)%10]--;
    }
    
    //copy
    for (int i = 0; i < size; i++)
    {
        A[i] = output[i];
    }
}

void RadixSort(int A[], int size)
{
    int max = get_max(A,size);
    for (int exp = 1; max/exp > 1; exp*=10)
    {
        CountingSort(A,size,exp);
    }

    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}


int main() {
    int A[] = {5, 2, 9, 1, 7, 3, 6, 4, 8};
    int size = sizeof(A)/sizeof(int);
    RadixSort(A, size);
    return 0;
}