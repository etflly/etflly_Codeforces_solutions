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

const int MAXN = 2e3;

int n;
long long X1, Y1, X2, Y2;
long long x[MAXN], y[MAXN];

int sn[MAXN];
pair<long long, long long> d[MAXN];

long long r1, r2;

inline long long disqr(long long x1, long long y1, long long x2, long long y2) { return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2); }

void read()
{
    cin >> n >> X1 >> Y1 >> X2 >> Y2;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
}

void solve()
{
    for (int i = 0; i < n; ++i) {
        d[i].first = disqr(x[i], y[i], X1, Y1);
        d[i].second = disqr(x[i], y[i], X2, Y2);
    }
    sort(d, d+n);

    r1 = r2 = 0;
    for (int i = 0; i < n; ++i) r2 = max(r2, d[i].second);

    long long now1, now2;
    for (int i = 0; i < n; ++i) {
        now1 = d[i].first;
        now2 = 0;
        for (int j = i+1; j < n; ++j) {
            if (d[j].first > now1) now2 = max(now2, d[j].second);
        }
        if (now1+now2 < r1+r2) {
            r1 = now1;
            r2 = now2;
        }
    }
}

void print()
{
    cout << r1 + r2 << endl;
}

int main()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
#ifndef ONLINE_JUDGE
    assert(freopen("C.in", "r", stdin));
    //assert(freopen("C.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
