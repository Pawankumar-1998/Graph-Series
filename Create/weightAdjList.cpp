#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    //  function for adding the edge  between the two nodes and the weigth between them (distance , cost )
    void addEdge(int source, int destination, int weight)
    {
        adjList[source].push_back(make_pair(destination, weight));
        adjList[destination].push_back(make_pair(source, weight));
    }

    // function for printing the edges
    void printEdges()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "the neighbours of the vertex no " << i << " is " << endl;
            for (auto &j : adjList[i])
            {
                cout << j.first << " " << j.second;
            }

            cout << " " << endl;
        }
    }
};

int main()
{

    Graph g(5);

    g.addEdge(0, 2, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 1, 3);

    g.printEdges();
    return 0;
}