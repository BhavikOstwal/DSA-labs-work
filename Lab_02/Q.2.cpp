#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p-1+i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[q + i];
    }

    L[n1] = 1215752191;
    R[n2] = 1215752191;
    int j = 0, k = 0;
    for (int i = p-1; i < r; i++)
    {
        if (R[k] < L[j])
        {
            A[i] = R[k];
            k++;
        }
        else
        {
            A[i] = L[j];
            j++;
        }
    }
}

void merge_sort(int A[], int p, int r){   
    if(p<r){
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int arr[8] = {3, 2, 56, 89, 4, 5, 9, 1};
    merge_sort(arr, 1, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}