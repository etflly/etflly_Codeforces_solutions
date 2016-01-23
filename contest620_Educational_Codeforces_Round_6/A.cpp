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

int X1, Y1, X2, Y2;
int ans;

void init()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
}

void read()
{
    cin >> X1 >> Y1;
    cin >> X2 >> Y2;
}

void solve()
{
    ans = max(abs(X1 - X2), abs(Y1 - Y2));
}

void print()
{
    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //assert(freopen("A.in", "r", stdin));
    //assert(freopen("A.out", "w", stdout));
#endif
    init();
    read();
    solve();
    print();
}
