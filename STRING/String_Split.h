//
// Created by Hardik on 02/07/16.
//

#include <bits/stdc++.h>
using namespace std;


vector<string> split(string str, char delim) {
    vector<string> elements;
    stringstream ss(str);
    string item;
    while (getline(ss, item, delim)) {
        elements.push_back(item);
    }
    return elements;
}

