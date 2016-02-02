#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

int n;
long long ans;

void read()
{
}

void solve()
{
    scanf("%d", &n);
    int min_odd = INT_MAX;
    int a;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if (a & 1 && a < min_odd) min_odd = a;
        ans += a;
    }
    if (ans & 1) ans -= min_odd;
    cout << ans << endl;
}

void print()
{
}

int main()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
#ifndef ONLINE_JUDGE
    assert(freopen("A.in", "r", stdin));
    //assert(freopen("A.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
