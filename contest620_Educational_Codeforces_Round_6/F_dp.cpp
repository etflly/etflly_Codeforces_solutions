// DP
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
//#define DEBUG
#endif

using namespace std;

const int INF = 1e9;
const long long INFL = 1e18;
const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXN = 5e4;
const int MAXM = 5e3;
const int MAXA = 1e6;
const int LOGA = 19;

int n, m;
int a[MAXN];
pair<int, int> q[MAXM];

int f[MAXA+1];
int fa[MAXN];
int d[MAXN];

int ans[MAXM];

void read()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) scanf("%d", a+i);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].first, &q[i].second);
        --q[i].first; --q[i].second;
    }
}

void solve()
{
    f[0] = 0;
    for (int i = 1; i <= MAXA; ++i) f[i] = f[i-1] ^ i;
    for (int i = 0; i < n; ++i) fa[i] = f[a[i]];

    for (int i = 0; i < n; ++i) {
        d[i] = a[i];
        for (int j = i+1; j < n; ++j) {
            d[j] = max(d[j-1], fa[i] ^ fa[j] ^ min(a[i], a[j]));
        }
        for (int j = 0; j < m; ++j) {
            if (q[j].first <= i && i <= q[j].second) ans[j] = max(ans[j], d[q[j].second]);
        }
    }
}

void print()
{
    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    assert(freopen("F.in", "r", stdin));
    //assert(freopen("F.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
