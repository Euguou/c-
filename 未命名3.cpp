#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;
int a[1001] , f[1001] ;
int en,ln;

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)

	{
		cin>>a[i];
		f[i]=1;
	int j=0;
	for(;j<ln;j++)

	    if(f[j]<=a[i])
            break;
        if(j==ln)
           f[ln++]=a[i];
        else
            f[j]=a[j];
    }

	cout<<ln<<endl;
    return 0;
}

