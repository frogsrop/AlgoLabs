#include<bits/stdc++.h>

using namespace std;

const int N = 100005; 

int tin[N];
int up[N];
int used[N];
vector<int> ans; 
vector<int> g[N];
set<int> ss; 
int n, m, t;

void dfs (int v, int p) 
{
	used[v] = 1;
	tin[v] = up[v] = t;
	t++;
	int ch = 0;
	for (size_t i=0; i < g[v].size(); i++) 
	{
		int u = g[v][i];
		if (u == p)  continue;
		if (used[u])
			up[v] = min (up[v], tin[u]);
		else 
		{
			dfs (u, v);
			up[v] = min (up[v], up[u]);
			if (up[u] >= tin[v] && p != -1)
				ss.insert(v);
			ch++;
		}
	}
	if (p == -1 && ch > 1)
		ss.insert(v);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
    freopen("points.in", "r", stdin);
    freopen("points.out", "w", stdout);
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
    }
    t = 0;
	for (int i=1; i<=n; i++)
		if (!used[i])
			dfs(i, -1);
	cout<<ss.size()<<endl;
	for(auto &zz: ss)
		cout<<zz<<endl;   
	return 0; 
}