#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\input.txt", "r", stdin);
    freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\output.txt", "w", stdout);

    //Reading input
    int n, q;
    cin >> n >> q;

    vector<pair<pair<int, int>, int>> num;
    for (size_t i = 0; i < q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        auto tmp = make_pair(make_pair(x, y), z);
        num.push_back(tmp);
    }

    // Program logic

    return 0;
}