#include <bits/stdc++.h>

using namespace std;

int LIS() {
// Input Read
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    // Input End

    // Sol Begins

    int *sol = new int[n];
    sol[0] = 1;
    for (int i = 1; i < n; i++) {
        sol[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && sol[j] + 1 > sol[i]) {
                sol[i] = sol[j] + 1;
            }
        }
    }
    return *max_element(sol, sol + n);

    // Sol Ends
}