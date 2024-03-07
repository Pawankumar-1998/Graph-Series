#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    //  function for adding the edge
    void addEdge(int source, int distination)
    {
        adjList[source].push_back(distination);
        adjList[distination].push_back(source);
    }

    void printEdges()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "adjecency list of the edge no " << i << "is :" << endl;
            for (int j : adjList[i])
            {
                cout << j << "-->";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    g.printEdges();

    return 0;
}