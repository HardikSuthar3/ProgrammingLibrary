/*ifstream in("/HSData/Data/IITM/workspace/CLion/ProblemsImplementation/input.txt", ios::in);
    auto buff = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());*/
#include<bits/stdc++.h>

using namespace std;

int main() {

//    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/input.txt", "r", stdin);
//    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        // Input Begin
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // Input End


        // Sol Begin

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
        cout << *max_element(sol, sol + n) << endl;
        // Sol End

    }

    return 0;

}