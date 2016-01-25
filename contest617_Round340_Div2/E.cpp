#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

const int INF = 1e9;
const long long INFL = 1e18;
const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXN = 1e5;
const int MAXM = 1e5;
const int MAXK = 1e6;
const int LOGA = 20;
const int MAXA = 1 << LOGA;
const int SQ = 300;

struct Query {
    int l, r;
    int id;

    inline bool operator<(const Query &b) {
        if (l / SQ == b.l / SQ) return r < b.r;
        return l / SQ < b.l / SQ;
    }
};

int n, m, k;
int a[MAXN + 1];
Query q[MAXM];
int f[MAXN + 1];

int cnt[MAXA];

long long ans[MAXM];

void read()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i] = f[i-1] ^ a[i];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        --q[i].l;
        q[i].id = i;
    }
    sort(q, q + m);
}

void solve()
{
    int L = 0, R = 0;
    long long now = 0;
    cnt[k] = 1;
    for (int i = 0; i < m; ++i) {
        while (R < q[i].r) {
            ++R;
            now += cnt[f[R]];
            ++cnt[f[R] ^ k];
        }
        while (R > q[i].r) {
            --cnt[f[R] ^ k];
            now -= cnt[f[R]];
            --R;
        }
        while (L > q[i].l) {
            --L;
            now += cnt[f[L]];
            ++cnt[f[L] ^ k];
        }
        while (L < q[i].l) {
            --cnt[f[L] ^ k];
            now -= cnt[f[L]];
            ++L;
        }
        ans[q[i].id] = now;
    }
}

void print()
{
    for (int i = 0; i < m; ++i)
        cout << ans[i] << endl;
}

int main()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
#ifndef ONLINE_JUDGE
    assert(freopen("E.in", "r", stdin));
    //assert(freopen("E.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
