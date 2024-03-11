#include <iostream>
#include <vector>
// for using the pair we need  to include the utility package
#include <utility>
using namespace std;

//  class for storing the graph
class Graph
{
private:
    int v;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertices)
    {
        v = vertices;
        adjList.resize(v);
    }

    //  function for adding edge between the two vertex with the respective weights
    void addEdge(int source, int dist, int weight)
    {
        adjList[source].push_back(make_pair(dist, weight));
        adjList[dist].push_back(make_pair(source, weight));
    }

    //  function for displaying the adjecent nodes of the vertices with their respective weight
    void printEdge()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Nodes and weigth for vertex " << i << " is " << endl;
            cout << "Node \t "
                 << "Weigth" << endl;
            for (auto &j : adjList[i])
            {
                cout << j.first << "\t" << j.second << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 1);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 3, 4);
    g.addEdge(2, 3, 3);

    g.printEdge();
}