## A, Wet Shark and Odd and Even
### 题目大意
给一组数a[n]，从中选若干个使和为偶数，求能得到的最大的和。
### 数据规模
1 <= n <= 100,000
1 <= a[i] <= 10^9
### 思路
若所有数的和是偶数，即为答案；否则减去最小的一个奇数。

## B. Wet Shark and Bishops
### 题目大意
在棋盘上有n个棋子，每个棋子可以攻击他所在的对角线上所有的棋子。求共有多少对可以互相攻击的棋子。
### 数据规模
1 <= n <= 200,000
1 <= x, y <= 1000
### 思路
每个棋子属于两条对角线，分别为x+y和x-y。
统计每条对角线上的棋子数c[i]，则ans = sigma{c[i] \* c[i-1] / 2}。
或者：可以假定只能序号排在后面的攻击排在前面的，在统计的时候，累加c[i]的当前值即可。如枚举到第k个棋子时，假设它在第p条对角线上，他就可以攻击c[p]个棋子。

## C. Wet Shark and Flowers
### 题目大意
n个人围成一圈，第i个人等概率从[l[i], r[i]]中挑选出一个数，若相邻两个人取的数的乘积是给定的素数p的倍数，则两人各获得1000块钱。求所有人得到的总钱数的期望。
### 数据范围
3 <= n <= 100,000
2 <= p <= 10^9
1 <= l[i] <= r[i] <= 10^9
### 思路
两个数的乘积是p的倍数，即两数中至少一个是p的倍数。
对第i个人，设第i个人共有s[i]个数，其中有a[i]个可以被p整除，b[i]个不能。s[i] = r[i] - l[i] +1，有a[i] = r[i]/p - (l[i]-1])/p，b[i] = s[i] - a[i]。
对相邻两个人i, j=(i+1)%n，两人拿到的钱的期望是f[i] = 2000 \* (a[i] \* c[j] + b[i] \* a[i])/(c[i]\*c[j])。
那么所有人拿到的钱的期望就是sigma(f[i])。
### 注
推算时一定要明确每个变量的意义！！
只看相邻两个人不看所有人！

## D. Rat Kwesh and Cheese
### 题目大意
给定三个0.1到200.0（精度一位小数）的实数x,y,z，用这三个数做乘方运算，如(x^y)^z或x^(y^z)，求结果最大的一种。
### 思路
显然当输入数据比较大时，会超出浮点数的表示范围（正溢出）。可以用取2次log的方式解决：log(a^b)=b\*log(a)，由于log函数单调递增，log后的大小顺序和log前的相同。
但是这样会引入另一个问题，当输入数据很小时，log后的值是负数，无法再取log（负溢出）。当所有的运算结果都负溢出（否则已经得到答案了），说明所有输入都很小，那直接用乘方运算再把各种情况算一次即可，肯定不会溢出。
另：200\*200^200会超过double的表示范围，但在long double的范围内，所以用long double，取一次log即可。

## E. Wet Shark and Blocks
### 题目大意
有b组相同的数字a[n]，从每组数字中取出一个作为一位，组成一个新的数。求有多少种取法，使新数模x得k。
### 数据范围
2 <= n <= 50,000
1 <= b <= 10^9
0 <= k <= x <= 100, x >= 2
1 <= a[i] <= 9
### 思路
1. 设g[i][j]为模x余数为i的数在尾部填一位，变成余数j有多少种方法。那么答案即为(g^b)[0][k]。
g的求法：对于每一个a[r]，g[i][(i\*10+a[r])%x]++；或者若数字v在a中出现c[v]次，g[i][(i\*10+v)%x]+=c[v]。
总时间复杂度O(x^3\*logb)。
2. 令h[p][i]为长度为p的数模x余数为i的方法数，则将长度分别为p1,p2的两个数连在一起（p2在低位）后的h[p1+p2][(i\*10^p2+j)%x]=sigma(h[p1][i]\*h[p2][j])。
借鉴快速幂的思想，让长度p按二进制级别增长（每次左移1位），可以在O(logb)的运算次数内算出h[b][k]，同时第一维是可以省略的。
总时间复杂度O(x^2\*logb)。
