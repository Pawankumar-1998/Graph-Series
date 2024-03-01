#include <iostream>
#include <climits>
using namespace std;
#define V 5

//  function to get the minimum anong the distance and mark the selected node as visited in the visited array
int minDistance(int minDist[V], bool visited[V])
{
    int minDistance = INT_MAX, selectedIndex = -1;
    for (int i = 0; i < V; i++)
    {
        if (minDist[i] < minDistance && visited[i] == false)
        {
            minDistance = minDist[i];
            selectedIndex = i;
        }
    }

    // return the selected index
    return selectedIndex;
}

//  print the prims nodes
void printPrims(int parent[V], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

//  FUNCTION FOR PRIMS ALGORITHM
void prims(int graphs[V][V])
{
    // array for storing the parent of the node
    int from[V];

    // array for storing the min distance to reach a particular node
    int minDst[V];

    // array for tracking if the node is visited or not
    bool visited[V];

    // initializing the min distance as the max number and the visited array as false by default
    for (int i = 0; i < V; i++)
    {
        minDst[i] = INT_MAX;
        visited[i] = false;
    }

    // as we start with node 0 set the min distance of 0 is 0 as it is the starting node
    minDst[0] = 0;

    // as it is the starting node it doesn't come from any other node the from node of 0 is -1
    from[0] = -1;

    //  start traversing from the selected node
    //  traverse till V-1 because a graph having V vertex should have V-1 edges

    for (int i = 0; i < V - 1; i++)
    {
        //  get the node with minumun distance
        int selectedNode = minDistance(minDst, visited);

        //  mark the selected node as visited in the visited array
        visited[selectedNode] = true;

        for (int node = 0; node < V; node++)
        {
            if (graphs[selectedNode][node] && visited[node] == false && graphs[selectedNode][node] < minDst[node])
            {
                //  set the mininum distance to visit the node as the current node distance
                minDst[node] = graphs[selectedNode][node];
                // as the min distance is from the selected node set the selected node as the parent of the current node
                from[node] = selectedNode;
            }
        }
    }

    printPrims(from, graphs);
}

int main()
{
    int graphs[V][V] = {
        {0, 1, 3, 0, 0},
        {1, 0, 0, 2, 0},
        {3, 0, 0, 4, 2},
        {0, 2, 4, 0, 3},
        {0, 0, 2, 3, 0},
    };

    prims(graphs);
    return 0;
}