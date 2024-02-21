#include <iostream>
#include <vector>
#include <queue>
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

//  function for the bgf traversal of the graph
vector<int> bfsTravel(vector<vector<int>> graph, int totalNodes)
{
    // vector for storing the visited node
    vector<int> visited(totalNodes + 1, 0);
    //  queues for storing the nodes that needes to be visited
    queue<int> q;
    // vector for storing the bfs
    vector<int> bfs;

    // setting the root index as visited as we start the traversal from there
    visited[1] = 1;

    // push the root node to queue
    q.push(1);
    // keep adding the adjecent nodes of the root and traverse until the queue is empty
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto adjNode : graph[node])
        {
            if (visited[adjNode] == 0)
            {
                visited[adjNode] = 1;
                q.push(adjNode);
            }
        }
    }
    return bfs;
}

int main()
{
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

    vector<int> bfs;
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
            bfs = bfsTravel(graph, nodes);
            cout << "The bfs traversal of the graph is :" << endl;
            for (int i = 0; i < bfs.size(); i++)
            {
                cout << bfs.at(i) << " ";
            }

            break;
        case 3:
            exit(0);

        default:
            break;
        }
    }
    return 0;
}
