#include<bits/stdc++.h>
using namespace std;


#include <chrono>
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

void printExecutionTime(ClockTime start_time, ClockTime end_time)
{
    auto execution_time_ns = duration_cast<nanoseconds>(end_time - start_time).count();
    auto execution_time_ms = duration_cast<microseconds>(end_time - start_time).count();
    auto execution_time_sec = duration_cast<seconds>(end_time - start_time).count();
    auto execution_time_min = duration_cast<minutes>(end_time - start_time).count();
    auto execution_time_hour = duration_cast<hours>(end_time - start_time).count();

    cerr << "\nExecution Time: ";
    if (execution_time_hour > 0)
        cerr << "" << execution_time_hour << " Hours, ";
    if (execution_time_min > 0)
        cerr << "" << execution_time_min % 60 << " Minutes, ";
    if (execution_time_sec > 0)
        cerr << "" << execution_time_sec % 60 << " Seconds, ";
    if (execution_time_ms > 0)
        cerr << "" << execution_time_ms % long(1E+3) << " MicroSeconds, ";
    if (execution_time_ns > 0)
        cerr << "" << execution_time_ns % long(1E+6) << " NanoSeconds, ";
}

#define ll long long
const int N = 1e5+5;
ll ST[4*N];
void update(int id, int l, int r, int i, ll v) {
    if (i < l || r < i) {
        return ;
    }
    if (l == r) {
        ST[id] = v;
        return ;
    }

    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);

    ST[id] = ST[id*2] + ST[id*2 + 1];
}

ll get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return 0LL;
    }
    if (u <= l && r <= v) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("out3.txt", "w", stdout);
    
    ClockTime start_time = Clock::now();
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        update(1, 0, n, i, a[i]);
    }
    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        cout << get(1, 0, n, l-1, r-1) << "\n";
    }

    //Put the function here

    ClockTime end_time = Clock::now();

    printExecutionTime(start_time, end_time);
}
