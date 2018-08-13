#include <bits/stdc++.h>

using namespace std;
int a[1001];

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }

    for(int i=0;i<N;i++)
    {
        cout<<a[i]<<" " ;
    }
    return 0;
}
