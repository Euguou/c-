#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#define LL long long
#define eps 1e-8
#define maxn 550
#define mod 100000007
#define inf 0x3f3f3f3f
using namespace std;

struct node{
    int left,right;
    double cost;
}road[maxn*maxn];

int cmp(node x,node y) {return x.cost<y.cost;}
int p[maxn],m,n;
int find(int x) {return p[x]=(p[x]==x? x:find(p[x]));}
double kruskal(int k)
{
    if(k>=n) return 0;
    int cnt = 0;
    for(int i=1;i<=n;i++) p[i]=i;
    sort(road+1,road+m+1,cmp);
    for(int i=1;i<=m;i++) {
        int x=find(road[i].left);
        int y=find(road[i].right);
        if(x!=y) {
            cnt++;
            if(cnt == n-k)
                return road[i].cost;
            p[x]=y;
        }
    }
}

int sign(double x) {
    if(fabs(x)<eps) return 0;
    return x<0? -1:1;
}

double x[maxn],y[maxn];

int main(int argc, char const *argv[])
{
    int t; cin >> t;
    while(t--)
    {
        int k;
        scanf("%d %d", &k,&n);
        m = 0;
        memset(road,0,sizeof(road));

        for(int i=1; i<=n; i++) {
            scanf("%lf %lf", &x[i],&y[i]);
        }

        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                double d = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
                road[++m].left = i;
                road[m].right = j;
                road[m].cost = d;
            }
        }

        double ans=kruskal(k);

        printf("%.2f\n", ans);
    }

    return 0;
}
