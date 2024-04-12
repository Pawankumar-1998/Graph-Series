#include <iostream>
#include <string>
#include <vector>

using namespace std;

// code for the pie tables
vector<int> pieTable(const string &pattern)
{
    int n = pattern.length();
    vector<int> table(n, 0);
    int len = 0;
    table[0] = 0;
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
            if (len != 0)
            {
                len = table[len - 1];
            }
            else
            {

                table[i] = 0;
                i++;
            }
        }
    }
    return table;
}

// code for the kmp algorithm
void kmpAlgo(const string &text, const string &pattern)
{
    int m = pattern.length();
    int n = text.length();

    vector<int> table = pieTable(pattern);
    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        // if the j reaches lenght of the pattern then the pattern is found
        if (j == m)
        {
            cout << "The pattern is found at the index " << i - j << endl;
            j = table[j - 1];
        }

        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = table[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the text" << endl;
    getline(cin, text);
    cout << "Enter the pattern " << endl;
    getline(cin, pattern);

    kmpAlgo(text, pattern);
}