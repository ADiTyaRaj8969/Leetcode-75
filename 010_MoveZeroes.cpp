// Topic: Two Pointers / Array
// Move Zeroes: Shift all zero elements to the end of an array, maintaining other elements' order.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    int last = 0;  // index to place next non-zero
    for (int i = 0; i < (int)nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            nums[last++] = nums[i];
        }
    }
    while (last < (int)nums.size()) nums[last++] = 0;
}

int main()
{
    vector<int> a1 = {0, 1, 0, 3, 12};
    moveZeroes(a1);
    for (int x : a1) cout << x << ' ';
    cout << "\n";  // 1 3 12 0 0

    vector<int> a2 = {0};
    moveZeroes(a2);
    for (int x : a2) cout << x << ' ';
    cout << "\n";  // 0

    vector<int> a3 = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    moveZeroes(a3);
    for (int x : a3) cout << x << ' ';
    cout << "\n";  // 4 2 4 3 5 1 0 0 0 0

    return 0;
}
