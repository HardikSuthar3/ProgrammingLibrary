#include "bits/stdc++.h"
using namespace std;

int partition(vector<int> &a, int start, int end)
{
    int piv;
    piv = a[start];
    int i = start + 1;
    for (int j = start + 1; j <= end; j++)
    {
        if (a[j] < piv)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[start], a[i - 1]);
    return (i - 1);
}

void qs(vector<int> &a, int start, int end)
{
    if (start >= end || end <= start)
        return;
    auto pos = partition(a, start, end);
    qs(a, start, pos - 1);
    qs(a, pos + 1, end);
}

int main()
{
    vector<int> a;
    for (size_t i = 0; i < 10; i++)
    {
        a.push_back(rand() % 93);
    }

    for (auto &&i : a)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    qs(a, 0, a.size());
    cout << endl
         << endl;

    for (auto &&i : a)
    {
        cout << i << " ";
    }

    return 0;
}
