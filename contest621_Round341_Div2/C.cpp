#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXN = 1e5;

int n, p;
int l[MAXN], r[MAXN];
int a[MAXN], b[MAXN];
double ans;

void read()
{
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]);
}

void solve()
{
    double a0 = r[0] / p - (l[0]-1) / p;
    double b0 = r[0] - l[0] + 1 - a0;
    double a, b;
    ans = 0;
    for (int i = 1; i < n; ++i) {
        a = r[i] / p - (l[i]-1) / p;
        b = r[i] - l[i] + 1 - a;
        ans += (a * (a0 + b0) + b * a0) / ((a + b) * (a0 + b0));
        a0 = a;
        b0 = b;
    }
    a = r[0] / p - (l[0]-1) / p;
    b = r[0] - l[0] + 1 - a;
    ans += (a * (a0 + b0) + b * a0) / ((a + b) * (a0 + b0));
    ans *= 2000;
}

void print()
{
    printf("%lf\n", ans);
}

int main()
{
    cout << setprecision(1) << fixed;
    cerr << setprecision(5) << fixed;
#ifndef ONLINE_JUDGE
    assert(freopen("C.in", "r", stdin));
    //assert(freopen("C.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
