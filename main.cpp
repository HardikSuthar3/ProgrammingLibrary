/*ifstream in("/HSData/Data/IITM/workspace/CLion/ProblemsImplementation/input.txt", ios::in);
    auto buff = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());*/
#include<bits/stdc++.h>
using namespace std;

int main() {

//    freopen("/HSData/Data/IITM/workspace/CLion/ProblemsImplementation/input.txt", "r", stdin);
//    freopen("/HSData/Data/IITM/workspace/CLion/ProblemsImplementation/output.txt", "w", stdout);


    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // Input begin
        int n, k;
        cin >> n >> k;
        // Input End


        //  Sol begin
        bool *task = new bool[n + 1];
        fill(task, task + n + 1, false);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            task[x] = true;
        }

        vector<int> a;
        for (int i = 1; i <= n; i++) {
            if (!task[i]) {
                a.push_back(i);
            }
        }

        if (a.size() > 0) {
            for (int i = 0; i < a.size(); i = i + 2) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << endl;
            continue;
        }
        if (a.size() > 1) {
            for (int i = 1; i < a.size(); i = i + 2) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else{
            cout << endl;
        }

        // Sol end
    }


    return 0;

}