// A. Comparing Two Long Integers
#include <cstdlib>
#include <cstdio>
#include <cstring>

const int MAXN = 1000001;

char a[MAXN], b[MAXN];
int la, lb;
int sa, sb;

int main()
{
    scanf("%s%s", a, b);
    la = strlen(a);
    lb = strlen(b);
    for (sa = 0; sa < la; ++sa) if (a[sa] != '0') break;
    for (sb = 0; sb < lb; ++sb) if (b[sb] != '0') break;
    if (la - sa > lb - sb)
        printf(">\n");
    else if (la - sa < lb - sb)
        printf("<\n");
    else {
        int i;
        for (i = 0; i < la-sa; ++i) {
            if (a[sa+i] > b[sb+i]) {
                printf(">\n");
                break;
            } else if (a[sa+i] < b[sb+i]) {
                printf("<\n");
                break;
            }
        }
        if (i == la-sa) printf("=\n");
    }
}
