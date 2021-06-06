#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Binary_Search(int arr[], int left, int right, int value)
{

    if (right >= left)
    {
        int mid = (left) + (right - left) / 2;

        if (arr[mid] == value)
            return mid;

        if (value < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        return Binary_Search(arr, left, right, value);
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = Binary_Search(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result << endl;
    return 0;
}