// D data maker

#include <cstdio>
#include <cstdlib>

const int MAXN = 5001;

int n;
char s[MAXN];

int main()
{
    freopen("d.in", "w", stdout);
    n = 5000;
    //for (int i = 0; i < n; ++i) s[i] = '1';
    for (int i = 0; i < n; ++i) s[i] = '0' + rand()%10;
    s[n+1] = '\0';
    printf("%d\n%s\n", n, s);
    fclose(stdout);
}
