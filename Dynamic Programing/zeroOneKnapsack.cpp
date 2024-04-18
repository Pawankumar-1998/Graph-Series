#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int profit[5] = {0, 1, 2, 5, 6};
    int weight[5] = {0, 2, 3, 4, 5};

    // m is the capacity of the knapsack bag and n is the number of the object
    int m = 8, n = 4;

    //  this is used to store the values in the table
    int v[5][9];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            //  if the i and w are 0 which means if there is no object or if the weight of the back is 0 then the profit is 0 at all
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if (weight[i] <= j)
            {
                //  code needs to be implemented
                v[i][j] = max(v[i - 1][j], profit[i] + v[i - 1][j - weight[i]]);
            }
            else
            {
                v[i][j] = v[i - 1][j];
            }
        }
    }

    cout << "The max profit that can be earned is " << v[n][m] << endl;

    //  this is code to see which objects are included and which are ignored if 0 excluded if 1 include
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (v[i][j] == v[i - 1][j])
        {
            cout << i << " 0 " << endl;
            i--;
        }
        else
        {
            cout << i << " 1 " << endl;
            i--;
            j = j - weight[i];
        }
    }
}