#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std; 
struct node{
	int u;
	int v;
	int w;
}e[50010];
int f[20010];
bool cmp(node a,node b)
{
	return a.w>b.w;
}
int getf(int x)
{
	if(x==f[x])
	return x;
	f[x]=getf(f[x]);
	return f[x];
} 
int merge(int x1,int x2)
{
	int y1,y2;
	y1=getf(x1);
	y2=getf(x2);
	if(y1!=y2)
	{
		f[y1]=y2;
		return 1;
	}
	return 0;
}
int main()
{
	int t,n,m,r;
	int i,j,k,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		int sum=0;
		memset(e,0,sizeof(e));
		scanf("%d %d %d",&n,&m,&r);
		for(i=0;i<r;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
		    e[i].u=a;
		    e[i].v=b+n;
		    e[i].w=c;
		}
		sort(e,e+r,cmp);
		for(j=0;j<(n+m);j++)
		f[j]=j;
		for(j=0;j<r;j++)
		{
			if(merge(e[j].u,e[j].v))
			sum=sum+e[j].w;
		}
		int ans=(m+n)*10000-sum;
		printf("%d\n",ans);
	}
	return 0;
}