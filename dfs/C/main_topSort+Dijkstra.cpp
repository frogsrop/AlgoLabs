#include<bits/stdc++.h>

using namespace std;

vector< pair<int, int> >  g[100001];
bool used[100001];
int ans[100001];
int n, m;
int s,p;
vector<int> topSort;
void dfsTopSort(int v)
{
	used[v] = 1;
	for(size_t i  = 0; i < g[v].size(); i++)
	{
		int u = g[v][i].first;
		if(used[u] == 0)
		{
			dfsTopSort(u);
		}
	}
	topSort.push_back(v);
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("shortpath.in", "r", stdin);
	freopen("shortpath.out", "w", stdout);
	cin>>n>>m>>s>>p;
	for(int i = 0; i < m; i++)
	{
		int x, y, z;
		cin>>x>>y>>z;
		g[x].push_back(make_pair(y, z));
	}
	for(int i = 1; i<=n; i++)
	{
		ans[i] = 0xFFFFFFFFu >> 1;
	}
	ans[s] = 0;
	dfsTopSort(s);
	reverse(topSort.begin(), topSort.end());
	for(size_t i  = 0; i < topSort.size(); i++)
	{
		int v = topSort[i];
		for(size_t j = 0; j < g[v].size(); j++)
		{
			int u = g[v][j].first;
			int mass = g[v][j].second;
			ans[u] = min(ans[u], ans[v] + mass);
		}
	}
	if(ans[p] < int(0xFFFFFFFFu >> 1))  
	{
		cout << ans[p];
	}
	else
	{
		cout << "Unreachable";
	}
	return 0;	
}