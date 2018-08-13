#include <iostream>  
#include <stdio.h>  
#include <memory.h>  
using namespace std;  
  
const int INF = 99999999;  
int c[50005], w[10005];  
int bag[10005];  
int N, V, Z;  
  
void _com_bag()     //完全背包：顺序！  
{  
    int i, j;  
    for(i = 0; i <= Z; i++) bag[i] = INF;  
    bag[0] = 0;  
    for(i = 0; i < N; i++)  
    {  
        for(j = c[i]; j <= Z; j++)  
        {  
            bag[j] = min(bag[j], bag[j-c[i]] + w[i]);  
        }  
    }  
}  
  
int main()  
{  
    int i, t, E, F;  
    scanf("%d", &t);  
    while(t--)  
    {  
        scanf("%d %d", &E, &F);  
        Z = F - E;  
        scanf("%d", &N);  
        for(i = 0; i < N; i++)  
            scanf("%d %d", &w[i], &c[i]);  
        _com_bag();  
        if(bag[Z] != INF)  
            printf("The minimum amount of money in the piggy-bank is %d.\n", bag[Z]);  
        else  
            printf("This is impossible.\n");  
    }  
  
    return 0;  
}  