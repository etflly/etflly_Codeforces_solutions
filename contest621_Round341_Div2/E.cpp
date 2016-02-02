// O(x^2*logb)
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXX = 101;

int n, b, k, x;
int c[MAXX];
int d[MAXX];

void read()
{
    scanf("%d%d%d%d", &n, &b, &k, &x);
    int a;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++c[a%x];
    }
}

inline void add(int &ret, long long a)
{
    ret = (ret + a) % MP;
}

int mx(int *a, int *b, int len)
{
    int ret[MAXX] = {};
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < x; ++j)
            add(ret[(i * len + j) % x], (long long) a[i] * b[j]);
    for (int i = 0; i < x; ++i) a[i] = ret[i];
}

void solve()
{
    long long len = 10 % x;
    d[0] = 1;
    for (; b; b >>= 1) {
        if (b & 1) mx(d, c, len);
        mx(c, c, len);
        len = len * len % x;
#ifdef DEBUG
        cout << "len=" << len << endl;
        for (int i = 0; i < x; ++i) printf("%d ", c[i]);
        printf("\n");
        for (int i = 0; i < x; ++i) printf("%d ", d[i]);
        printf("\n");
#endif
    }
    cout << d[k] << endl;
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
}
