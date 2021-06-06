#include <bits/stdc++.h>
using namespace std;

// Count number of words in string

int CountWords(string str)
{
    stringstream s(str);
    int count = 0;
    string word;
    while (s >> word)
    {
        count++;
    }
    return count;
}

void AppendWord(string source, string word)
{
    // cout << source << endl;
    stringstream ss(source, ios::app | ios::in | ios ::out);
    ss << word;
    // cout << source << endl;
    cout << ss.rdbuf() << endl;
}