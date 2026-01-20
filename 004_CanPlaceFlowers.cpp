// Topic: Greedy / Array
// Can Place Flowers: Determine if n new flowers can be planted in a flowerbed without adjacent
// planting. Time Complexity: O(m) where m = flowerbed.size() Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    int m = flowerbed.size();
    for (int i = 0; i < m && n > 0; ++i)
    {
        if (flowerbed[i] == 0)
        {
            bool left = (i == 0) || (flowerbed[i - 1] == 0);
            bool right = (i == m - 1) || (flowerbed[i + 1] == 0);
            if (left && right)
            {
                flowerbed[i] = 1;
                --n;
            }
        }
    }
    return n <= 0;
}

int main()
{
    vector<int> f1 = {1, 0, 0, 0, 1};
    cout << (canPlaceFlowers(f1, 1) ? "true" : "false") << '\n';  // true
    vector<int> f2 = {1, 0, 0, 0, 1};
    cout << (canPlaceFlowers(f2, 2) ? "true" : "false") << '\n';  // false
    vector<int> f3 = {0, 0, 1, 0, 0};
    cout << (canPlaceFlowers(f3, 2) ? "true" : "false") << '\n';  // true
    return 0;
}
