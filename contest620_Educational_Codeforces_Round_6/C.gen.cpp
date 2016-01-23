#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long INFL = 1e18;
const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXN = 3e5;
const int MAXA = 1e9;

int n;

int main()
{
    assert(freopen("C.in", "w", stdout));
    srand((unsigned)time(NULL));
    cout << setprecision(18) << fixed;

    int n = MAXN;
    cout << n << endl;
    for (int i = 0; i < n; ++i) printf("%d ", rand()%MAXA);
    printf("\n");
}
