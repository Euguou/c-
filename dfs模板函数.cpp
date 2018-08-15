void dfs(int v)
{
	cout<< v <<" ";
	vis[v] = true;
	for(int i=0;i <GV[v].size();i++)
	{
		if(!vis[GV[v][i].v)
		{
			dfs(GV[v][i].v);
		}
	}
}