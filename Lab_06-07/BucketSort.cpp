#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<float> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        float key = vec[i];
        int j = i - 1;
        while ((j >= 0) && (key < vec[j]))
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void BucketSort(float A[], int size)
{
    vector<float> B[size];
    for (int i = 0; i < size; i++)
    {
        int index = size * A[i];
        B[index].push_back(A[i]);
    }

    for (int i = 0; i < size; i++)
    {
        InsertionSort(B[i]);
    }

    int ind = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < B[i].size(); j++)
        {
            A[ind] = B[i][j];
            ind++;
        }
    }
}

int main()
{
    float A[] = {0.45, 0.232, 0.59, 0.81, 0.7, 0.13, 0.06, 0.64, 0.998};
    int size = sizeof(A) / sizeof(int);

    BucketSort(A, size);

    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}