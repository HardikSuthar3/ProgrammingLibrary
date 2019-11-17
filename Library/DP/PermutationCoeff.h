#include "bits/stdc++.h"

using namespace std;

long dp[100][100];

long permutationCoeff(int n, int k)
{
    if (k > n)
    {
        dp[n][k] = 0;
    }

    if (n < 0 || k < 0)
    {
        return 0;
    }

    if (k == 0)
    {
        dp[n][k] = 1;
    }

    if (dp[n][k] > -1)
    {
        return dp[n][k];
    }

    return (dp[n][k] = permutationCoeff(n - 1, k) + k * permutationCoeff(n - 1, k - 1));
}