#include <bits/stdc++.h>

using namespace std;

long long int N;
long long int a[41],K;
int f[1001][1001];

int haha(int x,int y)
  {
    int cnt=0;
    for(int i=x;i<=y;i++)
    cnt=cnt*10+a[i];
    return cnt;
  }

int main()
{
    long long int ans;
    cin>>N>>K;
    cout<<endl;
    char c;
    for(int i=1;i<=N;i++)
    {
      cin>>c;
      a[i]=c-'0';
    }
    f[1][0]=a[1];
    for(int i=2;i<=N;i++)
    {
        f[i][0]=f[i-1][0]*10+a[i];
        for(int i=2;i<=N;i++)
            for(int j=1;j<=K;j++)
            {
                for(int x=j;x<=i;x++)
                {
                    f[i][j]=max(f[i][j],f[x][j-1]*haha(x+1,i));
                }

            }
    }
    ans=f[N][K];
    cout<<ans;
    return 0;
}
