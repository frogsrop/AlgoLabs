#include<bits/stdc++.h>

using namespace std;

const int N = 100005; 

int tin[N];
int up[N];
int used[N];
int used1[N];
vector<int> ans; 
vector< pair<int,int> > g[N];
set<pair<int,int>> ss;
int n, m, t;

void dfs (int v, int p) {
	used[v] = 1;
	tin[v] = up[v] = t;
	t++;
	for (size_t i = 0; i < g[v].size(); i++) {
		int u = g[v][i].first;
		if (u == p)  
			continue;
		if (used[u])
			up[v] = min (tin[u], up[v]);
		else 
		{
			dfs (u, v);
			up[v] = min (up[v], up[u]);
			if (tin[v] < up[u] && ss.find(make_pair(v,u))==ss.end())
			{
				ans.push_back(g[v][i].second);	
				ss.insert(make_pair(v,u));
				ss.insert(make_pair(u,v));
			}
		}
	}
}

void clr(int v, int cl)
{
	used1[v] = cl;
	for(size_t i = 0; i < g[v].size();i++)
	{
		int u = g[v][i].first;
		if(ss.find(make_pair(v,u))!=ss.end())
			continue;
		if(used1[u]==0)
			clr(u, cl);
	}
} 
int main()
{
	ios_base::sync_with_stdio(0);
    freopen("bicone.in", "r", stdin);
    freopen("bicone.out", "w", stdout);
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
		int x,y;
		cin>>x>>y;
		g[x].push_back(make_pair(y, i +1));
		g[y].push_back(make_pair(x, i +1));
    }
    t = 0;
	for (int i=1; i<=n; i++)
		if (!used[i])
			dfs(i, -1);
	int color = 1;
	for (int i = 1; i<=n; i++)
		if (!used1[i])
		{
			clr(i, color);
			color++;
		}      
	cout<<color - 1<<endl;
	for(int i = 1; i<=n;i++)
		cout<<used1[i]<<' ';
	return 0; 
}