#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int source, dest, weight;
};

struct Subset
{
    int parent, rank;
};

//  fucntion compares two edges and return bool
bool compare(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

//  union operation on the graph is to be performed when both the nodes belongs to diffrent subse
void Union(vector<Subset> subset, int srcNode, int destNode)
{
    //  get the parent of the source node
    int srcNP = find(subset, srcNode);

    // get the parent of the dest node
    int destNP = find(subset, destNode);

    // preference will be given to the parent node having higher rank for merging
    if (subset[srcNP].rank < subset[destNP].rank)
    {
        //  in this case the porent of the source node will be changed
        subset[srcNP].parent = destNode;
    }
    else if (subset[srcNP].rank > subset[destNP].rank)
    {
        //  in this case the parent of the dest node will be changed
        subset[destNP].parent = srcNode;
    }
    else
    {
        //  this part will be executed when the rank of both(source node and the dest node are same )
        subset[destNP].parent = srcNode;
        // increment the rank of the source node by 1;
        subset[srcNP].rank++;
    }
}

//  function for finding the parent node of the given node
int find(vector<Subset> subset, int node)
{
    // if the parent node is not the parent of itself then it has been merged before with another subset find the above parent recursively
    if (subset[node].parent != node)
    {
        subset[node].parent = find(subset, subset[node].parent);
    }
    return subset[node].parent;
}

//  function for krushkal algo
void krushkalAlg0(int v, vector<Edge> graph)
{
    // sort the graph according to their edge weights
    sort(graph.begin(), graph.end(), compare);

    // vector that contain individual nodes as individual subset initially
    vector<Subset> subsets(v + 1);

    //  initially parent of the each node are they themself and rank in 1 by default
    for (int i = 1; i < v + 1; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    //  vector for storing the selected vertex
    vector<Edge> result;

    //  select a edge from the sorted list of graph
    for (size_t i = 0; i < graph.size(); i++)
    {
        //  find the parent of the source node
        int srcNP = find(subsets, graph[i].source);

        //  find the parent of the destination node
        int dstNP = find(subsets, graph[i].dest);

        // only continue if the source node parent and destination node parent are diffrent
        if (srcNP != dstNP)
        {
            // add the edge to the resultant vector
            result.push_back(graph[i]);
            // perform the union on the subset (i.e merge the both subsets)
            Union(subsets, srcNP, dstNP);
        }
    }
}

int main()
{
    vector<Edge> graph;

    // adding the nodes and the edges of the graph
    graph.push_back({1, 2, 1});
    graph.push_back({1, 3, 7});
    graph.push_back({2, 4, 5});
    graph.push_back({3, 4, 2});
    graph.push_back({2, 5, 6});
    graph.push_back({5, 6, 3});
    graph.push_back({6, 8, 8});
    graph.push_back({8, 7, 4});
    graph.push_back({7, 5, 9});

    return 0;
}