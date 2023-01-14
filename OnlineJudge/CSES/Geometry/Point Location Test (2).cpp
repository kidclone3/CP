#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef double T;
struct point {
  T x, y;
  point() {}
  point(T _x, T _y) : x(_x), y(_y) {}
  point operator+(point p) { return {x + p.x, y + p.y}; }
  point operator-(point p) { return {x - p.x, y - p.y}; }
  point operator*(T d) { return {x * d, y * d}; }
  point operator/(T d) { return {x / d, y / d}; }
  T cross(point v, point w) { return v.x * w.y - v.y * w.x; }
  T orient(point v, point w) { return cross(v - *this, w - *this); }
};

int solve() {
  vector<point> a(3);
  for (int i = 0; i < 3; ++i) {
    ll x, y;
    cin >> x >> y;
    a[i] = point(x, y);
  }
  int tmp = a[0].orient(a[1], a[2]);
  if (tmp > 0)
    cout << "LEFT";
  else if (tmp < 0)
    cout << "RIGHT";
  else
    cout << "TOUCH";
  cout << "\n";
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
