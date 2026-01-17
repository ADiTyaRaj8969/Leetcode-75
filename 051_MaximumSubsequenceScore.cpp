// Topic: Heap / Greedy
// Maximum Subsequence Score: Choose k indices to maximize (sum of nums1[selected]) *
// min(nums2[selected]). Approach: sort indices by nums2 descending, keep a min-heap of nums1,
// maintain sum of top k nums1 values. Time Complexity: O(n log n) Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
{
    int n = nums1.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) { return nums2[a] > nums2[b]; });
    long long sum = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i : idx)
    {
        pq.push(nums1[i]);
        sum += nums1[i];
        if ((int)pq.size() > k)
        {
            sum -= pq.top();
            pq.pop();
        }
        if ((int)pq.size() == k)
            ans = max(ans, sum * (long long)nums2[i]);
    }
    return ans;
}

int main()
{
    cout << maxScore((vector<int>{1, 3, 3, 2}), (vector<int>{2, 1, 3, 4}), 3) << "\n";  // example
    cout << maxScore((vector<int>{4, 2, 3, 1, 1}), (vector<int>{7, 3, 5, 10, 9}), 1) << "\n";
    return 0;
}
