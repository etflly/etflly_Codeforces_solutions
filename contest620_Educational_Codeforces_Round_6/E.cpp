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

const int MAXN = 4e5;
const int MAXM = 4e5;
const int MAXT = MAXN << 2;

struct Node;

struct Node {
    int l, r;
    int c;
    vector<int> nxt;

    Node(): l(-1), r(-1), c(0) { nxt.clear(); }
};

struct SegTreeNode {
    unsigned long long c;
    bool m;

    SegTreeNode(): c(0), m(false) {}

    inline void setColor(int x) { c = 1ULL << (x - 1); m = true; }
    
    inline void setColor(unsigned long long x) { c = x; m = true; }
};

int n, m;
Node nd[MAXN];

bool vis[MAXN];
int ln;

SegTreeNode st[MAXT];

void dfs(int i)
{
    vis[i] = true;
    nd[i].l = ln;
    ++ln;
    for (auto iter = nd[i].nxt.begin(); iter != nd[i].nxt.end(); ++iter) {
        if (!vis[*iter])
            dfs(*iter);
    }
    nd[i].r = ln - 1;
}

void recolor(int i, int L, int R, int l, int r, int c)
{
    int M = (L + R) >> 1;
    int ls = i << 1;
    int rs = ls + 1;
    if (l <= L && R <= r) {
        st[i].setColor(c);
#ifdef DEBUG
        //printf("[%d, %d]=>%llu(%d)\n", L, R, st[i].c, c);
#endif
        return;
    }
    if (st[i].m) {
        st[ls].setColor(st[i].c);
        st[rs].setColor(st[i].c);
        st[i].m = false;
    }
    if (l <= M) recolor(ls, L, M, l, r, c);
    if (M < r) recolor(rs, M+1, R, l, r, c);
    st[i].c = st[ls].c | st[rs].c;
#ifdef DEBUG
    //printf("[%d, %d]=>%llu(%llu %llu)\n", L, R, st[i].c, st[ls].c, st[rs].c);
#endif
}

unsigned long long query(int i, int L, int R, int l, int r)
{
    int M = (L + R) >> 1;
    int ls = i << 1;
    int rs = ls + 1;
    if (l <= L && R <= r) return st[i].c;
    if (st[i].m) {
        st[ls].setColor(st[i].c);
        st[rs].setColor(st[i].c);
        st[i].m = false;
    }
    unsigned long long ret = 0;
    if (l <= M) ret |= query(ls, L, M, l, r);
    if (M < r) ret |= query(rs, M+1, R, l, r);
    return ret;
}

inline int count(unsigned long long x) {
    int ret = 0; 
    while (x) { ret += x & 1; x >>= 1; }
    return ret;
}

void read()
{
    scanf("%d%d", &n, &m);
    int c;
    for (int i = 0; i < n; ++i) scanf("%d", &nd[i].c);
    int a, b;
    for (int i = 0; i < n-1; ++i) {
        scanf("%d%d", &a, &b);
        --a; --b;
        nd[a].nxt.push_back(b);
        nd[b].nxt.push_back(a);
    }
}

void solve()
{
    ln = 0;
    dfs(0);
    for (int i = 0; i < n; ++i) recolor(1, 0, n-1, nd[i].l, nd[i].l, nd[i].c);
#ifdef DEBUG
    for (int i = 0; i < n; ++i) printf("i=%d l=%d r=%d\n", i, nd[i].l, nd[i].r);
#endif

    int t, v, c;
    for (int k = 0; k < m; ++k) {
        scanf("%d", &t);
        switch(t) {
            case 1:
                scanf("%d%d", &v, &c);
#ifdef DEBUG
                printf("Q[%d] = (%d %d %d)\n", k, t, v, c);
#endif
                --v;
                recolor(1, 0, n-1, nd[v].l, nd[v].r, c);
                break;
            case 2:
                scanf("%d", &v);
#ifdef DEBUG
                printf("Q[%d] = (%d %d)\n", k, t, v);
#endif
                --v;
                printf("%d\n", count(query(1, 0, n-1, nd[v].l, nd[v].r)));
                break;
            default:
                cerr << "INPUT ERROR" << endl;
                return;
        }
    }
}

void print()
{
}

int main()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
#ifndef ONLINE_JUDGE
    assert(freopen("E.in", "r", stdin));
    //assert(freopen("E.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
