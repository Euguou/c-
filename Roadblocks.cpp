#include <iostream>  
#define MAXN 5010  
#define MAXE 200010  
using namespace std ;  
struct Graph  
{  
    int vex , next , cnt , dis ;  
};  
int first[MAXN] , from[MAXN] , to[MAXN] , n , r ;  
Graph g[MAXE] ;  
void Add (int u , int v , int d , int &tot)  
{  
    g[tot].cnt = 0 ;  
    g[tot].dis = d ;  
    g[tot].next = first[u] ;  
    g[tot].vex = v ;  
    first[u] = tot ++ ;  
}  
void Read ()  
{  
    int u , v , i , d , tot ;  
    scanf ("%d%d" , &n , &r) ;  
    memset (first , -1 , sizeof (first)) ;  
    memset (from , -1 , sizeof (from)) ;  
    memset (to , -1 , sizeof (to)) ;  
    for (tot = i = 0 ; i < r ; i ++)  
    {  
        scanf ("%d%d%d" , &u , & v , &d) ;  
        Add (u , v , d , tot) ;  
        Add (v , u , d , tot) ;  
    }  
}  
void DIJ (int source , int *dis , int flag)  
{  
    int i , j , mint , k , edge[MAXN] ;  
    bool visited[MAXN] = {false} ;  
    memset (edge , 0 , sizeof (edge)) ;  
    for (i = first[source] ; i != -1 ; i = g[i].next)  
        if (dis[g[i].vex] == -1 || g[i].dis < dis[g[i].vex])  
        {  
            dis[g[i].vex] = g[i].dis ;  
            edge[g[i].vex] = i ;  
        }  
    dis[source] = 0 ;  
    visited[source] = true ;  
    for (i = 1 ; i < n ; i ++)  
    {  
        for (k = -1 , j = 1 ; j <= n ; j ++)  
            if (!visited[j] && dis[j] != -1 && (k == -1 || dis[j] < mint))  
            {  
                mint = dis[j] ;  
                k = j ;  
            }  
        if (k == -1)  
            return ;  
        visited[k] = true ;  
        g[edge[k]].cnt = flag ;  
        for (j = first[k] ; j != -1 ; j = g[j].next)  
            if (!visited[g[j].vex] && (dis[g[j].vex] == -1 || mint + g[j].dis < dis[g[j].vex]))  
            {  
                dis[g[j].vex] = mint + g[j].dis ;  
                edge[g[j].vex] = j ;  
            }  
    }  
}  
void Solve ()  
{  
    int i , j , least , ans = -1 ;  
    DIJ (1 , from , 1) ;  
    DIJ (n , to , 2) ;  
    least = from[n] ;  
    for (i = 1 ; i <= n ; i ++)  
        for (j = first[i] ; j != -1 ; j = g[j].next)  
            if (g[j].cnt != 1 && from[i] != -1 && to[g[j].vex] != -1)  
            {  
                if (from[i] + to[g[j].vex] + g[j].dis > least  
                    && (ans == -1 || from[i] + to[g[j].vex] + g[j].dis< ans))  
                    ans = from[i] + to[g[j].vex] + g[j].dis ;  
            }  
    printf ("%d/n" , ans) ;  
}  
int main ()  
{  
    Read () ;  
    Solve () ;  
    return 0 ;  
}  