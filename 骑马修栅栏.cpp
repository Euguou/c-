//https://www.luogu.org/problemnew/show/P2731
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1031;
int G[maxn][maxn], du[maxn];
int n,m;
stack<int> S;
void dfs(int u)
{
    for(int v=1; v<=n; v++)
        if(G[u][v])
        {
            G[u][v]--;
            G[v][u]--;
            dfs(v);    
        }
    S.push(u);
}
int main(){

    cin>>m;
    int u,v;
    for(int i=1; i<=m; i++){
        cin>>u>>v;
        n = max(n,u);
        n = max(n,v); 
        G[u][v]++;
        G[v][u]++;
        du[u]++;
        du[v]++;
    }
    int s = 1;
    for(int i=1; i<=n; i++)
        if(du[i]%2==1) 
        {   
            s=i;
            break;
        }
		dfs(s);
		while (!S.empty())
		{
			cout<<S.top()<<endl;
			S.pop();
		}
    return 0;
}