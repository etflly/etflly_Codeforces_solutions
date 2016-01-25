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

const int MAXN = 100;

int n;
int a[MAXN];

long long ans;

void read()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
}

void solve()
{
    ans = 1;
    int cnt = 1;
    int i = 0;
    for (; i < n; ++i) if (a[i]) break;
    if (i == n) {
        ans = 0;
        return;
    }
    for (; i < n; ++i) {
        if (a[i]) {
            ans *= cnt;
            cnt = 1;
        }
        else {
            ++cnt;
        }
    }
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
    assert(freopen("B.in", "r", stdin));
    //assert(freopen("B.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
