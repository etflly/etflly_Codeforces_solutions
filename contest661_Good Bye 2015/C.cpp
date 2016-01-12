// C. New Year and Domino
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXH = 502;
const int MAXW = 502;

bool g[MAXH][MAXW];
int h, w;
int dhh[MAXH][MAXW];
int dhw[MAXH][MAXW];
int dwh[MAXH][MAXW];
int dww[MAXH][MAXW];
int d[4][MAXH][MAXW];

void init()
{
    scanf("%d%d", &h, &w);
    char s[MAXW];
    for (int i=0; i< h; ++i) {
        scanf("%s", s);
        //printf("%d %s\n",strlen(s),s);
        for (int j = strlen(s) - 1; j >= 0; --j) {
            g[i][j] = (s[j] == '.');
        }
    }
}

void solve()
{
    for (int j = 0; j < w+1; ++j) dhh[0][j] = 0;
    for (int i = 1; i < h+1; ++i) {
        for (int j = 0; j < w+1; ++j) {
            dhh[i][j] = dhh[i-1][j] + (g[i][j] && g[i-1][j]);
        }
    }
    for (int i = 0; i < h+1; ++i) dhw[i][0] = 0;
    for (int j = 1; j < w+1; ++j) dhw[0][j] = (g[0][j] && g[0][j-1]);
    for (int i = 1; i < h+1; ++i) {
        for (int j = 1; j < w+1; ++j) {
            dhw[i][j] = dhw[i-1][j] + (g[i][j] && g[i][j-1]);
        }
    }
    for (int i = 0; i < h+1; ++i) dww[i][0] = 0;
    for (int i = 0; i < h+1; ++i) {
        for (int j = 1; j < w+1; ++j) {
            dww[i][j] = dww[i][j-1] + (g[i][j] && g[i][j-1]);
        }
    }
    for (int j = 0; j < w+1; ++j) dwh[0][j] = 0;
    for (int i = 1; i < h+1; ++i) dwh[i][0] = g[i][0] && g[i-1][0];
    for (int i = 1; i < h+1; ++i) {
        for (int j = 1; j < w+1; ++j) {
            dwh[i][j] = dwh[i][j-1] + (g[i][j] && g[i-1][j]);
        }
    }
/*
    for (int i=0; i< h+1; ++i) {
        for (int j=0; j<w+1; ++j) printf("%d ", dhh[i][j]);
        printf("\n");
    }
        printf("\n");

    for (int i=0; i< h+1; ++i) {
        for (int j=0; j<w+1; ++j) printf("%d ", dhw[i][j]);
        printf("\n");
    }
        printf("\n");

    for (int i=0; i< h+1; ++i) {
        for (int j=0; j<w+1; ++j) printf("%d ", dww[i][j]);
        printf("\n");
    }
        printf("\n");

    for (int i=0; i< h+1; ++i) {
        for (int j=0; j<w+1; ++j) printf("%d ", dwh[i][j]);
        printf("\n");
    }
        printf("\n");
        printf("\n");
*/
    for (int i = 0; i < h; ++i) {
        d[0][i][0] = dhh[i+1][0] + dhw[i][1];
        d[1][i][0] = dhh[i+1][0] + dhw[i][0];
        d[2][i][0] = dhh[i][0] + dhw[i][1];
        d[3][i][0] = dhh[i][0] + dhw[i][0];
    }
    for (int j = 0; j < w; ++j) {
        d[0][0][j] = dww[0][j+1] + dwh[1][j];
        d[1][0][j] = dww[0][j] + dwh[1][j];
        d[2][0][j] = dww[0][j+1] + dwh[0][j];
        d[3][0][j] = dww[0][j] + dwh[0][j];
    }
    for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            d[0][i][j] = d[0][i-1][j-1] + dhh[i][j] + dhw[i][j+1] + dww[i][j]+ dwh[i+1][j] ;
            d[1][i][j] = d[1][i-1][j-1] + dhh[i][j] + dhw[i][j] + dww[i][j-1] + dwh[i+1][j];
            d[2][i][j] = d[2][i-1][j-1] + dhh[i-1][j] + dhw[i][j+1] + dww[i][j] + dwh[i][j];
            d[3][i][j] = d[3][i-1][j-1] + dhh[i-1][j] + dhw[i][j] + dww[i][j-1] + dwh[i][j];
        }
    }
    /*
    for (int k=0; k<4; ++k){
        for (int i=0; i<h; ++i){
            for (int j=0;j<w; ++j) {
                printf("%d ", d[k][i][j]);
            }
        printf("\n");
        }
        printf("\n");
    }
*/
    int q, r1, c1, r2, c2, ans;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d",&r1, &c1, &r2, &c2);
        --r1; --r2; --c1; --c2;
        //printf("%d %d %d %d\n", r1, c1, r2, c2);
        if (r1 == 0) {
            if (c1 == 0) {
                ans = d[3][r2][c2];
            } else {
                ans = d[3][r2][c2] - d[2][r2][c1-1];
            }
        } else if (c1 == 0) {
            ans = d[3][r2][c2] - d[1][r1-1][c2];
            //printf("%d %d\n",d[3][r2][c2], d[1][r1-1][c2]);
        } else {
            ans = d[3][r2][c2] - d[2][r2][c1-1] - d[1][r1-1][c2] + d[0][r1-1][c1-1];
        }
        printf("%d\n", ans);
    }
}

int main()
{
    init();
    solve();
}
