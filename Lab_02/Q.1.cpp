#include<iostream>
using namespace std;


int main() {
    int A[] = {5,2,4,6,1,3};
    // int swaps=0, comparisons=0;
    for (int i = 1; i < sizeof(A)/sizeof(int); i++)
    {
        int key = A[i];
        int j = i-1;
        while ((j>=0)&&(key<A[j]))
        {
            A[j+1]=A[j];
            // comparisons++;
            // swaps++;
            j-=1;
        }
        // if (j==i-1){
        //     comparisons++;
        // }
        A[j+1] = key;
    }

    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
    {
        cout<<A[i]<<" ";
    }
    // cout<<"\nSwaps: "<<swaps;
    // cout<<"\nComparisons: "<<comparisons<<endl;
    return 0;
}