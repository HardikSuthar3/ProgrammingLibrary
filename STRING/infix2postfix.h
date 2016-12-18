#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    switch(ch) {
        case '*':
        case '/':
        case '+':
        case '-':
        case '^':
            return true;
        default:
            return false;
    }
}

void generatePostfix(string str) {
    unordered_map<char, int> prio;
    prio.insert(make_pair('^', 5));
    prio.insert(make_pair('/', 4));
    prio.insert(make_pair('*', 3));
    prio.insert(make_pair('+', 2));
    prio.insert(make_pair('-', 1));
    prio.insert(make_pair('(', 0));
    stack<char> s;
    string output;
    int i = 0;
    while(i < str.length()) {
        if(isOperator(str[i])) {
            while((!s.empty()) && (prio[s.top()] >= prio[str[i]])) {
                output += s.top();
                s.pop();
            }
            s.push(str[i]);
        } else if(str[i] == '(') {
            s.push(str[i]);
        } else if(str[i] == ')') {
            while(s.top() != '(' && (!s.empty())) {
                output += s.top();
                s.pop();
            }
            if(!s.empty() && s.top() == '(') {
                s.pop();
            }
        } else {
            output += str[i];
        }
        i++;
    }
    cout << output;
}