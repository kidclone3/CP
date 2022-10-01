#include <bits/stdc++.h>
using namespace std;

#include <chrono>
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

void printExecutionTime(ClockTime start_time, ClockTime end_time)
{
    // auto execution_time_ns = duration_cast<nanoseconds>(end_time - start_time).count();
    // cerr << execution_time_ns << '\n';
    auto execution_time_ms = duration_cast<microseconds>(end_time - start_time).count();
    cerr << execution_time_ms << '\n';
    // auto execution_time_sec = duration_cast<seconds>(end_time - start_time).count();
    // auto execution_time_min = duration_cast<minutes>(end_time - start_time).count();
    // auto execution_time_hour = duration_cast<hours>(end_time - start_time).count();

    // cerr << "\nExecution Time: ";
    // if (execution_time_hour > 0)
    //     cerr << "" << execution_time_hour << " Hours, ";
    // if (execution_time_min > 0)
    //     cerr << "" << execution_time_min % 60 << " Minutes, ";
    // if (execution_time_sec > 0)
    //     cerr << "" << execution_time_sec % 60 << " Seconds, ";
    // if (execution_time_ms > 0)
    //     cerr << "" << execution_time_ms % long(1E+3) << " MicroSeconds, ";
    // if (execution_time_ns > 0)
    //     cerr << "" << execution_time_ns % long(1E+6) << " NanoSeconds, ";
}

#define ll long long

class FenwickTree
{
private:
    int n;
    const static int N = 1e5 + 10;
    ll bit[N];

public:
    FenwickTree(int n)
    {
        this->n = n;
        memset(bit, 0, sizeof bit);
    }
    FenwickTree(vector<ll> &a) : FenwickTree(a.size() - 1)
    {
        for (int i = 1; i < (int)a.size(); ++i)
            update(i, a[i]);
    }

    void update(int u, ll v)
    {
        for (int i = u; i <= n; i += i & (-i))
            bit[i] += v;
    }
    ll get(int p)
    {
        ll ans = 0LL;
        for (int i = p; i > 0; i -= i & (-i))
            ans += bit[i];
        return ans;
    }
    ll get(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};

int main(int argc, char *argv[])
{
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
    freopen(argv[3], "a", stderr);

    ClockTime start_time = Clock::now();

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    FenwickTree fw = FenwickTree(a);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << fw.get(l, r) << '\n';
    }

    // Put the function here

    ClockTime end_time = Clock::now();

    printExecutionTime(start_time, end_time);
}
