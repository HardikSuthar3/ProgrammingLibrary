#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007

inline void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return (long long) (a * b) % MOD;
}

inline int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        b = b >> 1;
        a = mul(a, a);
    }
    return res;
}

inline int inv(int x) {
    return power(x, MOD - 2);
}

int main() {
    freopen("/home/hardik/ClionProjects/ProgrammingLibrary/input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = (sum + a[i]) % MOD;
    }
    int total = (sum * a.size()) % MOD;
    int left = a[0];
    return 0;
}