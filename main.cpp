/*ifstream in("/HSData/Data/IITM/workspace/CLion/ProblemsImplementation/input.txt", ios::in);
    auto buff = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());*/
#include<bits/stdc++.h>

using namespace std;

int main() {

//    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/input.txt", "r", stdin);
//    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/output.txt", "w", stdout);
    int n;
    vector<int> a;

    for (int i = 1; i <= 20000; ++i) {
        a.push_back(i);

    }
    cout << a.size();


}