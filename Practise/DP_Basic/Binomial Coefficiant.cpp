#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

vector<vector<long long>> dp(1001, vector<long long>(801, -1));

long long BinomialCoefficiant(int n, int k) {
    if (k == 0 || k == n) {
        return dp[n][k] = 1;
    }

    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    return dp[n][k] = BinomialCoefficiant(n - 1, k - 1) + BinomialCoefficiant(n - 1, k);
}

int main() {
    /*Change input file from stdin to other*/
    freopen("C:\\Users\\hasuthar\\CLionProjects\\ProgrammingLibrary\\input.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        /*Reading Input*/
        int n, k;
        cin >> n >> k;
        /*Reading Input Ends*/

        /*Logic Begins*/
        cout << BinomialCoefficiant(n, k) << endl;
        /*Logic Ends*/
    }


    return 0;
}