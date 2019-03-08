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

int main()
{
    auto in = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\input.txt", "r", stdin);
    auto out = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\output.txt", "w", stdout);

    //Reading input
    for (size_t i = 1; i <= 10; i++)
    {
        cout << fun(i) << endl;
    }

    return 0;
}