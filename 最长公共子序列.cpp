#include <bits/stdc++.h>

using namespace std;

char S[5001],T[5001];
int b[5001][5001];

int main()
{
    int N;
    cin>>S+1>>T+1;
    int ls=strlen(S+1),lt=strlen(T+1);
    for(int i=1;i<=ls;i++)
 	{
 		for(int j=1;j<=lt;j++)
		{
		    if(S[i]!=T[j])
            {
                b[i][j]=max(b[i-1][j],b[i][j-1]);
            }
            else
            {
                b[i][j]=b[i-1][j-1]+1;
            }
		}
	}
    cout<<b[ls][lt];
    return 0;
    /*
    ABCBDABE
    BAEBCBD
    */
}
