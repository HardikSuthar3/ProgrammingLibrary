#include "bits/stdc++.h"

using namespace std;

int main()
{
    freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\input.txt", "r", stdin);
    // freopen("D:\\OneDrive - Microsoft\\Development\\C++\\ProgrammingLibrary\\output.txt", "w", stdout);

    vector<int> num;

    //Reading input
    for (size_t i = 0; i < 10; i++)
    {
        num.push_back(rand() % 100);
    }

    cout << "Before Sort" << endl;
    for (auto &&i : num)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "After Sort" << endl;
    sort(num.begin(), num.end(), std::less<int>());
    for (auto &&i : num)
    {
        cout << i << " ";
    }

    return 0;
}