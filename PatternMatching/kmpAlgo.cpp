#include <iostream>
#include <vector>

using namespace std;

// code for the pie table
vector<int> pieTable(const string pattern)
{
    int n = pattern.length();
    vector<int> table(n, 0);
    table[0] = 0;
    int len = 0;
    int i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            table[i] = len;
            i++;
        }
        else
        {
            table[i] = 0;
            i++;
        }
    }
}

// code for the kmp algorith
int kmpAlgo(const string text, const string pattern)
{
    int n = text.length();
    int m = pattern.length();
}