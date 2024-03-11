#include <iostream>
#include <vector>
using namespace std;

//  class for storing the graph
class Graph
{
private:
    int v;
    vector<vector<int>> adjList;

public:
    // constructor for setting the number of vertices in the graph
    Graph(int vertices)
    {
        v = vertices;
        // set the sixe of the adjecency list as the number of vertices
        adjList.resize(v);
    }

    //  function for adding a edge between the vertices
    void addEdge(int sourceNode, int distNode)
    {
        adjList[sourceNode].push_back(distNode);
        adjList[distNode].push_back(sourceNode);
    }

    //  function for printing the adjecent vertex of the node
    void printAdj()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Adjecent node of vertex " << i << "is" << endl;
            for (int j : adjList[i])
            {
                cout << j << "\t";
            }

            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);

    // add the edges between the veretx
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    //  print all the vertices
    g.printAdj();

    return 0;
}