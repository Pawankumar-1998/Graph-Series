#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//  code for the  matrix multiplication algo
vector<vector<int>> matrix_chain_multiplication(const vector<int> &dims)
{
    int n = dims.size();

    //  storing the value of cost of multipliying two matrixs
    vector<vector<int>> c(n, vector<int>(n, 0));

    // this is used for storing k
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;

            c[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = c[i][k] + c[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < c[i][j])
                {
                    c[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    return s;
}

//  for printing the best pair parenthesis matrix
void printParanthesisMatrix(const vector<vector<int>> &s, int i, int j)
{
    //  if the i and j are equal
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << " ( ";
        printParanthesisMatrix(s, i, s[i][j]);
        printParanthesisMatrix(s, s[i][j] + 1, j);
        cout << " )";
    }
}

int main()
{
    vector<int> dimensions = {2, 3, 4, 2}; // Matrix dimensions: A1(2x3), A2(3x4), A3(4x2)

    vector<vector<int>> s = matrix_chain_multiplication(dimensions);

    cout << "Optimal Parenthesization: ";
    printParanthesisMatrix(s, 1, dimensions.size() - 1);
    cout << endl;

    return 0;
}