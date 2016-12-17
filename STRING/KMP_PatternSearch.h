#include<bits/stdc++.h>

using namespace std;

vector<int> computeLPSArray(string pattern) {
    vector<int> lps(pattern.size());
    lps[0] = 0;

    int j = 0;
    int i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            j++;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

/// KMP Algo searches a string pattern in another string.
/// It takes O(m+n) time
/// \return index of Matched String
bool KMP_Search(string text, string pattern) {

    auto lps = computeLPSArray(pattern);
    int i = 0, j = 0;
    while (i < text.length() && j < pattern.length()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    if (j == pattern.length()) {
        return true;
    } else {
        return false;
    }
    // for finding starting index of pattern in text return (i-j)
}