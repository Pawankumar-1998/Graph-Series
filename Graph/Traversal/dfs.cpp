#include <iostream>
#include <vector>
using namespace std;

// function for checking the adjecent nodes
void checkRouteExisits(vector<vector<int>> &graph, int source)
{
    cout << "The adjecent nodes of the source node " << endl;
    for (int i = 0; i < graph[source].size(); i++)
    {
        cout << graph[source][i] << "";
    }
    cout << endl;
}

void dfsTraversal(vector<vector<int>> &graph, vector<int> &bfs, vector<int> &visited, int initialNode)
{
    visited[initialNode] = 1;
    bfs.push_back(initialNode);
    for (auto item : graph[initialNode])
    {
        if (visited[item] == 0)
        {
            dfsTraversal(graph, bfs, visited, item);
        }
    }
}

int main()
{
    //  code for storing the graph in the adjecent list
    int nodes, edges;
    cout << "Enter the number of nodes : " << endl;
    cin >> nodes;
    cout << "Enter the number of edges : " << endl;
    cin >> edges;
    vector<vector<int>> graph(nodes + 1, vector<int>());
    // store the graph in the adjecent list
    for (int i = 0; i < edges; i++)
    {
        int sourceNode, destinationNode;
        cout << "source node number :" << endl;
        cin >> sourceNode;
        cout << "destination node number :" << endl;
        cin >> destinationNode;

        // store in the graph
        graph[sourceNode].push_back(destinationNode);
        graph[destinationNode].push_back(sourceNode);
    }

    vector<int> visited(nodes + 1, 0);
    vector<int> dfs;
    int ch;
    cout << "Enter your choice :" << endl;
    cin >> ch;
    switch (ch)
    {
        while (1)
        {
        case 1:
            int source;
            cout << "Enter the number of source node to see its adjecents : " << endl;
            cin >> source;
            checkRouteExisits(graph, source);
            break;

        case 2:
            int initialNode;
            cout << "Enter the initial nodes " << endl;
            cin >> initialNode;
            dfsTraversal(graph, dfs, visited, initialNode);
            for (int i = 0; i < dfs.size(); i++)
            {
                cout << dfs.at(i) << " -- >";
            }

            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}