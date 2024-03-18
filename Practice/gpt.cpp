#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

// Structure to represent a subset for union-find
struct Subset
{
    int parent, rank;
};

// Function to find set of an element i (path compression)
int find(vector<Subset> &subsets, int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two sets (union by rank)
void Union(vector<Subset> &subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm
void KruskalMST(vector<Edge> &edges, int V)
{
    vector<Edge> result;
    // Sort all edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Subset> subsets(V);
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (Edge edge : edges)
    {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        if (x != y)
        {
            result.push_back(edge);
            Union(subsets, x, y);
        }
    }

    // Print the edges of MST
    for (Edge edge : result)
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
}

int main()
{
    int V = 8; // Number of vertices
    vector<Edge> edges;
    edges.push_back({1, 2, 1});
    edges.push_back({1, 3, 7});
    edges.push_back({2, 4, 5});
    edges.push_back({3, 4, 2});
    edges.push_back({2, 5, 6});
    edges.push_back({5, 6, 3});
    edges.push_back({6, 8, 8});
    edges.push_back({8, 7, 4});
    edges.push_back({7, 5, 9});

    // Find and print MST using Kruskal's algorithm
    cout << "Edges of Minimum Spanning Tree using Kruskal's algorithm:" << endl;
    KruskalMST(edges, V);

    return 0;
}
