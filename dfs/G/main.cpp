#include<bits/stdc++.h>

using namespace std;

int n, m;



vector<int> g[100001];
vector<int> ord;
int used[100001];
bool used1[100001];

void top_(int v)
{
	used1[v] = 1;
	for(size_t i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(!used1[u])
		{
			top_(u);
		}
	} 
	ord.push_back(v);
}

void dfs(int v, int color)
{
	used[v] = color;
	for(size_t i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(!used[u])
		{
			dfs(u, color);
		}
	} 
}

int main()
{
	freopen("components.in", "r", stdin);
	freopen("components.out", "w", stdout);
	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin>>x>>y;
		g[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)
	{           
		if(!used1[i])
		{
			top_(i);
		}
	}
	reverse(ord.begin(), ord.end());
	int color = 1;
	for(int i = 0; i < n; i++)
	{
		if(!used[ord[i]])
		{
			dfs(ord[i], color);
			color++;
		}
	}
	cout<<color - 1<<endl;
	for(int i = 1; i <= n; i++)
	{
		cout << used[i] << ' ';
	}	
	return 0;
}