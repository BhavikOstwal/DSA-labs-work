#include<iostream>
using namespace std;

void Counting_Sort(int A[], int B[], int k, int size)
{
    int C[k+1];
    for (int i = 0; i < k+1; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < size ; i++)
    {
        C[A[i]] += 1;
    }
    for (int i = 1; i < k+1; i++)
    {
        C[i] +=C[i-1];
    }
    // for (int i = 0; i < size; i++) --> If used this line, then this algorithm won't be called "STABLE"
    for (int i = size-1; i >=0; i--) // --> Instead used this line    
    {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}


int main() {
    int A[] = {5, 2, 9, 1, 7, 3, 6, 4, 8};
    int size = sizeof(A)/sizeof(int);
    int B[size];
    Counting_Sort(A,B,9,size);

    //printing
    for (int i = 0; i < size; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    
    return 0;
}