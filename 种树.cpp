#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int H,N;
bool used[100001];

struct line{
	int b,e,t;
}a[1005],mid; 

bool Cmp(line x , line y)
{
	return x.e<y.e;
}

int main()
{
	cin>>N>>H;
	for(int i=0;i<H;i++)
	{
		cin>>a[i].b>>a[i].e>>a[i].t;
	}
	sort(a+1,a+N+1,Cmp);
	int ans=0,k;
	for(int i=1;i<=H;i++)
	{
		k=0;
		for(int j=a[i].b;j<=a[i].e;j++)
		{
			if(used[j])
			{
				k++;
			}
		}
		if(a[i].t<=k)
		{
			continue;
		}
		for(int j=a[i].e;j>=a[i].b;j--)
		{
			if(!used[j])
			{
				k++;
				ans++;
				if(k==a[j].e)
				{
					break;
				}
			}
			
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
