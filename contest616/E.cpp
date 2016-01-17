// Longest k-Good Segment
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const long long MP = 1e9+7;

long long n, m;
long long ans;

int main()
{
    cin >> n >> m;
    ans = (n % MP) * (m % MP) % MP;
    for (long long k = 1; k <= m; ++k) {
        if (k * k > n) break;
        long long r = n % k;
        long long nk = n / k;
        long long l = (nk - r - 1) / (k +1);
        ans = (ans + MP - nk * k % MP) % MP;
        if (nk - l > m) continue;
        if (nk > m) {
            l = m - (nk - l);
            nk = m;
        }
        //if (k * k >= n) break;
        if (k == nk) continue;
        k %= MP; r %= MP; nk %= MP; l %= MP;
        ans = (ans + MP - (((l + 1)*(nk + nk -l) / 2 %MP) * k) % MP) % MP;
    }
    cout << ans << endl;
#ifndef ONLINE_JUDGE
    long long ans1 = 0;
    for (int i = 1; i <= m; ++i)
        ans1 = (ans1 + n % i) % MP;
    cout << ans1 << endl;
#endif
}
