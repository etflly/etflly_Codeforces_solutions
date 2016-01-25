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

pair<int, int> a[3];

void read()
{
    cin >> a[0].first >> a[0].second;
    cin >> a[1].first >> a[1].second;
    cin >> a[2].first >> a[2].second;
}

void solve()
{
    if (a[0].first == a[1].first && a[0].first == a[2].first) {
        cout << 1 << endl;
        return;
    }
    if (a[0].second == a[1].second && a[0].second == a[2].second) {
        cout << 1 << endl;
        return;
    }
    sort(a, a+3);
    if (a[0].first == a[1].first) {
        if (a[2].second >= a[1].second && a[2].second >= a[0].second ||
                a[2].second <= a[1].second && a[2].second <= a[0].second) {
            cout << 2 << endl;
            return;
        }
    }
    if (a[2].first == a[1].first) {
        if (a[0].second >= a[1].second && a[0].second >= a[2].second ||
                a[0].second <= a[1].second && a[0].second <= a[2].second) {
            cout << 2 << endl;
            return;
        }
    }
    sort(a, a+3, [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; });
    if (a[0].second == a[1].second) {
        if (a[2].first >= a[1].first && a[2].first >= a[0].first ||
                a[2].first <= a[1].first && a[2].first <= a[0].first) {
            cout << 2 << endl;
            return;
        }
    }
    if (a[2].second == a[1].second) {
        if (a[0].first >= a[1].first && a[0].first >= a[2].first ||
                a[0].first <= a[1].first && a[0].first <= a[2].first) {
            cout << 2 << endl;
            return;
        }
    }
    cout << 3 << endl;
}

void print()
{
}

int main()
{
#ifndef ONLINE_JUDGE
    //assert(freopen("D.in", "r", stdin));
    //assert(freopen("D.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
