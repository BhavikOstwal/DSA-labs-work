#include<iostream>
#include<vector>
using namespace std;

const int columns =5;

class DiGraph
{
    int (*Adj)[columns];
    int vertex_num;
public:
    DiGraph(int Mat[][columns] , int V)
    {
        Adj = Mat;
        vertex_num = V;
    }

    void AllZero()
    {
        for (int i = 0; i < vertex_num; i++)
        {
            for (int j = 0; j < vertex_num; j++)
            {
                Adj[i][j] = 0;
            }
        }
    }

    void AddEdge(int u, int v)
    {
        Adj[u][v] = 1;
        Adj[v][u] = 1;
    }

    void Print_AdjMatrix()
    {
        for (int i = 0; i < vertex_num; i++)
        {
            for (int j = 0; j < vertex_num; j++)
            {
                if (Adj[i][j]!=1)
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << Adj[i][j] << " ";
                }
            }
            cout << endl;
        }
        
    }


};


int main()
{
    int V = columns;
    int Adj[5][5];
    DiGraph myGraph1(Adj, V);
    myGraph1.AllZero();
    myGraph1.AddEdge(0, 3);
    myGraph1.AddEdge(0, 1);
    myGraph1.AddEdge(0, 4);
    myGraph1.AddEdge(1, 2);
    myGraph1.AddEdge(1, 1);
    myGraph1.AddEdge(3, 4);

    myGraph1.Print_AdjMatrix();
    return 0;
}