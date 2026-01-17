// Topic: Binary Search / Greedy
// Minimize Max Distance to Gas Station: binary search on distance and check required stations.
// Time Complexity: O(n log R) where R is range precision
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int requiredStations(const vector<int>& stations, double D)
{
    int cnt = 0;
    for (int i = 1; i < stations.size(); ++i)
    {
        double dist = stations[i] - stations[i - 1];
        cnt += (int)(dist / D) - 1;  // careful with floor
    }
    return cnt;
}

double minmaxGasDist(vector<int>& stations, int k)
{
    double lo = 0, hi = stations.back() - stations.front();
    for (int it = 0; it < 60; ++it)
    {
        double mid = (lo + hi) / 2;
        int need = 0;
        for (int i = 1; i < stations.size(); ++i)
            need += (int)((stations[i] - stations[i - 1]) / mid) - 1;
        if (need > k)
            lo = mid;
        else
            hi = mid;
    }
    return hi;
}

int main()
{
    cout << fixed << setprecision(6)
         << minmaxGasDist((vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), 9) << "\n";
    cout << fixed << setprecision(6) << minmaxGasDist((vector<int>{0, 10}), 9) << "\n";
    return 0;
}
