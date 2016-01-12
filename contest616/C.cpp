// C. The Labyrinth
#include <cstdlib>
#include <cstdio>

const int MAXN = 1001;
const int MAXNN = MAXN * MAXN;

int n, m;
char g[MAXN][MAXN];
int d[MAXN][MAXN];
int s[MAXNN];
int h;

int qi[MAXNN], qj[MAXNN];
int qs, qt;

void addq(int i, int j)
{
    d[i][j] = h;
    ++s[h];
    qi[qt] = i; qj[qt] = j;
    ++qt;
}

void bfs(int i, int j)
{
    qs = 0; qt = 1; qi[qs] = i; qj[qs] = j;
    d[i][j] = h;
    ++s[h];
    while (qs < qt) {
        int ii = qi[qs], jj = qj[qs];
        ++qs;
        if (ii > 0 && g[ii-1][jj] == '.' && d[ii-1][jj] == 0) addq(ii-1, jj);
        if (ii < n-1 && g[ii+1][jj] == '.' && d[ii+1][jj] == 0) addq(ii+1, jj);
        if (jj > 0 && g[ii][jj-1] == '.' && d[ii][jj-1] == 0) addq(ii, jj-1);
        if (jj < m-1 && g[ii][jj+1] == '.' && d[ii][jj+1] == 0) addq(ii, jj+1);
    }
}

int main()
{
    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", g[i]);
    h = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.' && d[i][j] == 0) {
                ++h;
                bfs(i, j);
            }
        }
    }
/*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i <= h; ++i) printf("%d ", s[i]);
    printf("\n");
*/
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.') printf(".");
            else {
                int d1=0, d2=0, d3=0, d4=0;
                int s1=0, s2=0, s3=0, s4=0;
                if (i > 0 && g[i-1][j] == '.') { d1 = d[i-1][j]; s1 = s[d1]; }
                if (i < n-1 && g[i+1][j] == '.') { d2 = d[i+1][j]; s2 = s[d2]; }
                if (j > 0 && g[i][j-1] == '.') { d3 = d[i][j-1]; s3 = s[d3]; }
                if (j < m-1 && g[i][j+1] == '.') { d4 = d[i][j+1]; s4 = s[d4]; }
                /*
                printf("%d %d\n", d1, s1);
                printf("%d %d\n", d2, s2);
                printf("%d %d\n", d3, s3);
                printf("%d %d\n", d4, s4);
                */
                int t = s1+1;
                if (d2 != d1) t += s2;
                if (d3 != d2 && d3 != d1) t += s3;
                if (d4 != d3 && d4 != d2 && d4 != d1) t +=s4;
                printf("%d", t%10);
            }
        }
        printf("\n");
    }
}
