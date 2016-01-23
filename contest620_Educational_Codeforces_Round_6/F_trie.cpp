#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
//#define DEBUG
//#define DEBUG_BL
#endif

using namespace std;

const int INF = 1e9;
const long long INFL = 1e18;
const double EP = 1e-9;
const double PI = 3.141592653589793284626433832795;
const int MP = 1e9+7;

const int MAXN = 5e4;
const int MAXM = 5e3;
const int MAXA = 1e6;
const int LOGA = 20;
const int MAXT = 2 * MAXN * LOGA;
#ifndef DEBUG
const int BLK = 300;
#else
const int BLK = 3;
#endif

struct Query {
    int l, r;
    int id;
    int ans;

    Query(): l(-1), r(-1), id(-1), ans(INT_MIN) {}

    inline bool operator<(const Query& b) {
        int x = l / BLK;
        int y = b.l / BLK;
        if (x < y) return true;
        if (x > y) return false;
        return r < b.r;
    }

    inline void update_ans(int v) { ans = max(ans, v); }
};

struct TrieNode {
    int max;
    int min;
    TrieNode *son[2];

    TrieNode(): max(INT_MIN), min(INT_MAX) {
        son[0] = son[1] = NULL; 
    }

    inline void clear() {
        max = INT_MIN; min = INT_MAX;
        son[0] = son[1] = NULL;
    }
    
    inline void update_max(int v) { max = ::max(max, v); }

    inline void update_min(int v) { min = ::min(min,v); }
};

struct Trie {
    int n;
    TrieNode nd[MAXT];

    Trie(): n(0) {};

    inline void clear() {
        n = 1;
        nd[0].clear();
    }

    inline TrieNode *new_node() {
        nd[n].clear();
        return &nd[n++];
    }

    void insert(int v);

    int calc(int v);
};

int n, m;
int a[MAXN];
Query q[MAXM];

int f[MAXA+1];
int bl[MAXN];

Trie trie;

int res[MAXM];

void Trie::insert(int v) {
    // v as right end, add <f[v]> to trie, update max
    int x = f[v];
    TrieNode *now = &nd[0];
    now->update_max(v);
    for (int k = LOGA-1; k >= 0; --k) {
        int d = (x >> k) & 1;
        if (now->son[d] == NULL)
            now->son[d] = new_node();
        now = now->son[d];
        now->update_max(v);
    }

    // v as left end, add <f[v-1]> to trie, update min
    x = f[v - 1];
    now = &nd[0];
    now->update_min(v);
    for (int k = LOGA-1; k >= 0; --k) {
        int d = (x >> k) & 1;
        if (now->son[d] == NULL)
            now->son[d] = new_node();
        now = now->son[d];
        now->update_min(v);
    }
}

int Trie::calc(int v) {
    int ret0 = INT_MIN, ret1 = INT_MIN;

    // v as right end, search !(f[v]) which < v
    int x = f[v];
    TrieNode *now = &nd[0];
    if (now->min < v) {
        ret0= 0;
        for (int k = LOGA-1; k >= 0; --k) {
            int d = ((x >> k) & 1) ^ 1;
            ret0 <<= 1;
            if (now->son[d] != NULL && now->son[d]->min < v) {
                ret0 |= 1;
                now = now->son[d];
            }
            else now = now->son[d ^ 1];
        }
    }

    // v as left end, search !(f[v-1]) which > v
    now = &nd[0];
    if (now->max > v) {
        ret1 = 0;
        x = f[v - 1];
        for (int k = LOGA-1; k >=0; --k) {
            int d = ((x >> k) & 1) ^ 1;
            ret1 <<= 1;
            if (now->son[d] != NULL && now->son[d]->max > v) {
                ret1 |= 1;
                now = now->son[d];
            }
            else now = now->son[d ^ 1];
        }
    }
    return max(max(ret0, ret1), v);
}

void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        --q[i].l; --q[i].r;
        q[i].id = i;
    }
}

void solve()
{
    f[0] = 0;
    for (int i = 0; i < MAXA; ++i) f[i] = f[i-1] ^ i;

    for (int i = 0; i < n; i += BLK) {
        trie.clear();
        int tmp = INT_MIN;
        for (int j = min(i + BLK - 1, n - 1); j >= i; --j) {
            trie.insert(a[j]);
            bl[j] = tmp = max(tmp, trie.calc(a[j]));
        }
    }
#ifdef DEBUG_BL
    for (int i = 0; i < n; ++i) printf("%d ", bl[i]);
    printf("\n");
#endif

    sort(q, q+m);

    int L = 0;
    int R = min(BLK, n);
    int now = R-1;
    int nowans = INT_MIN;
    trie.clear();
    for (int k = 0; k < m; ++k) {
        while (q[k].l >= R) {
            L = R; 
            R = min(R + BLK, n);
            now = R - 1;
            nowans = INT_MIN;
            trie.clear();
        }
#ifdef DEBUG
        cout << "===============================" << endl;
        cout << "k=" << k << " l=" << q[k].l << " r=" << q[k].r << " L=" << L << " R=" << R << endl;
#endif
        if (q[k].r < R) {
            for (int i = q[k].l; i <= q[k].r; ++i) {
                trie.insert(a[i]);
#ifdef DEBUG
//                cout << "k=" << k << " i=" << i << " max=" << trie.nd[0].max << " min=" << trie.nd[0].min << endl;
#endif
                q[k].update_ans(trie.calc(a[i]));
            }
            trie.clear();
        }
        else {
            q[k].update_ans(bl[q[k].l]);
            while (now < q[k].r) {
                ++now;
                trie.insert(a[now]);
                nowans = max(nowans, trie.calc(a[now]));
#ifdef DEBUG
//            cout << "k=" << k << " now=" << now << " max=" << trie.nd[0].max << " min=" << trie.nd[0].min << " ans=" << q[k].ans <<  endl;
#endif
            }
            q[k].update_ans(nowans);
            for (int i = q[k].l; i < R; ++i) {
                q[k].update_ans(trie.calc(a[i]));
#ifdef DEBUG
//            cout << "k=" << k << " i=" << i << " max=" << trie.nd[0].max << " min=" << trie.nd[0].min << " ans=" << q[k].ans <<  endl;
#endif
            }
        }
    }

    for (int k = 0; k < m; ++k) res[q[k].id] = q[k].ans;
}

void print()
{
    for (int k = 0; k < m; ++k) printf("%d\n", res[k]);
}

int main()
{
    cout << setprecision(18) << fixed;
    cerr << setprecision(5) << fixed;
#ifndef ONLINE_JUDGE
    assert(freopen("F.in", "r", stdin));
    //assert(freopen("F.out", "w", stdout));
#endif
    read();
    solve();
    print();
}
