// B_gen
#include <cstdlib>
#include <cstdio>

const int MAXN = 101;
const int MAXC = 1000000000;

int n, m;
long c[MAXN][MAXN];

int main()
{
    freopen("b.in", "w", stdout);
    n = 10;
    m = 10;
    printf("%d %d\n", n,m);
    for (int i=0; i< n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", rand()%MAXC);
        }
        printf("\n");
    }
}
