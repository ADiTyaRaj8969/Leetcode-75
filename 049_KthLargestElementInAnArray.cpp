// Topic: Selection / nth_element or heap
// Kth Largest Element in an Array: Find the k-th largest element.
// Time Complexity: O(n) average with nth_element, O(n log k) with heap
// Space Complexity: O(1) for nth_element, O(k) for heap

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k)
{
    // use nth_element
    nth_element(nums.begin(), nums.begin() + (k - 1), nums.end(), greater<int>());
    return nums[k - 1];
}

int main()
{
    vector<int> a1 = {3, 2, 1, 5, 6, 4};
    cout << findKthLargest(a1, 2) << "\n";  // 5
    vector<int> a2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(a2, 4) << "\n";  // 4
    return 0;
}
