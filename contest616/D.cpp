// D. Longest k-Good Segment
#include <cstdlib>
#include <cstdio>
#include <cstring>

const int MAXN = 500001;
const int MAXA = 1000001;

int n, k;
int a[MAXN];
int cnt[MAXA];
int ansl, ansr, anslen;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; ++i) scanf("%d", &a[i]);
    int l=0, r=0, len=1, t = 1;
    cnt[a[0]] = 1;
    for (r=1; r<n; ++r) {
        while (t==k && cnt[a[r]]==0) {
            --cnt[a[l]];
            if (cnt[a[l]] == 0) {
                --t;
            }
            ++l;
            --len;
        }
        if (t<k || cnt[a[r]]>0) {
            if (cnt[a[r]]==0) ++t;
            ++cnt[a[r]];
            ++len;
        }
        //for (int j = 0; j < 10; ++j) printf("%d ", cnt[j]);
        //printf("\n");
        if (len > anslen) {
            anslen = len;
            ansl = l;
            ansr = r;
        }
    }
    printf("%d %d\n", ansl+1, ansr+1);
}
