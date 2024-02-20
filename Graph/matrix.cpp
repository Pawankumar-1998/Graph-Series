//  this code is used to store a graph using a matrix
#include <iostream>
using namespace std;

// matrix to store edges
int mat[6][6]; // 5 nodes and 6 edges
void checkRouteExisits(int, int);
int main()
{
    int ch;
    //  run the loop till how many number of edges you have in the graph
    for (int i = 0; i < 5; i++)
    {
        // enter the number of both nodes which are connected to each other
        int sourceNode, destinationNode;

        cout << "Enter the first node number :" << endl;
        cin >> sourceNode;
        cout << "Enter the second node number :" << endl;
        cin >> destinationNode;

        // now mark the distance between the source node and destination node as 1 and the vice versa
        mat[sourceNode][destinationNode] = 1;
        mat[destinationNode][sourceNode] = 1;

        cout << "Path between " << sourceNode << " amd " << destinationNode << endl;
    }

    cout << "Enter your choice  :" << endl;
    cin >> ch;
    switch (ch)
    {
        while (1)
        {
        case 1:
            int source, destination;
            cout << "Enter the source node number " << endl;
            cin >> source;
            cout << " Enter the destination number " << endl;
            cin >> destination;
            checkRouteExisits(source, destination);
            break;

        case 2:
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}

void checkRouteExisits(int sourceNode, int destinationNode)
{
    if (mat[sourceNode][destinationNode] == 1)
    {
        cout << "There is a route " << endl;
    }
    else
    {
        cout << "No route existes " << endl;
    }
}