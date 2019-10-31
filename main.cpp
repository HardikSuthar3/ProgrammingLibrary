#include "bits/stdc++.h"

using namespace std;

long long dp[1000];

// Graph Structure
int V, E, root;
vector<int> G[100];
vector<pair<int, int>> edges;
vector<pair<int, float>> W;
//End Graph Structure

void MakeGraph(int n, int m)
{
    V = n;
    E = m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(i);
        edges.push_back(make_pair(a, b));
        W.push_back(make_pair(i, c));
    }
}

void PrintGraph()
{
    int n = V;
    int m = edges.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < G[i].size(); j++)
        {
            auto tmp = G[i][j];
            auto u = edges[tmp].first;
            auto v = edges[tmp].second;
            auto w = W[tmp].second;
        }
    }
}

int main()
{
    // auto in = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\input.txt", "r", stdin);
    // auto out = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\output.txt", "w", stdout);

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