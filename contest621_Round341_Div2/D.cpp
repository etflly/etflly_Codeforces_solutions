#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

long double x, y, z;
long double a[13];
long double ans;
string res[13] = {
    "",
    "x^y^z",
    "x^z^y",
    "(x^y)^z",
    "(x^z)^y",
    "y^x^z",
    "y^z^x",
    "(y^x)^z",
    "(y^z)^x",
    "z^x^y",
    "z^y^x",
    "(z^x)^y",
    "(z^y)^x"
};

void solve()
{
    cin >> x >> y >> z;
    a[1] = pow(y, z) * log(x);
    a[2] = pow(z, y) * log(x);
    a[3] = z * y * log(x);
    a[4] = a[3];
    a[5] = pow(x, z) * log(y);
    a[6] = pow(z, x) * log(y);
    a[7] = z * x * log(y);
    a[8] = a[7];
    a[9] = pow(x, y) * log(z);
    a[10] = pow(y, x) * log(z);
    a[11] = y * x * log(z);
    a[12] = a[11];
    ans = -DBL_MAX;
#ifdef DEBUG
    for (int i = 1; i <= 12; ++i) cout << res[i] << " = " << a[i] << endl;
#endif
    for (int i = 1; i <= 12; ++i) ans = max(ans, a[i]);
    for (int i = 1; i <= 12; ++i) if (ans == a[i]) {
        cout << res[i] << endl;
        break;
    }
}

int main()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
#ifndef ONLINE_JUDGE
    assert(freopen("D.in", "r", stdin));
    //assert(freopen("D.out", "w", stdout));
#endif
    solve();
}
