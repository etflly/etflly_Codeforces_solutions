// D. New Year and Ancient Prophecy

#include <cstdio>
#include <cstdlib>

const int MAXN = 5001;
const int MAXNN = MAXN*MAXN;
const int MP = 1000000007;

struct tnode {
    int i, j;
    int br;
    int son[10];
};

int n;
char s[MAXN];
int a[MAXN];
int tm;
tnode tr[MAXNN];
int order[MAXN][MAXN];
int d[MAXN][MAXN];

int add(int i, int j, int k)
{
    int x = a[i+j-1];
    ++tm;
    tr[tm].i = i; tr[tm].j = j;
    if (tr[k].son[x] != 0) {
        int sx = tr[k].son[x];
        tr[tm].br = sx;
        tr[k].son[x] = tm;
        for (int kk = 0; kk < 10; ++kk) {
            tr[tm].son[kk] = tr[sx].son[kk];
            tr[sx].son[kk] = 0;
        }
    }
    tr[k].son[x] = tm;
    return tm;
}

int dfs(int k, int od, bool first)
{
    order[tr[k].i][tr[k].j] = od;
    if (tr[k].br != 0) dfs(tr[k].br, od, false);
    if (first) {
        for (int x = 0; x < 10; ++x) {
            if (tr[k].son[x] != 0) {
                od = dfs(tr[k].son[x], od+1, true);
            }
        }
    }
    return od;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i=0; i<n; ++i) a[i+1] = s[i] - '0';

    tm = 0;
    for (int i = 1; i <= n; ++i) {
        int now = add(i, 1, 0);
        for (int j = 2; j <= n-i+1; ++j) {
            now = add(i, j, now);
        }
    }

    dfs(0, 0, true);
/*
    for (int i = 1; i <= n; ++i) {
        for (int j=1; j <= n-i+1; ++j) {
            printf("%d ", order[i][j]);
        }
        printf("\n");
    }
    */
    d[0][0] = d[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            d[i][j] = d[i][j-1];
            if (a[i-j+1] != 0) {
                if (i-j+1 > j) {
                    if (order[i-j-j+1][j] < order[i-j+1][j]) {
                        d[i][j] += d[i-j][j];
                    } else if (j > 1){
                        d[i][j] += d[i-j][j-1];
                    }
                } else {
                    d[i][j] += d[i-j][i-j];
                }
            }
            d[i][j] %= MP;
        }
    }
    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    */
    printf("%d\n", d[n][n]);
}
