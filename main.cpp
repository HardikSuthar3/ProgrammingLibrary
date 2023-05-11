#include <bits/stdc++.h>
using namespace std;

// Heapify a subtree rooted with node i
// which is an index in arr[]. n is size of heap
void heapify(int arr[], int n)
{
    int i = n - 1;
    int parent = (i - 1) / 2;
    while (parent >= 0)
    {
        if (arr[parent] < arr[i])
        {
            swap(arr[parent], arr[i]);
            i = parent;
            parent = (i - 1) / 2;
        }
        else
            break;
    }
}

int main()
{
}