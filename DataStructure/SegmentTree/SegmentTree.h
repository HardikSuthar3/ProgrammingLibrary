#include<bits/stdc++.h>

using namespace std;

/// A recursive function to get the sum of values in given range
/// of the array. The following are parameters for this function.
/// ss & st -> Starting and ending indexes of the segment represented by current node, i.e., st[si]
/// si -> index of current node in the segment tree. Initially 0 is passed as root is always at index 0
/// qs & qe  -> Starting and ending indexes of query range
int getSum_util(vector<int> &st, int ss, int se, int qs, int qe, int si) {

    // If segment of this node is a part of given range, then return the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;

    // If a part of this segment overlaps with the given range
    int mid = ss + (se - ss) / 2;
    return getSum_util(st, ss, mid, qs, qe, 2 * si + 1) + getSum_util(st, mid + 1, se, qs, qe, 2 * si + 2);
}

/// Return sum of elements in range from index qs (quey start) to qe (query end).
/// \param st: Segment Tree
int getSum(vector<int> &st, int n, int qs, int qe) {
    if (qs < 0 || qe > n - 1) {
        return -1;
    }
    return getSum_util(st, 0, n - 1, qs, qe, 0);
}


/// A recursive function to update the nodes which have the given
/// index in their range. The following are parameters
/// st, si, ss and se are same as getSumUtil()
/// i    --> index of the element to be updated. This index is in input array.
/// diff --> Value to be added to all nodes which have i in range
void updateValue_util(vector<int> &st, int ss, int se, int i, int diff, int si) {

    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;

    // If the input index is in range of this node, then update
    // the value of the node and its children

    st[si] += diff;
    if (ss != se) {
        int mid = ss + (se - ss) / 2;
        updateValue_util(st, ss, mid, i, diff, 2 * si + 1);
        updateValue_util(st, mid + 1, se, i, diff, 2 * si + 2);
    }
}


/// The function to update a value in input array and segment tree.
/// It uses updateValueUtil() to update the value in segment tree
void updateValue(vector<int> &a, vector<int> &st, int i, int new_val) {
    int n = a.size();

    // Check for erroneous input index
    if (i < 0 || i > n - 1) {
        return;
    }

    // Get the difference between new value and old value
    int diff = new_val - a[i];

    // Update Value in array
    a[i] = new_val;

    //update Values  of Nodes in segment tree
    updateValue_util(st, 0, n - 1, i, diff, 0);
}


/// A recursive function that constructs Segment Tree for array[ss..se].
/// si is index of current node in segment tree st
int constructSegmentTree_util(vector<int> &a, int ss, int se, vector<int> &st, int si) {
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se) {
        st[si] = a[ss];
        return a[ss];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = ss + (se - ss) / 2;
    st[si] = constructSegmentTree_util(a, ss, mid, st, 2 * si + 1) +
             constructSegmentTree_util(a, mid + 1, se, st, 2 * si + 2);
    return st[si];
}

vector<int> createSegmentTree(vector<int> &a) {
    int h = (int) (ceil(log2(a.size())));
    int maxSize = 2 * (int) pow(2, h) - 1;
    vector<int> st(maxSize);
    constructSegmentTree_util(a, 0, a.size() - 1, st, 0);
    return st;
}

