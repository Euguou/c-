#include <bits/stdc++.h>

 using namespace std;

 long long a[1000000];
 int b[105];
 int ans;

 int main()
 {
 	int N;
 	cin>>N;
 	for(int i=0;i<N;i++)
 	{
 		cin>>a[i];
 		b[i]=1;
	}
 	for(int i=1;i<N;i++)
 	{
 		for(int j=0;j<i;j++)
		{
			 if(a[i]<a[j])
			 {
			 	b[i]=max(b[i],b[j]+1);
			 }
		}
	}
	for(int i=0;i<N;i++)
	{
		ans=max(ans,b[i]);
	}
	cout<<ans;
	return 0;
 }
