#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> num;

    for (int i = 0; i < 10; i++)
    {
        num.push_back(rand() % 27);
    }

    for (auto &&i : num)
    {
        cout << i << " ";
    }

    sort(num.begin(), num.end());

    cout << endl;
    for (auto &&i : num)
    {
        cout << i << " ";
    }

    return 0;
}