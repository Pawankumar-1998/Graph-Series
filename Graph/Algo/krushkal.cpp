#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  this is the structure of the edges
struct Edge
{
    int src, dest, weight;
};

//  this is the structure of the subset which store the parent of the particular node and their ranks
struct Subset
{
    int parent, rank;
};

// this function is used to compare two edges with respective to their weight
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

//  this function will give the parent node of the following node
int find(vector<Subset> &subsets, int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
}

//  this is the function for joining two sets
void Union(vector<Subset> &subsets, int firstNode, int secondNode)
{
    int firstNodeParent = find(subsets, firstNode);
    int secondNodeParent = find(subsets, secondNode);

    // if the rank of the firstNode is less then the ranl of the second node
    if (subsets[firstNodeParent].rank < subsets[secondNodeParent].rank)
    {
        subsets[firstNodeParent].parent = secondNodeParent;
    }
    else if (subsets[firstNodeParent].rank > subsets[secondNodeParent].rank)
    {
        subsets[secondNodeParent].parent = firstNodeParent;
    }
    else
    {
        subsets[secondNodeParent].parent = firstNodeParent;
        subsets[firstNodeParent].rank++;
    }
}

//  code of the krushkal algorithm
void krushkal(int V, vector<Edge> edges)
{
    vector<Edge> selected; // for storing the selected vertexs

    //  this sort function below sorts all the edges accorting to their weights ( in the ascending order )
    sort(edges.begin(), edges.end(), compareEdges);

    //  this is for storing the parent and rank of the respective node
    vector<Subset> subset(V + 1);

    // initially every node is their parent and their rank is 0
    for (int i = 1; i < V + 1; i++)
    {
        subset[i].parent = i;
        subset[i].rank = 0;
    }

    // select each edge from the sorted vector
    for (size_t i = 0; i < edges.size(); i++)
    {
        int pFirstNode = find(subset, edges[i].src);
        int pSecondNode = find(subset, edges[i].dest);
        // if the parent of the first node and second node are not same the add it to result and find union
        if (pFirstNode != pSecondNode)
        {
            // add the edge to the result
            selected.push_back(edges[i]);
            Union(subset, pFirstNode, pSecondNode);
        }
    }
    // Print the edges of MST
    for (size_t i = 0; i < selected.size(); i++)
        cout << selected[i].src << " - " << selected[i].dest << " : " << selected[i].weight << endl;
}

int main()
{
    int V = 8;
    vector<Edge> edges;
    edges.push_back({1, 2, 1});

    // Find and print MST using Kruskal's algorithm
    cout << "Edges of Minimum Spanning Tree using Kruskal's algorithm:" << endl;
    krushkal(V, edges);
    return 0;
}