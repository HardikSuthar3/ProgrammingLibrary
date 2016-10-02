#include <bits/stdc++.h>
using namespace std;

int largestAreaHistogram(int *hist, int n) {

    stack<int> st;

    int area = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        if (st.empty() || hist[st.top()] <= hist[i])
            st.push(i);
        else {
            while (!st.empty() && hist[st.top()] > hist[i]) {
                int j = st.top();
                st.pop();
                area = hist[j] * (st.empty() ? i : i - 1 - st.top());
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
    }

    int i =n;
    while (!st.empty() && hist[st.top()] > hist[i]) {
        int j = st.top();
        st.pop();
        area = hist[j] * (st.empty() ? i : i - 1 - st.top());
        maxArea = max(maxArea, area);
    }

    return  maxArea;
}