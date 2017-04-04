#include<bits/stdc++.h>

using namespace std;

string result;
vector<string> permutations;

void PermuteUtil(string str, vector<int> &count, int level) {
    if (level == result.length()) {
        // Print Permutation
        permutations.push_back(result);
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        if (count[i] == 0)
            continue;
        count[i]--;
        result[level] = str[i];
        PermuteUtil(str, count, level + 1);
        count[i]++;
    }
}

void Permute(string str) {
    unordered_map<char, int> chCount;
    int uniqueChar = 0;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (chCount.find(ch) == chCount.end()) {
            chCount.insert(make_pair(ch, 1));
        } else
            chCount[ch]++;
    }

    result.resize(str.size());

    vector<int> count;
    string minStr;
    for (auto item:chCount) {
        count.push_back(item.second);
        minStr.push_back(item.first);
    }
/*
    for (int i = 0; i < minStr.size(); i++) {
        cout << minStr[i] << " " << count[i] << endl;
    }*/

    PermuteUtil(minStr, count, 0);
}


/// Easy Program to Permute Strings
/// \param str: Input String
/// \param l: Left index
/// \param r:End Index
void permuteString(string str, int l, int r) {
    if (l == r) {
        cout << str << " ";
        return;
    }
    for (int i = l; i <= r; ++i) {

        swap(str[l], str[i]);
        permuteString(str, l + 1, r);
        swap(str[l], str[i]);
    }
}