#include <bits/stdc++.h>

using namespace std;

vector<int> breakingRecords(vector<int> scores)
{
    int min = scores[0];
    int max = scores[0];
    int minCount = 0;
    int maxCount = 0;

    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[i] < min)
        {
            min = scores[i];
            minCount++;
        }
        else if (scores[i] > max)
        {
            max = scores[i];
            maxCount++;
        }
    }

    vector<int> result;
    result.push_back(maxCount);
    result.push_back(minCount);
    return result;
}

int main()
{
    // Change stdin to read from a file
    freopen("input.txt", "r", stdin);
    // Change stdout to write to a file
    // freopen("output.txt", "w", stdout);

    // Read vector
    int n;
    cin >> n;
    vector<int> scores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    auto result = breakingRecords(scores);
    cout << endl;

    // Print vector
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}