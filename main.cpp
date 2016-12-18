#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, n, k;
    cin >> a >> n >> k;
    int b = a;
    for(int i = 1; i <= k; ++i) {
        cout << b % (n + 1) << " ";
        b = b / (n + 1);
    }
    return 0;
}
