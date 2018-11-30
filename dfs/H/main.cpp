#include<bits/stdc++.h>

using namespace std;

const int N = 100005; 

int tin[N];
int up[N];
int used[N];
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
 
int main()
{
	ios_base::sync_with_stdio(0);
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
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
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(size_t i  = 0; i < ans.size();i++)
		cout<<ans[i]<<' ';   
	return 0; 
}