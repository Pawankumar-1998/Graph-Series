#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
//  code of the floyd warshall or all source shortest path
void floydWarshall(vector<vector<int>> &graph)
{
    const int V = graph.size();

    //  creating a matrix for performing the algo on it and setting its default values to the infinity
    vector<vector<int>> dist(V, vector<int>(V, INF));

    //  copying the values to the vector we created
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    //  as it the all source shortest path we need to consider all the nodes
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Printing the shortest distance
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};

    // Applying Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}