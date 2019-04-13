#include "bits/stdc++.h"

using namespace std;

long long dp[1000];

long long fun(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (n <= 2)
    {
        dp[n] = n;
    }

    if (dp[n] > 0)
    {
        return dp[n];
    }
    return dp[n] = dp[n - 1] + dp[n - 2];
}

int V, E, root;
vector<int> G[100];
vector<pair<int, int>> edges;
vector<pair<int, float>> W;

int main()
{
    auto in = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\input.txt", "r", stdin);
    auto out = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\output.txt", "w", stdout);

    vector<int> a;

    //Reading input
    for (size_t i = 1; i <= 10; i++)
    {
        a.push_back(rand() % 1000);
        // cout << fun(i) << endl;
    }

    cout << "Beore Sort" << endl;
    for (auto &&i : a)
    {
        cout << i << " ";
    }

    cout << endl
         << "After Sort" << endl;

    sort(a.begin(), a.end());
    for (auto &&i : a)
    {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}