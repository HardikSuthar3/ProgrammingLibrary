#include<bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t) {
    int i, j;
    i = j = 0;
    while (i < t.length() && j < s.length()) {
        if (s[j] == t[i]) {
            j++;
        }
        i++;
    }

    return (j == s.size()) ? true : false;
}
