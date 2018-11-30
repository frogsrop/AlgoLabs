#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int > > g[1001];
vector<pair<int,int>> v;
set<pair<int,int>> zz;
int used[10001];
int n, m;

int dfs(int v, int cl)
{
	used[v] = cl;
	for(int i = 0; i<g[v].size();i++)
	{
		int u = g[v][i].first;
		if(zz.find(make_pair(v,u))==zz.end())
		{
			continue;
		}
		if(used[u]==0)
		{
			if (g[v][i].second == 1)
			{
				return dfs(u,cl);
			}
			else
			{
				return dfs(u,3-cl);
			}
		}
		else
		if(used[u]==used[v])
		{
			if(g[v][i].second == 0)
			{
				return 0;		
			}
		}
		else
		if(used[u]!=used[v])
		{
			if(g[v][i].second == 1)
			{
				return 0;		
			}
		}
	}
	return 1;
}

int main()
{
	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		int x,y;
		cin>>x>>y;
		char c;
		cin>>c;
		bool z = (c=='T'?1:0);
		g[x].push_back(make_pair(y,z));
		v.push_back(make_pair(x,y));
	}
	int l = 0, r = n;
	while(l+1<r)
	{
		int m = (l+r)/2;
		zz.clear();
		for(int q = 0;q<m;q++)
		{
			zz.insert(v[q]);		
		}
		bool b;
		for(int i  = 1;i<n;i++)
		{
			b = 0;
			if(dfs(i,1)==0)
			{
				b = 1;
				break;
			}
		}
		if(b)
			r = m;
		else
			l = m;
	}
	cout<<l;
	return 0;
}