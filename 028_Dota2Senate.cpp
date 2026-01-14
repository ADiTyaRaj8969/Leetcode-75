// Topic: Queue / Simulation
// Dota2 Senate: Predict which party (Radiant or Dire) will win using queue simulation.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate)
{
    int n = senate.size();
    queue<int> r, d;
    for (int i = 0; i < n; ++i)
    {
        if (senate[i] == 'R')
            r.push(i);
        else
            d.push(i);
    }
    while (!r.empty() && !d.empty())
    {
        int ri = r.front();
        r.pop();
        int di = d.front();
        d.pop();
        if (ri < di)
            r.push(ri + n);
        else
            d.push(di + n);
    }
    return r.empty() ? string("Dire") : string("Radiant");
}

int main()
{
    cout << predictPartyVictory("RD") << '\n';   // Radiant
    cout << predictPartyVictory("RDD") << '\n';  // Dire
    cout << predictPartyVictory("RDRDR") << '\n';
    return 0;
}
