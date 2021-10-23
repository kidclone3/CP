#include <bits/stdc++.h>

#define int long long
const int maxM = 1e5+5;

int house[maxM], busStops[maxM];

using namespace std;
int32_t main() {
    int endPoint, numberHouses, numberStops, taxiFee, busFee;
    cin >> endPoint >> numberHouses >> numberStops >> taxiFee >> busFee;
    
    house[0] = busStops[0] = 1;
    house[numberHouses+1] = busStops[numberStops+1] = endPoint;
    busStops[numberStops+2] = LLONG_MAX;
    for(int i = 1; i < numberHouses+1; ++i) cin >> house[i];
    for(int i = 1; i < numberStops+1; ++i) cin >> busStops[i];

// Tram xe buyt thi ko dung con tro dc, chi co the la lower/--lower_bound.

// Return the nearest bus Stop (by distance).
    auto findNearestStop = [&] (int x) -> int {
        auto Stop1 = lower_bound(busStops, busStops + numberStops+1, x);
        auto Stop2 = Stop1;
        if (Stop2 - busStops > 0) Stop2--;
        // return abs(*Stop1 - x) <= abs(*Stop2 - x) ? *Stop1 : *Stop2;
        return min(abs(*Stop1 -x), abs(*Stop2 - x));
    };

    int ans = 0LL;
    for(int i = 1; i <= numberHouses+1; ++i) {
        int taxi = taxiFee * abs(house[i] - house[i-1]);
        int bus2 = findNearestStop(house[i]);
        int bus1 = findNearestStop(house[i-1]);
        // int bus = taxi;
        // bus = taxiFee*(abs(bus1-house[i-1]) + abs(bus2-house[i])) + busFee;
        int bus = (bus1 + bus2) * taxiFee + busFee;
        ans += min(taxi, bus);
    }
    cout << ans;
    return 0;
}
    