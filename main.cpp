#include <bits/stdc++.h>
using namespace std;

int main() {
    /*Change input file from stdin to other*/
    freopen("C:\\Users\\hasuthar\\CLionProjects\\ProgrammingLibrary\\input.txt", "r", stdin);
//    freopen("D:\\Hardik\\Clion Projects\\ProgrammingLibrary\\input.txt", "r", stdin);
    freopen("C:\\Users\\hasuthar\\CLionProjects\\ProgrammingLibrary\\output.txt", "w", stderr);

    int owKey, reqKey, n;
    cin >> owKey >> reqKey >> n;

    vector<int> keySet(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> keySet[i];
    }

    queue<int> q;
    vector<int> steps(100000 + 5, -1);
    q.push(owKey);
    steps[owKey] = 0;

    long long curVal, newVal;

    while (!q.empty()) {
        curVal = q.front();
        q.pop();
        if (curVal == reqKey)
            break;
        for (int i = 0; i < n; i++) {
            newVal = (curVal * keySet[i]) % 100000;

            if (steps[newVal] == -1) {
                steps[newVal] = steps[curVal] + 1;
                q.push((int)newVal);
            }
        }
    }

    cout << steps[reqKey];
    return 0;
}