#include <iostream>
#include <vector>
using namespace std;

// predefinig the functions
void checkRouteExisits(vector<vector<int>> &v, int source)
{
    cout << "the adjecent destination node for" << source << "are : " << endl;
    for (int i = 0; i < v[source].size(); i++)
    {
        cout << v[source][i] << " ";
    }
    cout << endl;
}

int main()

{

    int nodes, edges;
    cout << "Enter the number of nodes in the graph :" << endl;
    cin >> nodes;
    cout << "Enter the number of edges in the graph :" << endl;
    cin >> edges;

    //  the size of the vector should be equal to number of nodes in the graph
    vector<vector<int>> v(nodes + 1, vector<int>());

    for (int i = 0; i < edges; i++)
    {
        int sourceNode, destinationNode;
        cout << "Enter the number of the source node " << endl;
        cin >> sourceNode;
        cout << "Enter the number of the destination node " << endl;
        cin >> destinationNode;

        // insert the node in the specified index
        v[sourceNode].push_back(destinationNode);
        v[destinationNode].push_back(sourceNode);
    }
    int ch;
    cout << "Enter your choice  :" << endl;
    cin >> ch;
    switch (ch)
    {

    case 1:
        int source;
        cout << "Enter the source node number " << endl;
        cin >> source;
        checkRouteExisits(v, source);
        break;

    case 2:
        exit(0);
        break;

    default:
        break;
    }
    return 0;
}