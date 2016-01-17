// F. Expensive Strings
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <map>

//#define DEBUG
#define DEBUG_DFS
#define DEBUG_SON

using namespace std;

const int MAXN = 100001;
const int MAXS = 500001;
const int MAXNS = MAXN + MAXS;
const int MAXST = MAXNS * 2;

int n;
string s[MAXN];
int c[MAXN];
char buf[MAXS];
int len;
int a[MAXNS];
long long ans;

struct node {
    int l, r;
    int fa, lnk;
    map<int, int> sons;

    node (int l = 0, int r = 0, int fa = -1): l(l), r(r), fa(fa) {
        lnk = -1;
        sons.clear();
    }

    int len() { return r - l; }
};

struct v_node {
    int v;
    int len;

    v_node (int v = 0, int len = 0): v(v), len(len) {}
};

int stn;
node st[MAXST];
v_node active;
map<int, int> pos;

void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        s[i] = buf;
    }
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    len = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            a[len++] = s[i][j] - 'a';
        }
        pos[len] = c[i];
        a[len++] = 26 + i;
    }
}

inline bool vnode_full(v_node vnode)
{
    return vnode.len == st[vnode.v].len();
}

bool vnode_extend(v_node &vnode, int i)
{
#ifdef DEBUG_SON
    if (i==5352) {
        printf("i = %d, a[i] = %d, vnode = (%d %d)\n", i, a[i], vnode.v, vnode.len);
        printf("EXT:%d %d %d\n", vnode.v, vnode.len, vnode_full(vnode));
        printf("EXT2:%d %d\n", a[st[vnode.v].l+vnode.len], a[i]);
        printf("sons[a[i]] count %d\n", st[vnode.v].sons.count(a[i]));
        if (st[vnode.v].sons.count(a[i])) {
            printf("sons[a[i]] = %d\n", st[vnode.v].sons[a[i]]);
        }
    }
#endif
#ifdef DEBUG
    printf("EXT:%d %d %d\n", vnode.v, vnode.len, vnode_full(vnode));
#endif
    if (vnode_full(vnode)) {
        if (st[vnode.v].sons.count(a[i])) {
            vnode.v = st[vnode.v].sons[a[i]];
            vnode.len = 0;
        } else {
            return false;
        }
    }
#ifdef DEBUG
    printf("EXT2:%d %d\n", a[st[vnode.v].l+vnode.len], a[i]);
#endif
    if (a[st[vnode.v].l + vnode.len] == a[i]) {
        ++vnode.len;
    } else {
        return false;
    }
    return true;
}

int node_split(v_node vnode, int i)
{
    int mid = vnode.v;
#ifdef DEBUG
    printf("F:%d %d\n", vnode.v, vnode_full(vnode));
#endif
    if (!vnode_full(vnode)) {
        mid = stn++;
        int L = st[vnode.v].l;
        int M = L + vnode.len;
        st[mid] = node(L, M, st[vnode.v].fa);
        st[mid].lnk = 0;
#ifdef DEBUG
        printf("NEWM %d %d\n", mid, st[mid].fa);
#endif
        st[st[vnode.v].fa].sons[a[L]] = mid;
        st[vnode.v].l = M;
        st[vnode.v].fa = mid;
        st[mid].sons.clear();
        st[mid].sons[a[M]] = vnode.v;
    }
    st[stn] = node(i, len, mid);
#ifdef DEBUG
    printf("NEW %d %d\n", stn, st[stn].fa);
#endif
#ifdef DEBUG_SON
    if (i==5352) {
        printf("i = %d, a[i] = %d, mid = %d\n", i, a[i], mid);
    }
#endif
    st[mid].sons[a[i]] = stn;
    ++stn;
    return mid;
}

