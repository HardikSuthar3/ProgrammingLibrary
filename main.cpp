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
    // auto in2 = freopen("/Users/hardik/HData/Development/CPP/ProgrammingLibrary/input.txt", "r", stdin);
    // auto o = freopen("/Users/hardik/HData/Development/CPP/ProgrammingLibrary/output.txt", "r", stdout);

    vector<int> a;
    for (int i = 0; i < 100; i++)
    {
        a.push_back(rand() % 29);
    }

    cout << "Before Sort" << endl;

    for (auto &item : a)
    {
        cout << item << " ";
    }

    cout << endl
         << endl
         << "After Sort" << endl
         << endl;
    sort(a.begin(), a.end(), std::greater<int>());

    for (auto &item : a)
    {
        cout << item << " ";
    }
    return 0;
}