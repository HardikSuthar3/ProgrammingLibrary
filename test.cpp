#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> a(N);
    // priority_queue<int, vector<int>, std::greater<int>> pq, t_pq;
    priority_queue<int, vector<int>, std::less<int>> pq, t_pq;

    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
        pq.push(a[i]);
    }

    for (size_t i = 0; i < N; i++)
    {
        t_pq.push(a[i]);

        while (!pq.empty() && !t_pq.empty() && (pq.top() == t_pq.top()))
        {
            cout << t_pq.top() << " ";
            pq.pop();
            t_pq.pop();
        }

        cout << endl;
    }

    return 0;
}