//https://www.luogu.org/problemnew/show/P1037
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cng[10][11],num[10];
  
int n[35],ans[35];
int k,a,b,len=0;
char x;
bool find(int x,int y){
    for(int i=1;i<=num[x];i++)
        if(cng[x][i]==y) return 1;
    if(x==y) return 1;
    return 0;
}
int main(){
    while(scanf("%c",&x)&&x!=' ')
    n[++len]=x-48; 
    cin>>k;
    for(int i=1;i<=k;i++){
        scanf("%d%d",&a,&b);
        cng[a][++num[a]]=b;
    }
  
    for(int i=0;i<=9;i++)
          for(int j=1;j<=num[i];j++)
            for(int k=1;k<=num[cng[i][j]];k++)
                if(!find(i,cng[cng[i][j]][k])) 
                    cng[i][++num[i]]=cng[cng[i][j]][k];
    ans[0]=1;
    for(int i=1;i<=len;i++){
        int d=n[i],p=0;
        if(num[d]){
            for(int i=0;i<=31;i++){
                ans[i]=ans[i]*(num[d]+1)+p;
                p=ans[i]/10;
                ans[i]%=10;
            }
        }
    }
    bool ok=0;
    for(int i=31;i>=0;i--)
        if(ans[i]||ok){
            ok=1;
            cout<<ans[i];
        }
    return 0;
}