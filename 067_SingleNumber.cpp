// Topic: Bit Manipulation
// Single Number: XOR all numbers to find unique element
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums)
{
    int x = 0;
    for (int v : nums) x ^= v;
    return x;
}

int main()
{
    cout << singleNumber((vector<int>{2, 2, 1})) << "\n";        // 1
    cout << singleNumber((vector<int>{4, 1, 2, 1, 2})) << "\n";  // 4
    return 0;
}
