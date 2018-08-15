void bfs(int v)
{
	vector <int> q;
	q.push(v);
	vis[v]=true;
	while( !q.empty())
	{
		v = q.front();
		q.pop()
		cout<< v <<" ";
		for(int i=0;i<GV[v].size();i++)
		{
			if(!vis[GV][v][i].v)
			{
				q.push(GV[v][i].v)
				vis[GV[v][i].v]=true;
			}
		}
	}
}