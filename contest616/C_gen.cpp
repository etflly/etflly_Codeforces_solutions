// C_gen
#include <cstdlib>
#include <cstdio>

const int MAXN = 1001;
const int MAXNN = MAXN * MAXN;

int n, m;
char g[MAXN][MAXN];

int main()
{
    freopen("c.in", "w", stdout);
    n = 10;
    m = 10;
    printf("%d %d\n",n,m);
    for (int i=0; i< n; ++i ) {
        for (int j = 0; j < m; ++j) {
            if (rand()%2) printf(".");
            else printf("*");
        }
        printf("\n");
    }
    fclose(stdout);
}
