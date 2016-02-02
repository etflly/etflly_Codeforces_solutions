#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXXY = 1e3;
const int MAXN = 2e5;

int n;
unordered_map<int, int> d1;
unordered_map<int, int> d2;
long long ans;

void read()
{
}

void solve()
{
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        ans += d1[x+y]++;
        ans += d2[x-y]++;
    }
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
    assert(freopen("B.in", "r", stdin));
    //assert(freopen("B.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
