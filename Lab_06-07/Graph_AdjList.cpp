#include<iostream>
#include<vector>
using namespace std;


class UnGraph
{
    vector<int>* Adj;
    int degrees = 0;
public:
    UnGraph(vector<int>* ADJ)
    {
        Adj = ADJ;
    }

    void AddEdge(int u, int v)
    {
        if (u != v)
        {
            Adj[u].push_back(v);
            Adj[v].push_back(u);
            degrees+=2;
        }
        else
        {
            cout << "Self Loops cannot be defined in an undirected graph : " << u << "->" << v << endl;
        }
    }

    void Print_AdjList(int vertex_num)
    {
        for(int i =0 ; i< vertex_num ; i++)
        {
            cout << i << " : ";
            for(auto& j : Adj[i])
            {
                cout << "->" << j;
            }
            cout << "->X\n";
        }
    }

    // int Degree(int u)
    // {
    //     // can easily write (afterwards)
    // }
};

class DiGraph
{
    vector<int>* Adj;
    int vertex_num;
public:
    DiGraph(vector<int>* ADJ , int V)
    {
        Adj = ADJ;
        vertex_num = V;
    }

    void AddEdge(int u, int v)
    {
        Adj[u].push_back(v);
    }

    void Print_AdjList()
    {
        for(int i =0 ; i< vertex_num ; i++)
        {
            cout << i << " : ";
            for(auto& j : Adj[i])
            {
                cout << "->" << j;
            }
            cout << "->X\n";
        }
    }

    int OutDegree(int u)
    {
        return end(Adj[u]) - begin(Adj[u]);
    }
 
    int InDegree(int u)
    {
        int indegrees = 0;
        for (int i = 0; i < vertex_num; i++)
        {
            for (int j = 0; j < end(Adj[i]) - begin(Adj[i]); j++)
            {
                if (Adj[i][j]==u)
                {
                    indegrees++;
                }
            }
        }
        return indegrees;
    }

    int Degree(int u)
    {
        return InDegree(u) + OutDegree(u);
    }
};


int main()
{
    int V = 5;
    vector<int> Adj1[V];

    DiGraph myGraph(Adj1, V);
    myGraph.AddEdge(0, 3);
    myGraph.AddEdge(0, 1);
    myGraph.AddEdge(0, 4);
    myGraph.AddEdge(1, 2);
    myGraph.AddEdge(1, 1);
    myGraph.AddEdge(3, 4);
    myGraph.Print_AdjList();
    cout << myGraph.OutDegree(3) << endl;
    cout << myGraph.InDegree(3) << endl;
    cout << myGraph.Degree(1) << endl;

    cout << endl;
    vector<int> Adj2[V];
    UnGraph myGraph2(Adj2);
    myGraph2.AddEdge(0, 3);
    myGraph2.AddEdge(0, 1);
    myGraph2.AddEdge(0, 4);
    myGraph2.AddEdge(1, 2);
    myGraph2.AddEdge(1, 1);
    myGraph2.AddEdge(3, 4);
    myGraph2.Print_AdjList(5);
    return 0;
}