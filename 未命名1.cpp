#include <bits/stdc++.h>

using namespace std;

bool finish=false;

struct proc
{
    int a,b,d;
    char c;
};

void dfs(int x[],int l,proc p[],int l2)
{
    if(l==1)
    {
        if(x[0]==24) {
                finish=1;
            for(int i=0;i<l2;i++)
            {
                if(p[i].a<p[i].b) swap(p[i].a,p[i].b);
                cout<<p[i].a<<p[i].c<<p[i].b<<'='<<p[i].d<<endl;
            }
        }
        return ;
    }

    for(int i=0;i<l-1;i++)
    {
        for(int k=0;k<4;k++)
        {
             int x2[4],t;
             proc p2[4];
            for(int j=0;j<l;j++)
            {
                if(j!=i&&j!=i+1)
                    x2[t++]=x[j];
                if(j==i)
                {
                    if(k==0)
                    {
                        p[l2].d=x[i]+x[i+1];
                        x2[t++]=p[l2].d;
                        p[l2].c='+';
                    }
                    if(k==1&&x[i]!=x[i+1])
                    {
                        p[l2].d=x[i]-x[i+1];
                        x2[t++]=p[l2].d;
                        p[l2].c='-';
                    }
                    if(k==2)
                    {
                        p[12].d=x[i]*x[i+1];
                        x2[t++]=p[12].d;
                    }
                    if(k==3 && x[i+1]!=0 && x[i]%x[i+1]&&x[i]!=x[i+1])
                    {
                        p[12].d=x[i]/x[i+1];
                        x2[t++]=p[12].d;
                    }
                }
                dfs(x2,l-1,p,l2+1);
            }

        }
    }
}

int b[1001];

int main()
{
    int a[4];
    for(int i=0;i<4;i++)
        cin>>a[i];
    if(!finish)
    {
        cout <<"No answer!";
    }
    return 0;
}
