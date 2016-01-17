#include<bits/stdc++.h>
#define N 100005
#define M 1000005
using namespace std;
vector<int>a[M];char s[M];
typedef long long LL;LL ans;
int f[M],son[M][26],step[M];LL ret[M];
int st[N],ed[N],c[N],k,n,i,last,tot;
int Insert(int last,int ch){
  int p,q,np,nq;
    if (q=son[last][ch]){
        if (step[q]==step[last]+1) return q;
        step[nq=++tot]=step[last]+1;
        memcpy(son[nq],son[q],sizeof(son[q]));
        f[nq]=f[q];f[q]=nq;
        for (p=last;p&&son[p][ch]==q;p=f[p]) son[p][ch]=nq;
        return nq;
  }step[np=++tot]=step[last]+1;
  for (p=last;p&&!son[p][ch];p=f[p]) son[p][ch]=np;
  if (!p) return f[np]=1,np;
  if (step[q=son[p][ch]]==step[p]+1) return f[np]=q,np;
  step[nq=++tot]=step[p]+1;
  memcpy(son[nq],son[q],sizeof(son[q]));
  f[nq]=f[q];f[q]=nq;f[np]=nq;
  for (;p&&son[p][ch]==q;p=f[p]) son[p][ch]=nq;
    return np;
}
void DFS(int x){
  for (int i=0;i<a[x].size();i++)
    DFS(a[x][i]),ret[x]+=ret[a[x][i]];
  ans=max(ans,1ll*step[x]*ret[x]);
}
int main(){
    freopen("F.in", "r", stdin);
    scanf("%d",&n);tot=1;
    for (i=1;i<=n;i++){
    st[i]=ed[i-1]+1;
    scanf("%s",s+st[i]);
    ed[i]=st[i]+strlen(s+st[i])-1;
  }for (i=1;i<=n;i++) scanf("%d",&c[i]);
    for (i=1;i<=n;i++)
        for (last=1,k=st[i];k<=ed[i];k++)
            last=Insert(last,s[k]-'a'),ret[last]+=c[i];
    for (i=2;i<=tot;i++)    
        a[f[i]].push_back(i);
    DFS(1);
    cout << ans << endl;
//    printf("%I64d\n",ans);
}
