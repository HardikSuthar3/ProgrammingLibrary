#include <bits/stdc++.h>
using namespace std;

#define MAX (int)1e5
int a[MAX];

// Index = Root Node
// N = Total Node
void Heapify(int index, int n)
{
    // Compare current node with parent
    int parent = (index - 1) / 2;
    if (a[index] > a[parent])
        swap(a[index], a[parent]);

    // Repeat for Childs
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < n)
        Heapify(left, n);

    if (right < n)
        Heapify(right, n);
}

void HeapSort(int root, int n)
{
    // 1. Heapify Tree
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < n)
        Heapify(left, n);

    if (right < n)
        Heapify(right, n);

    for (size_t i = 0; i < n - 1; i++)
    {
        // 2. Print Root
        cout << a[root] << " ";

        // 3. Swap Last Element With Root
        swap(a[root], a[n - i - 1]);

        // 4. Heapify with reduced size (n-i)
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n)
            Heapify(left, n - i);

        if (right < n)
            Heapify(right, n - i);
    }

    // 5. Repeat from Step 2
}

int main()
{
    freopen("t.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Read Inputs
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    HeapSort(0, n);

    return 0;
}