#include<bits/stdc++.h>

using namespace std;

int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
        cout << dp[i] << " ";
    }


    return dp[amount] > amount|| dp[amount] <0? -1 : dp[amount];
}

int main() {
//    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/input.txt", "r", stdin);


    freopen("/home/hardik/ClionProjects/ProgrammingLibrary/input.txt", "r", stdin);

    int n, sum;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> sum;

    cout << coinChange(a, sum);


    return 0;
}