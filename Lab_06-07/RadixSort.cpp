#include <iostream>
using namespace std;

int get_max(int A[], int size)
{
    int a = A[0];
    for (int i = 0; i < size; i++)
    {
        if (A[i] > a)
        {
            a = A[i];
        }
    }
    return a;
}
void Counting_Sort(int A[], int size, int exp)
{
    int output[size];
    int C[10] = {0};

    for (int i = 0; i < size; i++)
    {
        C[int(A[i]/exp) % 10] += 1;
    }
    for (int i = 1; i < 10; i++)
    {
        C[i] += C[i - 1];
    }
    // for (int i = 0; i < size; i++) --> If used this line, then this algorithm won't be called "STABLE"
    for (int i = size - 1; i >= 0; i--) // --> Instead used this line
    {
        output[C[int(A[i]/exp) % 10] - 1] = A[i];
        C[int(A[i]/exp) % 10]--;
    }

    //copy
    for (int i = 0; i < size; i++)
    {
        A[i] = output[i];
    }
}

void RadixSort(int A[], int size)
{
    int a = get_max(A, size);
    // int tmparr[] = {};
    for (int exp = 1; a / exp > 1; exp *= 10)
    {
        Counting_Sort(A, size, exp);
    }

    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    
}


int main()
{
    int A[] = {5, 2, 9, 1, 7, 3, 6, 4, 8};
    int size = sizeof(A)/sizeof(int);
    RadixSort(A, size);
    return 0;
}