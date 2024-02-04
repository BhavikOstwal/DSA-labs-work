#include<iostream>
using namespace std;


int main() {
    int A[] = {3,1,2,34,2,1,4,6,8,9,78,4};
    for (int i = 1; i < sizeof(A)/sizeof(int); i++)
    {
        int key = A[i];
        int j = i-1;
        while ((j>=0)&&(key<A[j]))
        {
            A[j+1]=A[j];
            j-=1;
        }
        A[j+1] = key;
    }

    for (int i = 0; i < sizeof(A)/sizeof(int); i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}