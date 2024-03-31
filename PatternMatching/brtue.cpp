#include <iostream>
#include <string>
using namespace std;

//  code for finding the pattern using the brute force approach
int findPattern(const string &text, const string &pattern)
{
    int textLen = text.length();
    int patternLen = pattern.length();

    for (int i = 0; i <= textLen - patternLen; ++i)
    {
        bool matching = true;
        for (int j = 0; j < patternLen; ++j)
        {
            //  only break the loop if the char at i and j doesn't match
            if (text[i + j] != pattern[j])
            {
                matching = false;
                break;
            }
        }

        //  if the matching is true we found the pattern
        if (matching)
        {
            return i;
        }
    }

    //  else return -1
    return -1;
}

int main()
{
    string text, pattern;

    cout << "Enter the text " << endl;
    getline(cin, text);

    cout << "Enter the pattern" << endl;
    getline(cin, pattern);

    int ans = findPattern(text, pattern);
    if (ans != -1)
    {
        cout << "The pattern is at index " << ans << endl;
    }
    else
    {
        cout << "The pattern is not in the text you provided " << endl;
    }
}