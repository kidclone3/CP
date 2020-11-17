#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

int n,m;
int a[105][105];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input_3d.txt", "r", stdin);
    freopen("3d.inp", "r", stdin);
    freopen("3d.out", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, n+1)
        FOR(j, 1, m+1)
            cin >> a[i][j];
    int res = 0;
    FOR(i, 1, n+1){
        FOR(j, 1, m+1){
            int cur = a[i][j]*6 - (a[i][j]-1)*2;
            FOR(k, 0, 4){
                cur -= min(a[i+dx[k]][j+dy[k]], a[i][j]);
            }
            res +=cur;
        }
    }
    cout << res;
    return 0;
}
