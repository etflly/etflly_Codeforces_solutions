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

int n;

void read()
{
    cin >> n;
}

void solve()
{
}

void print()
{
    cout << n / 5 + (n % 5 != 0) << endl;
}

int main()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
#ifndef ONLINE_JUDGE
    //assert(freopen("A.in", "r", stdin));
    //assert(freopen("A.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
