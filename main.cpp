#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("/home/hardik/ClionProjects/ProgrammingLibrary/input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), dec;
        vector<int> b(a.size());

        dec.push_back(1);
        dec.push_back(2);
        dec.push_back(5);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int minEle = *min_element(a.begin(), a.end());
        vector<int> diff(a.size());
        for(int i=0;i<a.size();i++){
            diff[i] = a[i]-minEle;
        }

    }
    return 0;
}