/*ifstream in("/HSData/Data/IITM/workspace/CLion/ProblemsImplementation/input.txt", ios::in);
    auto buff = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());*/
#include "DP/Optimal Strategy for a Game.h"

using namespace std;
int sol[100][100];

int main() {
    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/input.txt", "r", stdin);
    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/output.txt", "w", stdout);

    clock_t t = clock();
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < n; ++j) {
            sol[i][j] = -1;
        }
    }

    OptimalStrategy(a, n);

    cerr << (float) (clock() - t) / CLOCKS_PER_SEC;
    return 0;
}