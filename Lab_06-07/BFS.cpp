#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Vertex
{
public:
    int data;
    char color;
    int dist;
    Vertex* pred;

    Vertex(int mydata)
    {
        data = mydata;
        color = 'w'; // Initialize color to white
        dist = INFINITY;
        pred = nullptr;
    }
};

class DiGraph
{
    vector<int>* Adj;
    int vertex_num;

public:
    DiGraph(vector<int>* ADJ, int V)
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
        for (int i = 0; i < vertex_num; i++)
        {
            cout << i << " : ";
            for (auto& j : Adj[i])
            {
                cout << "->" << j;
            }
            cout << "->X\n";
        }
    }

    int OutDegree(int u)
    {
        return Adj[u].size();
    }

    int InDegree(int u)
    {
        int indegrees = 0;
        for (int i = 0; i < vertex_num; i++)
        {
            for (int j = 0; j < Adj[i].size(); j++)
            {
                if (Adj[i][j] == u)
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

    void BFS(int s)
    {
        // Initialize all vertices as I don't have one
        vector<Vertex> vertices;
        for (int i = 0; i < vertex_num; ++i)
        {
            vertices.push_back(Vertex(i));
        }

        // Real algo starts
        vertices[s].color = 'g'; // Mark source vertex as gray
        vertices[s].dist = 0;
        vertices[s].pred = nullptr;

        queue<int> Q;
        Q.push(s);

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for (auto v : Adj[u])
            {
                if (vertices[v].color == 'w')
                {
                    vertices[v].color = 'g';
                    vertices[v].dist = vertices[u].dist + 1;
                    vertices[v].pred = &vertices[u];
                    Q.push(v);
                }
            }
            vertices[u].color = 'b'; // Mark vertex as black when finished processing
        }

        // Print distances from source and predecessor of each vertex
        for (int i = 0; i < vertex_num; ++i)
        {
            cout << "Vertex: " << i << ", Distance: " << vertices[i].dist;
            if (vertices[i].pred != nullptr)
            {
                cout << ", Predecessor: " << vertices[i].pred->data;
            }
            cout << endl;
        }
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
    // cout << myGraph.OutDegree(3) << endl;

    cout << "BFS Traversal:" << endl;
    myGraph.BFS(0);

    return 0;
}
