// Topic: Design / Heap + Set
// Smallest Number in Infinite Set: Implement a class that can pop the smallest number and add
// numbers back. Time Complexity: popSmallest O(log n) worst, addBack O(log n) Space Complexity:
// O(n)

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> inSet;
    int next;

   public:
    SmallestInfiniteSet() : next(1) {}
    int popSmallest()
    {
        if (!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            inSet.erase(x);
            return x;
        }
        return next++;
    }
    void addBack(int num)
    {
        if (num < next && inSet.insert(num).second)
            pq.push(num);
    }
};

int main()
{
    SmallestInfiniteSet s;
    cout << s.popSmallest() << "\n";  // 1
    cout << s.popSmallest() << "\n";  // 2
    s.addBack(1);
    cout << s.popSmallest() << "\n";  // 1
    cout << s.popSmallest() << "\n";  // 3
    s.addBack(2);
    cout << s.popSmallest() << "\n";  // 2
    return 0;
}
