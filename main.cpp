#include <bits/stdc++.h>

using namespace std;

void fun(vector<string> &inp) {
   int n = inp.size();
   unordered_map<int, set<int>> data;
   unordered_set<int> yvals;
   for (int i = 0; i < n; i++) {
      stringstream ss(inp[i]);
      int x, y;
      ss >> x >> y;
      if (yvals.find(y) != yvals.end()) {
         data[y].insert(x);
      } else {
         set<int> xset;
         xset.insert(x);
         yvals.insert(y);
         data.insert(make_pair(y, xset));
      }
   }
}

int main() {
   int n;
   cin >> n;
   vector<string> input;
   cin.ignore();
   for (int i = 0; i < n; i++) {
      string str;
      getline(cin, str);
      input.push_back(str);
   }
   fun(input);
   return 0;
}
