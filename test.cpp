// Find subarray of a vector with length K and given sum S
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cassert>
using namespace std;

// Find subarray of a vector with length K and given sum S
// Time complexity: O(n)
// Space complexity: O(1)
vector<int> findSubarray(const vector<int> &v, int K, int S)
{
    int n = v.size();
    int i = 0, j = 0;
    int sum = 0;
    while (j < n)
    {
        sum += v[j];
        if (j - i + 1 == K)
        {
            if (sum == S)
                return vector<int>(v.begin() + i, v.begin() + j + 1);
            sum -= v[i];
            i++;
        }
        j++;
    }
    return {};
}
int main()
{

    // Read Vector of N integers from stdin
    int N;

    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int K = 3;
    int S = 15;
    auto res = findSubarray(v, K, S);
    // copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << res.size() << endl;
    return 0;
}