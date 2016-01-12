// B. Dinner with Emma
#include <cstdlib>
#include <cstdio>

const int MAXN = 1001;

int n, m;
long c[MAXN][MAXN];
long mm[MAXN];
long ans;

int main()
{
    //freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%ld", &c[i][j]);
    ans = -1;
    for (int i = 0; i < n; ++i) {
        mm[i] = c[i][0];
        for (int j = 1; j < m; ++j) {
            if (mm[i] > c[i][j]) mm[i] = c[i][j];
        }
        if (ans < mm[i]) ans = mm[i];
    }
    printf("%ld\n", ans);
}
