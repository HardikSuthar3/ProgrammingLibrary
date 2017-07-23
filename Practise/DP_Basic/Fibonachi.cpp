//
// Created by hasuthar on 7/23/2017.
//

#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

vector<int> dp(1001, -1);


int fib(int n) {
    if (n <= 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = (fib(n - 1) + fib(n - 2)) % MOD;
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << fib(n) << endl;
    }
    return 0;
}