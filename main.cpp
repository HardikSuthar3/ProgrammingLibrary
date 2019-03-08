#include "bits/stdc++.h"

using namespace std;

long dp[100][100];

int main()
{
    // freopen("D:\\OneDrive-Microsoft\\Development\\C++\\ProgrammingLibrary\\input.txt", "r", stdin);
    // freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\output.txt", "w", stdout);

    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            dp[i][j] = -1;
        }
    }

    //Reading input
    int n, k;
    cin >> n >> k;
    return 0;
}