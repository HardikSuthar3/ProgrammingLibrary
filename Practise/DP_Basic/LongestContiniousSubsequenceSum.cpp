#include <bits/stdc++.h>

using namespace std;

int LongestContSum(vector<int> &num) {
    vector<long> dp(num.size());
    dp[0] = num[0];
    for (int i = 1; i < num.size(); i++) {
        dp[i] = max(dp[i - 1] + num[i], (long)num[i]);
    }

    return *max_element(dp.begin(), dp.end());
}




int main() {
    freopen("C:\\Users\\hasuthar\\CLionProjects\\ProgrammingLibrary\\input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        cout << LongestContSum(numbers)<<endl;
    }
    return 0;
}