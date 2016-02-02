// O(x^3*logb)
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXA = 10;
const int MAXX = 101;

int n, b, k, x;
int c[MAXA];
int g[MAXX][MAXX];
int d[MAXX][MAXX];
int ans;

void read()
{
    scanf("%d%d%d%d", &n, &b, &k, &x);
    int a;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++c[a];
    }
}

int mx(int (*a)[MAXX], int (*b)[MAXX])
{
    int ret[MAXX][MAXX] = {};
    for (int i = 0; i < x; ++i)
        for (int t = 0; t < x; ++t)
            for (int j = 0; j < x; ++j)
                ret[i][j] = (ret[i][j] + (long long)a[i][t] * b[t][j]) % MP;
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < x; ++j)
            a[i][j] = ret[i][j];
}

void solve()
{
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < MAXA; ++j)
            g[i][(i*10 + j)%x] += c[j];

    for (int i = 0; i < x; ++i) d[i][i] = 1;
    for (int p = 1 << 30; p > 0; p >>= 1) {
        mx(d, d);
        if (b & p) mx(d, g);
    }
#ifdef DEBUG
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j)
            printf("%d ", d[i][j]);
        printf("\n");
    }
#endif
    ans = d[0][k];
}

void print()
{
    cout << ans << endl;
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
