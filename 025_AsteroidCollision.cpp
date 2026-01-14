// Topic: Stack / Simulation
// Asteroid Collision: Simulate asteroids colliding in a row; smaller ones explode.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids)
{
    vector<int> st;
    for (int a : asteroids)
    {
        bool alive = true;
        while (alive && a < 0 && !st.empty() && st.back() > 0)
        {
            if (st.back() < -a)
            {
                st.pop_back();
                continue;
            }
            if (st.back() == -a)
                st.pop_back();
            alive = false;
        }
        if (alive)
            st.push_back(a);
    }
    return st;
}

int main()
{
    vector<int> a1 = {5, 10, -5};
    auto r1 = asteroidCollision(a1);
    for (int x : r1) cout << x << ' ';
    cout << "\n";  // 5 10

    vector<int> a2 = {8, -8};
    auto r2 = asteroidCollision(a2);
    for (int x : r2) cout << x << ' ';
    cout << "\n";  // (empty)

    vector<int> a3 = {10, 2, -5};
    auto r3 = asteroidCollision(a3);
    for (int x : r3) cout << x << ' ';
    cout << "\n";  // 10
    return 0;
}
