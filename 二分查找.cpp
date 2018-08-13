#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int a[1000000];
int mid;

int main()
{
    int N;
    cin>>N;
    int i;
    int left,right;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }
    left = 0;
    right = N-1;
    int X;
    cin>>X;
    while (left<right)
    {
        mid=(left + right)/2;
        if(X>a[mid])
        {
            left = mid+1;
        }
        if(X<=a[mid])
        {
            right=mid;
        }
    }
    if(a[left]==X)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
