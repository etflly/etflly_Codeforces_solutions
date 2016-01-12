// B. New Year and Old Property
#include <cstdio>
#include <cstdlib>

long long a, b;
int ba[100], bb[100];
int la, lb, ka, kb;
long long ans;

int main()
{
    scanf("%I64d%I64d", &a, &b);
    la = 0;
    while (a != 0) {
        ba[la++] = a & 1;
        a >>= 1;
    }
    lb = 0;
    while (b != 0) {
        bb[lb++] = b & 1;
        b >>= 1;
    }
    ka = -1;
    for (int i = la - 2; i >= 0; --i)
        if (ba[i] == 0) {
            ka = i;
            break;
        }
    kb = 0;
    for (int i = lb - 2; i >= 0; --i)
        if (bb[i] == 0) {
            if (kb == 0) {
                kb = i;
                //printf("dd%d\n", i);
            } else {
                ++kb;
                //printf("ff%d\n", kb);
                break;
            }
        }
/*
    for (int i=la - 1; i>=0; --i) printf("%d", ba[i]);
    printf("\n");
    for (int i=lb - 1; i>=0; --i) printf("%d", bb[i]);
    printf("\n");
    printf("%d %d %d %d\n", la, ka, lb, kb);
*/
    if (la == lb) {
        if (ka < kb) ans = 0;
        else ans = ka - kb + 1;
    } else if (la > lb) {
        ans = 0;
    } else {
        ans = ka + 1 + lb - kb - 1;
        for (int i = la + 1; i <= lb - 1; ++i) ans += i - 1;
    }
    printf("%I64d\n", ans);
}