void st_extend(int i)
{
#ifdef DEBUG
    printf("------EXTEND %d: %d----\n", i, a[i]);
    printf("ACTIVE: %d %d\n", active.v, active.len);
#endif
    int last = -1;
    while (!vnode_extend(active, i)) {
#ifdef DEBUG
        printf("new ACTIVE: %d %d\n", active.v, active.len);
#endif
        int mid = node_split(active, i);
#ifdef DEBUG_SON
            if (i==5352 || i ==1568) {
                printf("%d OLD ACTIVE: %d %d\n", i, active.v, active.len);
            }
            if (last == 1998) {
                printf("LNK1998: i=%d, to=%d\n", i, mid);
            }
#endif
        if (last != -1) {
#ifdef DEBUG
            printf("LINK %d %d\n", last, mid);
#endif
            st[last].lnk = mid;
        }
        last = mid;
        if (active.v == 0) break;
#ifdef DEBUG
        printf("MID: %d %d\n", mid, st[mid].fa);
#endif
        if (st[mid].fa == 0) {
            if (active.len == 1) {
                active.v = 0;
                active.len = 0;
            } else {
                --active.len;
#ifdef DEBUG
                printf("CCCC : %d %d %d %d\n", mid, st[mid].fa, a[i-active.len], st[st[mid].fa].sons[a[i-active.len]]);
#endif
#ifdef DEBUG_SON
                if (!st[0].sons.count(a[i-active.len])) {
                    printf("ERROR! %d (%d)-> null\n", 0, a[i-active.len]);
                    printf("000 i=%d active=(%d %d) a=%d\n", i, active.v, active.len, a[i-active.len]);
                }
                if (i == 5352) printf("5352CCCC : %d %d %d %d\n", mid, st[mid].fa, a[i-active.len], st[st[mid].fa].sons[a[i-active.len]]);
#endif
                active.v = st[0].sons[a[i-active.len]];
            }
        }
        else {
#ifdef DEBUG
            printf("CCCC : %d %d %d %d %d\n", mid, st[mid].fa, st[st[mid].fa].lnk, a[i-active.len], st[st[st[mid].fa].lnk].sons[a[i-active.len]]);
#endif
#ifdef DEBUG_SON
            if (!st[st[st[mid].fa].lnk].sons.count(a[i-active.len])) {
                printf("ERROR! %d (%d)-> null\n", st[st[mid].fa].lnk, a[i-active.len]);
                printf("i=%d mid=%d st[mid].fa=%d lnk=%d active=(%d %d) a=%d\n", i, mid, st[mid].fa, st[st[mid].fa].lnk, active.v, active.len, a[i-active.len]);
                printf("FA RANGE [%d %d] at (%d %d)\n", st[st[mid].fa].l, st[st[mid].fa].r, st[st[mid].fa].l / 11 +2, st[st[mid].fa].l % 11);
                printf("LNK RANGE [%d %d] at (%d %d)\n", st[st[st[mid].fa].lnk].l, st[st[st[mid].fa].lnk].r, st[st[st[mid].fa].lnk].l / 11 +2, st[st[st[mid].fa].lnk].l % 11);
            }
            if (i == 5352) printf("5352CCCC : %d %d %d %d\n", mid, st[mid].fa, a[i-active.len], st[st[mid].fa].sons[a[i-active.len]]);
#endif
            active.v = st[st[st[mid].fa].lnk].sons[a[i-active.len]];
#ifdef DEBUG_SON
            if (i==5352 || i ==1568) {
                printf("%d NEW ACTIVE: %d %d\n", i, active.v, active.len);
            }
#endif
#ifdef DEBUG
            printf("NEW ACTIVE: %d %d\n", active.v, active.len);
#endif
            while (active.len > st[active.v].len()) {
#ifdef DEBUG
                printf("GOGOGO : %d %d %d %d\n", active.v, active.len, st[active.v].len(), st[active.v].sons[a[i-active.len]]);
#endif
                active.len -= st[active.v].len();
#ifdef DEBUG_SON
            if (!st[active.v].sons.count(a[i-active.len])) {
                printf("ERROR! %d (%d)-> null\n", active.v, a[i-active.len]);
                printf("i=%d active=(%d %d) a=%d\n", i, active.v, active.len, a[i-active.len]);
            }
#endif
                active.v = st[active.v].sons[a[i-active.len]];
#ifdef DEBUG
//        printf("NEW ACTIVE: %d %d\n", active.v, active.len);
#endif
            }
        }
#ifdef DEBUG
        printf("NEW ACTIVE: %d %d\n", active.v, active.len);
#endif
    }
}

void build_tree()
{
    st[0] = node();
    stn = 1;
    active = v_node(0, 0);
    for (int i = 0; i < len; ++i) {
        st_extend(i);
    }

#ifdef DEBUG
    for (int i = 0; i < stn; ++i) {
        printf("[%d] %d %d | %d | %d | ", i, st[i].l, st[i].r, st[i].lnk, st[i].fa);
        for (map<int,int>::iterator it = st[i].sons.begin(); it != st[i].sons.end(); ++it) {
            printf("(%d %d) ", it->first, it->second);
        }
        printf("\n");
    }
    printf("%d\n", stn);
#endif
}

#ifdef DEBUG_DFS
int DN = 0;
bool vis[MAXST];
#endif

int dfs(int i, int len)
{
#ifdef DEBUG_DFS
    vis[i] = true;
    ++DN;
    //printf("DFS-[%d/%d] %d %d\n", DN, stn, i, len);
#endif
    long long sum = 0;
    map<int, int>::iterator it = pos.lower_bound(st[i].l);
    if (it != pos.end() && it->first < st[i].r) {
        sum += it->second;
        if (it->first > st[i].l) {
            len -= st[i].r - it->first;
            //printf("SUM: %d LEN: %d st: %d - %d, X: %d\n", sum, len, st[i].l, st[i].r, it->first);
            if (ans < sum * len) ans = sum * len;
        }
        return sum;
    }
    for (map<int, int>::iterator it = st[i].sons.begin(); it != st[i].sons.end(); ++it) {
#ifdef DEBUG_DFS
        if (vis[it->second]) {
            printf("ERROR! %d (%d)-> %d\n", i, it->first, it->second);
            continue;
        }
#endif
        //printf("%d %d %d\n", it->first, it->second, st[it->second].len());
        sum += dfs(it->second, len + st[it->second].len());
    }
    if (ans < sum * len) ans = sum * len;
    return sum;
}

void solve()
{
    build_tree();
    dfs(0, 0);
}

void print()
{
    cout << ans << endl;
}

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("F.in", "r", stdin);
    //freopen("F.out", "w", stdout);
#endif
    init();
    solve();
    print();
}
