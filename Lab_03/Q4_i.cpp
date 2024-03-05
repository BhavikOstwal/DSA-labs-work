#include<iostream>
using namespace std;


void Matrix_Mult(int A1[][2], int A2[][3], int r1, int c1, int c2)
{
    int A1A2[r1][c2];
    for (int k = 0; k < r1; k++)
    {
        for (int j = 0; j < c2; j++)
        {
            A1A2[k][j]=0;
            for (int i = 0; i < c1; i++)
            {
                A1A2[k][j] += A1[k][i]*A2[i][j];
            }
        }
    }
    

    //printing matrix
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << A1A2[i][j] << " ";
        }
        cout<< endl;
    }
}


int main() {

    int A1[3][2] = { {0, 1}, {2, 0}, {3, 3} };
    int A2[2][3] = { {1, 1, 0}, {2, 0, 0} };
    
    // int A1[3][2] = { {1, 1}, {2, 2}, {3, 3} };
    // int A2[2][4] = { {1, 1, 1,1}, {2, 2, 2,1} };
    
    // int A1[5][6] =
    // {
    //     {0 , 0 , 0 , 0 , 9, 0 }, 
    //     {0 , 8 , 0 , 0 , 0, 0 },
    //     {4 , 0 , 0 , 2 , 0, 0 },
    //     {0 , 0 , 0 , 0 , 0, 5 },
    //     {0 , 0 , 2 , 0 , 0, 0 }
    // };

    // int A2[6][6] =
    // {
    //     {0 , 0 , 0 , 0 , 1, 0 },
    //     {0 , 0 , 0 , 0 , 1, 0 },
    //     {0 , 5 , 0 , 2 , 0, 0 },
    //     {0 , 0 , 1 , 0 , 0, 5 },
    //     {2 , 8 , 0 , 0 , 1, 0 },
    //     {0 , 0 , 4 , 0 , 0, 0 }
    // };

    Matrix_Mult(A1, A2, 3,2,3);
    return 0;
}

