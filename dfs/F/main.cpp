#include<bits/stdc++.h>

using namespace std;

vector<int> g[100001];
 
vector<int> used(100001, 0);
vector<int> top;
vector<int> ord;

int n,m;

void dfs(int v)
{
	used[v] = 1;
	for(size_t i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(used[u] == 0)
		{
			dfs(u);
		}
	}   	
	top.push_back(v);
}

bool ex(int v, int u)
{
	for(size_t i = 0; i<g[v].size();i++)
	{
		if(g[v][i]==u)
			return 1;	
	}	
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("hamiltonian.in", "r", stdin);
	freopen("hamiltonian.out", "w", stdout);
	cin>>n>>m;
	for(int i = 0; i < m ; i++)
	{
		int x, y;
		cin >> x >> y;  
		g[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)
	{	
		if(!used[i])
			dfs(i);
	}
	for(int  i = top.size()-1; i>=1;i--)
	{
		if(!ex(top[i],top[i-1]))
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}