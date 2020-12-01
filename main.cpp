#include <bits/stdc++.h>

using namespace std;

int main()
{

    //freopen("/Users/hardik/HData/Development/CPP/ProgrammingLibrary/input.txt", "r", stdin);

    //Input Variable Declaration
    int n;
    vector<string> names;
    cin >> n;
    string tmp2;
    getline(std::cin, tmp2);
    for (size_t i = 0; i < n; i++)
    {
        string tmp;
        std::getline(std::cin, tmp);
        names.push_back(tmp);
    }
    cout << endl;
    // Logic

    for (size_t i = 0; i < n; i++)
    {
        int count = 0;
        for (size_t j = 0; j < i; j++)
        {
            if (std::lexicographical_compare(names[j].begin(), names[j].end(), names[i].begin(), names[i].end()))
            {
                count++;
            }
        }
        cout << count << endl;
    }

    // Output Section
}