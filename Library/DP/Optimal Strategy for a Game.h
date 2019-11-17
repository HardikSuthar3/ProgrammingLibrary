/*
Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even.
 We play a game against an opponent by alternating turns.
 In each turn, a player selects either the first or last coin from the row,
 removes it from the row permanently, and receives the value of the coin.
 Determine the maximum possible amount of money we can definitely win if we move first.

Note: The opponent is as clever as the user.

Let us understand the problem with few examples:

    1. 5, 3, 7, 10 : The user collects maximum value as 15(10 + 5)

    2. 8, 15, 3, 7 : The user collects maximum value as 22(7 + 15)

Does choosing the best at each move give an optimal solution?

No. In the second example, this is how the game can finish:

1.
…….User chooses 8.
…….Opponent chooses 15.
…….User chooses 7.
…….Opponent chooses 3.
Total value collected by user is 15(8 + 7)

2.
…….User chooses 7.
…….Opponent chooses 8.
…….User chooses 15.
…….Opponent chooses 3.
Total value collected by user is 22(7 + 15)

  */

#include <bits/stdc++.h>

using namespace std;

int OptimalStrategy_Recursion(int *a, int i, int j) {
    cerr << i << " " << j << endl;

    if (i == j) {
        return a[i];
    } else if (i + 1 == j) {
        return max(a[i], a[j]);
    }

    int x = a[i] + min(OptimalStrategy_Recursion(a, i + 2, j), OptimalStrategy_Recursion(a, i + 1, j - 1));
    int y = a[j] + min(OptimalStrategy_Recursion(a, i, j - 2), OptimalStrategy_Recursion(a, i + 1, j - 1));
    return max(x, y);
}


void printSol(int **sol, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

int OptimalStrategy(int *a, int n) {
    int **sol = new int *[n];
    for (int i = 0; i < n; i++) {
        sol[i] = new int[n];
    }

    for (int len = 0; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            if (i == j)
                sol[i][j] = a[i];
            else {
                int x = (i + 2 <= j) ? sol[i + 2][j] : 0;
                int y = (i + 1 <= j - 1) ? sol[i + 1][j - 1] : 0;
                int z = (i <= j - 2) ? sol[i][j - 2] : 0;

                sol[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
            }

        }

    }
    printSol(sol, n);

    return 0;
}