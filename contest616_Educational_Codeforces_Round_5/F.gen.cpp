#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAXN = 100001;
const int MAXS = 500001;
const int MAXNS = MAXN + MAXS;
const int MAXST = MAXNS * 2;
const int MAXC = 1e7;

int n, m;

int main() 
{
    freopen("F.in", "w", stdout);
    srand((unsigned)time(NULL));
    n = 1000;
    m = 10;
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%c", 'a'+rand()%26);
        }
        printf("\n");
    }
    for (int i = 0; i < n; ++i) printf("%d ", rand()%MAXC * (rand()%2 ? 1 : -1));
    printf("\n");
}
