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

const int MAXN = 2e3;
const int MAXNN = MAXN * MAXN;

int n, m, nn, mm;
int a[MAXN], b[MAXN];

pair<long long, int> A1[MAXN], B1[MAXN];
pair<long long, pair<int, int>> A2[MAXNN], B2[MAXNN];
long long v;

int k;
long long bestv;
pair<int, int> res[2];

void init()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
}

void read()
{
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    cin >> m;
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
}

void solve()
{
    for (int i = 0; i < n; ++i) {
        v += a[i];
        A1[i] = {-2*(long long)a[i], i};
    }
    for (int i = 0; i < m; ++i) {
        v -= b[i];
        B1[i] = {2*(long long)b[i], i};
    }
    bestv = abs(v);
#ifdef DEBUG
    cout << "v=" << v << " bestv=" << bestv << endl;
#endif
    k = 0;
    sort(A1, A1+n);
    sort(B1, B1+m);
#ifdef DEBUG
    for (int i = 0; i < n; ++i) printf("%d ", A1[i]);
    printf("\n");
    for (int i = 0; i < m; ++i) printf("%d ", B1[i]);
    printf("\n");
#endif
    int j = 0;
    for (int i = n-1; i >= 0 ; --i) {
        while(j < m-1 && abs(v + A1[i].first + B1[j].first) >= abs(v + A1[i].first + B1[j+1].first)) ++j;
        if (abs(v + A1[i].first + B1[j].first) < bestv) {
            bestv = abs(v + A1[i].first + B1[j].first);
#ifdef DEBUG
            printf("x=%d y=%d bestv=%d\n", A1[i].second, B1[j].second, bestv);
#endif
            k = 1;
            res[0] = {A1[i].second, B1[j].second};
        }
    }
    if (n == 1 || m == 1) return;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            A2[nn] = {-2*(long long)(a[i]+a[j]), {i, j}};
            ++nn;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            B2[mm] = {2*(long long)(b[i]+b[j]), {i, j}};
            ++mm;
        }
    }
    sort(A2, A2+nn);
    sort(B2, B2+mm);
    j = 0;
    for (int i = nn-1; i >= 0 ; --i) {
        while(j < mm-1 && abs(v + A2[i].first + B2[j].first) >= abs(v + A2[i].first + B2[j+1].first)) ++j;
        if (abs(v + A2[i].first + B2[j].first) < bestv) {
            bestv = abs(v + A2[i].first + B2[j].first);
#ifdef DEBUG
            //printf("i=%d j=%d a=%lld b=%lld x1=%d y1=%d x2=%d y2=%d bestv=%d\n", i, j, A2[i].first, B2[i].first, A2[i].second.first, B2[j].second.first, A2[i].second.second, B2[j].second.second, bestv);
#endif
            k = 2;
            res[0] = {A2[i].second.first, B2[j].second.first};
            res[1] = {A2[i].second.second, B2[j].second.second};
        }
    }
}

void print()
{
    cout << bestv << endl;
    cout << k << endl;
    for (int i = 0; i < k; ++i) printf("%d %d\n", res[i].first+1, res[i].second+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    assert(freopen("D.in", "r", stdin));
    //assert(freopen("D.out", "w", stdout));
#endif
    init();
    read();
    solve();
    print();
}
