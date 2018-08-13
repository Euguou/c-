#include <bits/c++config.h>
#include <iostream>
#include <cstdio> 
using namespace std;	
int a,b,c,d,e,f,n,q,w,r;	
int sum,Sn,Sa; 
int main()
{
	
	cin>>n;//n为要购买的支数 
	cin>>a>>b>>c>>d>>e>>f;
	q=n%a;
	if(q!=0)
		sum=(q+1)*b;
	else
		sum=q*b;
	w=n%c;
	if(w!=0)
		Sn=(w+1)*d;
	else
		Sn=w*d;
	r=n%e;
	if(r!=0)
		Sa=(r+1)*f;
	else
		Sa=r*f;
	if(sum>Sa>Sn)
		printf("%d",Sn);
	if(sum>Sn>Sa)
		printf("%d",Sa);
	if(Sa>sum>Sn)
		printf("%d",Sn);
	if(Sa>Sn>sum)
		printf("%d",sum);
	if(Sn>Sa>sum)
		printf("%d",sum);
	if(Sn>sum>Sa)
		printf("%d",Sa);
	return 0;
}
