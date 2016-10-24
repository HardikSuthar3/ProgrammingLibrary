#include<bits/stdc++.h>

using namespace std;

bool isBalanced(string str) {
    stack<char> st;
    for (auto &item:str) {
        if (item == '(') {
            st.push(item);
        } else {
            if (st.empty() == true)
                return false;
            else {
                st.pop();
            }
        }
    }
    return st.empty();
}

set<string> ss;

void change(string str, int start) {
    if (str.size() == 0)
        return;
    if (start >= str.size()) {
        if (isBalanced(str)) {
            ss.insert(str);
        }
    }
    int c = 0;
    for (int i = start; i < str.size(); i++) {
        if (str[i] == '*') {
            c++;
            str[i] = '(';
            change(str, i + 1);

            str[i] = ')';
            change(str, i + 1);

            string a = str.substr(0, i) + str.substr(i + 1);
            change(a, i);
        }
    }
    if (c == 0 && isBalanced(str)) {
        ss.insert(str);
    }
}

int main() {
    freopen("/HSData/Data/IITM/workspace/CLion/ProgrammingLibrary/output.txt", "w", stdout);
    string s = "(*(*)*)";
    s = "*(*(**)*";
    s = "";
    change(s, 0);
    for (auto &item:ss) {
        cout << item << endl;
    }

    priority_queue<int, deque<int> > q;
    for (int i = 1; i <= 10; i++) {
        q.push(rand() % 11);
    }
    for (int i = 0; i < 10; i++) {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}

