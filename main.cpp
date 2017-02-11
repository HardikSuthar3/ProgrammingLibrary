#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if(x <= 2) {
        return true;
    }
    for(int i = 2; i <= (int)sqrt(x); i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n + 1);
    numbers[0] = 0;
    for(int i = 1; i < n; i++) {
        int val;
        cin >> val;
        numbers[i] = numbers[i - 1] + val;
    }

    for(int window = n - 1; window >= 0; window--) {
        if(isPrime(window)) {
            break;
        }
    }
    return 0;
}
