#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixChainMulti(vector<int> &dimn)
{
    int n = dimn.size();

    //  this is for storing the value of the minimum cost
    vector<vector<int>> cMatrix(n, vector<int>(n, 0));

    //  this for storing the value of k
    vector<vector<int>> kMatrix(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++)
    {
        
    }
}

int main()
{
    vector<int> dimensions = {2, 3, 4, 2};
}