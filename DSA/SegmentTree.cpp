#include <bits/stdc++.h>
using namespace std;

#include <chrono>
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

void printExecutionTime(ClockTime start_time, ClockTime end_time)
{
    // auto execution_time_ns = duration_cast<nanoseconds>(end_time - start_time).count();
    // auto execution_time_ms = duration_cast<microseconds>(end_time - start_time).count();
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
    // cerr << execution_time_ns << '\n';
    auto execution_time_ms = duration_cast<microseconds>(end_time - start_time).count();
    cerr << execution_time_ms << '\n';
}
#define ll long long
class SegmentTree
{
private:
    const static int N = 1e5 + 5; // limit for array size
    int n;                        // array size
public:
    ll t[2 * N];
    void build()
    { // build the tree
        for (int i = n - 1; i > 0; --i)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void modify(int p, ll value)
    { // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }

    ll query(int l, int r)
    { // sum on interval [l, r)
        ll res = 0LL;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }
    SegmentTree()
    {
        memset(t, 0LL, sizeof t);
    };
    SegmentTree(int n) : SegmentTree()
    {
        this->n = n;
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
    SegmentTree st = SegmentTree(n);
    for (int i = 0; i < n; ++i)
        cin >> st.t[i + n];
    st.build();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l - 1, r) << '\n';
    }

    // Put the function here

    ClockTime end_time = Clock::now();

    printExecutionTime(start_time, end_time);
}
