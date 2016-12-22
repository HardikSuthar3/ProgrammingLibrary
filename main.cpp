#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> a, b;
    for(int i = 0; i < 10; ++i) {
        a.insert(i + 1);
    }
    for(int i = 5; i < 20; ++i) {
        b.insert(i);
    }
    vector<int> result(max(a.size(), b.size()));
    auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    cout << distance(result.begin(), it) << " " << *it << endl;
    for(auto iter = result.begin(); iter != it; ++iter) {
        cout << *iter << " ";
    }
    return 0;
}
