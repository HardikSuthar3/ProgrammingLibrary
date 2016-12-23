#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    reverse(str.begin(), str.end());
    vector<int> res(str.length(), 0);
    for(int i = 0; i < str.length(); i++) {
        if((str[i] - '0') % 2 == 0) {
            res[i] = res[i - 1] + 1;
        } else {
            res[i] = res[i - 1];
        }
    }
    reverse(res.begin(), res.end());
    for(auto &item: res) {
        cout << item << " ";
    }
    return 0;
}
