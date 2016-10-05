/*ifstream in("/HSData/Data/IITM/workspace/CLion/ProblemsImplementation/input.txt", ios::in);
    auto buff = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());*/
#include<bits/stdc++.h>

using namespace std;


#define MOD 1000000007

inline int add(int a, int b) {
    return (a + b) % MOD;
}


int main() {

//    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/input.txt", "r", stdin);
//    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/output.txt", "w", stdout);

    freopen("/home/hardik/ClionProjects/ProgrammingLibrary/input.txt", "r", stdin);
    freopen("/home/hardik/ClionProjects/ProgrammingLibrary/output.txt", "w", stdout);


    // Input Begin
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cout << a[i] << endl;
    }
    // Input End


    // Sol Begin
    int **sol = new int *[n];
    for (int i = 0; i < n; i++) {
        sol[i] = new int[n];
        fill(sol[i], sol[i] + n, 0);
        sol[i][i] = a[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;

        }
    }
    // Sol End




    return 0;

}