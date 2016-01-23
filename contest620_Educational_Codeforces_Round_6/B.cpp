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

const int d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int a, b;
int ans;

void init()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
}

void read()
{
    cin >> a >> b;
}

void solve()
{
    int k;
    for (int i = a; i <= b; ++i) {
        k = i;
        while (k!=0) {
            ans += d[k % 10];
            k /= 10;
        }
    }
}

void print()
{
    cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //assert(freopen("B.in", "r", stdin));
    //assert(freopen("B.out", "w", stdout));
#endif
    init();
    read();
    solve();
    print();
}
