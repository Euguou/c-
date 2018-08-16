//http://poj.org/problem?id=2186 
#include <cstdlib>
#include <iostream>
#include <algorithm> 
#include <cstring>
#include <string>
#define MAXp 10009
#define MAXe 50009
using namespace std;
 
struct Edge{
    int u;   
    int v;
    int next;   
} edge[MAXe];
 
int c,head[MAXp],dfn[MAXp],stk1[MAXp],stk2[MAXp],part[MAXp],tcc,s1,s2,ts;
int odeg[MAXp];
 
void addEdge(int u,int v)
{
     edge[c].u=u;
     edge[c].v=v;
     edge[c].next=head[u];
     head[u]=c;
     c++;
}
 
void dfs(int u)
{
     int i,v;
     dfn[u]=++ts;
     stk1[++s1]=stk2[++s2]=u;
     for(i=head[u];i!=-1;i=edge[i].next)
     {
         v=edge[i].v;
         if(!dfn[v]) dfs(v);
         else if(!part[v]){
             while(dfn[v]<dfn[stk2[s2]]) s2--;
         }                               
     }
     
     if(u==stk2[s2])
     {
         tcc++; 
         part[stk2[s2]]=tcc;          
         while(stk1[s1]!=stk2[s2])
         {
             part[stk1[s1]]=tcc;
             s1--;                     
         }        
         s1--;
         s2--;    
     }
}
 
int main(int argc, char *argv[])
{
#ifdef LOCAL
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
#endif
    int n,m,a,b,i,count,ans;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
         c=0;           
         memset(head,-1,sizeof(head));           
         for(i=0;i<m;i++)
         {
             scanf("%d %d",&a,&b);
             addEdge(a,b);            
         }
         tcc=ts=0;
         s1=s2=-1;
         memset(dfn,0,sizeof(dfn));
         memset(part,0,sizeof(part));
         for(i=1;i<=n;i++)
         {
             if(!dfn[i]) dfs(i);             
         }
         //cout<<"tcc = "<<tcc<<endl;
         memset(odeg,0,sizeof(odeg));
         for(i=0;i<c;i++)
         {
             a=edge[i].u;
             b=edge[i].v;
             if(part[a]!=part[b])
             {
                 odeg[part[a]]++;                 
             }            
         }
         count=0;
         for(i=1;i<=tcc;i++)
         {
             if(odeg[i]==0)
             {
                 count++;
                 ans=i;          
             }                
         }  
         if(count==1) 
         {
             count=0;         
             for(i=1;i<=n;i++)
             {
                 if(part[i]==ans) count++;             
             } 
             printf("%d\n",count);        
         }else printf("0\n");          
    } 
    system("PAUSE");
    return EXIT_SUCCESS;
}

