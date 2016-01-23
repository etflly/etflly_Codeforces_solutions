#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
//#define DEBUG
#endif

using namespace std;

const int INF = 1e9;
const long long INFL = 1e18;
const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXN = 3e5;

int n;
int a[MAXN];
map<int, int> h;
int ans;
pair<int, int> res[MAXN];

void init()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
}

void read()
{
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
}

void solve()
{
    ans = 0;
    h.clear();
    int j = 0;
    for (int i = 0; i < n; ++i) {
#ifdef DEBUG
        printf("A[%d] %d\n", a[i], h.count(a[i]));
#endif
        if (h.count(a[i])) {
            res[ans] = {j+1, i+1};
            j = i + 1;
            h.clear();
            ++ans;
        }
        else {
            h[a[i]] = i;
        }
    }
    if (ans != 0) res[ans-1].second = n;
    
}

void print()
{
    if (ans == 0) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    assert(freopen("C.in", "r", stdin));
    //assert(freopen("C.out", "w", stdout));
#endif
    init();
    read();
    solve();
    print();
}
