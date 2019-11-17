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
