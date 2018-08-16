void dfsone(int x)
{
	vst[x]=1;
	for(int i=0;i<=n;i++)
	{
		if(!vst[i]&&map[x][i])
		{
			dfsone(i);
		}
	}
	d[++t]=x;
 } 
 void dfstwo(int x)
 {
 	vst[x]=t;
	for(int i=0;i<=n;i++)
	{
		if(!vst[i]&&map[x][i])
		{
			dfstwo(i);
		}
	}
 }
 void kosaraju()
 {
	int i,t=0;
	for(int i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			dfstwo(i);
		}
	}
	memset(vst,0,sizeof(vst))
	t=0;
	for(int i=n;i>=1;i--)
	{
		if(!vst[d[i]])
		{
			t++;
			dfstwo(d[i]);
		}
	}
 }
