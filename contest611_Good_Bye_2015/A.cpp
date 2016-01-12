// A New Year and Days
#include <cstdio>
#include <cstdlib>

int n;
char  s[10];

int main()
{
    scanf("%d %s %s", &n, s, s);
    if (s[0] == 'w') {
        if (n==5 || n==6) printf("53\n");
        else printf("52\n");
    } else {
        if (n == 31) printf("7\n");
        else if (n == 30) printf("11\n");
        else printf("12\n");
    }
}
