#include <bits/stdc++.h>

using namespace std;

double P(string str) {
    if (str.size() == 0)
        return 0;

    double val = 0;
    for (int i = 0; i < str.length(); i++) {
        int a = str[i] - 96;
        val += a * pow(2, -i);
    }

}

bool mycompare(pair<string, double> a, pair<string, double> b) {
    if (a.second - b.second > (double) 0.0) {
        return false;
    } else if (a.second - b.second < (double) 0.0) {
        return true;
    } else {
        return a.first >= b.first;
    }
}

int main() {

    string str;
    getline(cin, str);
    map<double, string> inputs;
    for (int i = 0; i < str.length(); i++) {
        string left = str.substr(0, i + 1);
        string right = str.substr(i + 1);
        string newStr = right + left;

        inputs.insert(make_pair(P(newStr), newStr));
    }

    auto item = max_element(inputs.begin(), inputs.end());

    /*for (auto &&item1  : inputs) {
        cout << item1.first << " " << item1.second << endl;
    }

    cout << endl << endl;*/
    cout << item->second;
    return 0;
}
