#include "bits/stdc++.h"
using namespace std;

int main()
{
    unordered_map<string, int> items;

    items.insert(make_pair("A1", 1));
    items.insert(make_pair("A2", 2));
    items.insert(make_pair("A3", 3));
    items.insert(make_pair("A4", 4));

    for (auto &&i : items)
    {
        string a = i.first;
        int b = i.second;
        cout << a << " " << b << endl;
    }

    return 0;
}