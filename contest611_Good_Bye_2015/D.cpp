// D. New Year and Ancient Prophecy

#include <cstdio>
#include <cstdlib>

const int MAXN = 5001;
const int MP = 1000000007;

int n;
char s[MAXN];
int a[MAXN];
int f[MAXN][MAXN];
int d[MAXN][MAXN];

bool st(int i, int j)
{
    int k = f[i-j+1][i-j-j+1];
    return k < j && a[i-j-j+k+1] < a[i-j+k+1];
}

int main()
{
    //freopen("d.in", "r", stdin);
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) a[i+1] = s[i] - '0';
    for (int i = n; i > 0; --i) {
        for (int j = n; j > 0; --j) {
            if (i == n || j == n) f[i][j] = (a[i] == a[j]);
            else {
                if (a[i] == a[j]) f[i][j] = f[i+1][j+1] + 1;
                else f[i][j] = 0;
            }
        }
    }
    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) printf("%d ", f[i][j]);
        printf("\n");
    }
    printf("\n");
    */
    d[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            d[i][j] = d[i][j-1];
            if (a[i-j+1] != 0) {
                if (i-j < j) d[i][j] += d[i-j][i-j];
                else {
                    if (st(i, j)) d[i][j] += d[i-j][j];
                    else d[i][j] += d[i-j][j-1];
                }
            }
            if (d[i][j] > MP) d[i][j] -= MP;
        }
    }
    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) printf("%d ", d[i][j]);
        printf("\n");
    }
    */
    printf("%d\n", d[n][n]);
}
