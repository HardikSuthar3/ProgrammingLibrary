#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Input Variable Declaration
    int n;
    vector<int> ele;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        auto tmp = rand() % 29;
        ele.push_back(tmp);
    }

    for (auto &&i : ele)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    // Logic Section
    sort(ele.begin(), ele.end());

    for (auto &&i : ele)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;
    // Output Section
}