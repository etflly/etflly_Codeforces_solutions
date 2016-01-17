#include <cstdio>
#include <cstring>

const int kMaxN = 1000000;
const int kMod = 1000000007;

int n, m, len_p, res;
char p[kMaxN];
int y[kMaxN];
int k[kMaxN];
bool f[kMaxN];
int pow[kMaxN+1];

void init()
{
    scanf("%d%d\n", &n, &m);
    scanf("%s", p);
    len_p = strlen(p);
    for (int i = 0; i < m; ++i) {
        scanf("%d", y + i);
        --y[i];
    }
}
/*
int pow(int x, int a)
{
    if (a == 0) return 1;
    int ret = pow(x, a >> 1);
    if (x & 1)
        ret = ret * ret * x % kMod;
    else
        ret = ret * ret % kMod;
    return ret;
}
*/
void calc_k()
{
    int j = -1;
    k[0] = -1;
    for (int i = 1; i < len_p; ++i) {
        while((j != -1) && (p[i] != p[j+1])) {
            j = k[j];
            //printf("%d %c %c\n", j, p[i], p[j]);
        }
        if (p[i] == p[j+1]) {
            ++j;
            k[i] = j;
        }
        else k[i] = -1;
        //printf("%d %d\n", i, k[i]);
    }
}

void calc_pow()
{
    pow[0] = 1;
    for (int i = 1; i <= n; ++i) pow[i] = 1LL * pow[i-1] * 26 % kMod;
}

void solve()
{
    calc_pow();
    if (m == 0) {
        res = pow[n];
        return;
    }
    calc_k();
    for (int i = k[len_p-1]; i >= 0; i = k[i]) {
        f[i] = true;
        //printf("%d\n", i);
    }
    res = 1LL * pow[y[0]] * pow[n - y[m-1] - len_p] % kMod;
    //printf("%d %d\n", pow[y[0]], pow[n - y[m-1] - len_p]);
    for (int i = 1; i < m; ++i) {
        if (y[i] < y[i-1] + len_p) {
            if (!f[y[i-1] + len_p - y[i] - 1]) {
                //printf("%d %d %d\n", y[i], y[i-1], y[i-1] + len_p - y[i] -1);
                res = 0;
                return;
            }
        }
        else res = 1LL * res * pow[y[i] - y[i-1] - len_p] % kMod;
        //printf("%d\n", res);
    }
}

void print()
{
    printf("%d\n", res);
}

int main()
{
    //freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    init();
    solve();
    print();
}
