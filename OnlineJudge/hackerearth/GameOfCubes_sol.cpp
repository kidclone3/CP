#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x)                                                                 \
  { cout << #x << ": " << (x) << endl; }
#define all(x) x.begin(), x.end()

int l, b;
int dirx[] = {1, 0, -1, 0};
int diry[] = {0, 1, 0, -1};
int vis[102][102];
char s[102][102];
vector<pair<int, int>> v;

void get(int x, int y) {
  if (x >= l || y >= b || x < 0 || y < 0)
    return;

  if (s[x][y] == '.' || vis[x][y])
    return;

  vis[x][y] = 1;
  s[x][y] = '.';
  v.pb(mp(x, y));
  int i;
  for (i = 0; i < 4; i++) {
    int nx = x + dirx[i];
    int ny = y + diry[i];
    get(nx, ny);
  }
}

void move() {
  int i, j;

  for (i = 0; i < l; i++) {
    for (j = 0; j < b; j++) {
      vis[i][j] = 0;
    }
  }

  for (i = 0; i < l; i++) {
    for (j = 0; j < b; j++) {
      if (s[i][j] == 'x' && !vis[i][j]) {
        v.clear();

        get(i, j);

        int x;

        int shift = l;

        for (x = 0; x < v.size(); x++) {
          cout << v[x].first << " " << v[x].second << '\n';
          int len = 0;
          for (len = v[x].first + 1; len < l && s[len][v[x].second] == '.';
               len++)
            ;
          // printf("%d\n", len - v[x].first - 1);
          shift = min(shift, len - v[x].first - 1);
        }

        for (x = 0; x < v.size(); x++) {
          s[v[x].first + shift][v[x].second] = 'x';
          vis[v[x].first + shift][v[x].second] = 1;
        }
      }
    }
  }
}

int main() {
  int i, j;
  int n;
  scanf("%d%d", &l, &b);
  assert(1 <= l && l <= 100);
  assert(1 <= b && b <= 100);
  for (i = 0; i < l; i++) {
    scanf("%s", s[i]);
    for (j = 0; j < b; j++) {
      assert(s[i][j] == '.' || s[i][j] == 'x');
    }
    assert(s[i][j] == 0);
  }
  scanf("%d", &n);
  assert(1 <= n && n <= 100);
  for (i = 0; i < n; i++) {
    int h;
    scanf("%d", &h);
    assert(1 <= h && h <= l);
    if (i & 1) {
      for (j = b - 1; j >= 0; j--) {
        if (s[l - h][j] == 'x')
          break;
      }
    } else {
      for (j = 0; j < b; j++) {
        if (s[l - h][j] == 'x')
          break;
      }
    }
    if (j != b)
      s[l - h][j] = '.';
    move();
  }
  for (i = 0; i < l; i++)
    printf("%s\n", s[i]);
  // system("pause");
  return 0;
}
