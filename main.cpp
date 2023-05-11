#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = add(1, 2, 3);
    return sum;
}

void heapify(vector<int> test)
{
    // Heapify the vector test.
    make_heap(test.begin(), test.end());
}
 
/* make heap from a vector of Integer */


int add(int x, int y, int z)
{
    // Add x, y, and z together and return the result.
    return x + y;
}