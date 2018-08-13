#include <iostream>
using namespace std;
#define inf 1<<29
#define MAXV 1005
 
int map[MAXV][MAXV];
int n,m;
 
void dijkstra(){
	int i,j,min,v;
	int d[MAXV];
	bool vis[MAXV];
 
	for(i=1;i<=n;i++){
		vis[i]=0;
		d[i]=map[1][i];
	}
 
	for(i=1;i<=n;i++){
		min=inf;
		for(j=1;j<=n;j++)
			if(!vis[j] && d[j]<min){
				v=j;
				min=d[j];
			}
		vis[v]=1;
 
		for(j=1;j<=n;j++)
			if(!vis[j] && d[j]>map[v][j]+d[v])
				d[j]=map[v][j]+d[v];
	}
	printf("%d\n",d[n]);
}
 
int main(){
	int i,j,a,b,c;
	while(~scanf("%d%d",&m,&n)){
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i==j)
					map[i][i]=0;
				else map[i][j]=map[j][i]=inf;
		
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(map[a][b]>c) map[a][b]=map[b][a]=c;
		}
		dijkstra();
	}
	return 0;
}

