#include <bits/stdc++.h>

using namespace std;

int num[100001],k,sum;
int N,ans,x[21];

int Prime(int N)
{
  for(int i = 2; i<= sqrt(N); i++)
	  if(N%i == 0) return 0;
  return 1;
}

void dfs(int sum , int deep , int now)
{
     if(deep==k && sum>1 && Prime(sum)) ans++;
     if(deep==k || now==N) return;
     dfs(sum ,deep ,now+1);
     dfs(sum+x[now],deep+1,now+1);
}

int a[10001];

int main()
{

    cin>>N>>k;
    for(int i=0;i<N;i++)
    {
        cin>>x[i];
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
