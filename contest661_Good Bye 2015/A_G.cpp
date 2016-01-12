// A New Year and Days GENERATOR
#include <cstdio>
#include <cstdlib>

int md[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int w[8];
int m[32];
int wi = 5;
int mi = 1;
int mdi = 1;

int main()
{
    while (mdi <= 12) {
        ++w[wi];
        ++m[mi];
        if (++wi > 7) wi = 1;
        if (++mi > md[mdi]) {
            mi = 1;
            ++mdi;
        }
    }
    for (int i = 1; i <= 7; ++i)
        printf("%d, ", w[i]);
    printf("\n");
    for (int i = 1; i <= 31; ++i)
        printf("%d, ", m[i]);
}
