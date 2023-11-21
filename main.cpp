#include <bits/stdc++.h>

using namespace std;

long long binaryToDecimalLarge(string binaryString)
{
    bitset<1000000> binary(binaryString);
    long long decimal = binary.to_ullong();
    return decimal;
}

string leftRotatedString(string s, int d)
{
    string ans = s.substr(d) + s.substr(0, d);
    return ans;
}

string rightRotatedString(string s, int d)
{
    string ans = s.substr(s.length() - d) + s.substr(0, s.length() - d);
    return ans;
}

int main()
{

    // Read File Input
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;   
    }
    return 0;
}