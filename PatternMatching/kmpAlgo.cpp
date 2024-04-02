#include <iostream>
#include <vector>
#include <string>
using namespace std;

// code for the LPS table or the pie table
vector<int> pieTable(const string &pattern)
{
    int n = pattern.length();
    //  vector to store the pie table
    vector<int> pie(n, 0);

    //  the first index of the pie table will always be 0 because there will not be any previous occurence of the
    //  first index as it the first index
    pie[0] = 0;

    int len = 0;

    int i = 1;
    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            pie[i] = len;
            i++;
        }
        else
        {

            if (len != 0)
            {
                len = pie[len - 1];
            }
            else
            {
                pie[i] = 0;
                i++;
            }
        }
    }

    return pie;
}

//  code of the algo kmp
int kmpAlgo(const string &text, const string &pattern)
{
    int textLen = text.length();
    int patternLen = pattern.length();

    //  get the lps table or the pie table from the above
    vector<int> lps = pieTable(pattern);

    int i = 0; // for the text
    int j = 0; // for the pattern

    while (i < textLen)
    {
        //  if the pattern is matching keep forwarding the pointers
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
    }

    //  if the both pointers reached at their ends it means patters has been found
    if (j == patternLen)
    {
        cout << "The pattern is available at the index no :" << i - j << endl;
        j = lps[j - 1];
    }
    else if (i < textLen && text[i] != pattern[j])
    {
        if (j != 0)
        {
            j = lps[j - 1];
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    kmpAlgo(text, pattern);

    return 0;
}