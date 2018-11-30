#include<bits/stdc++.h>

using namespace std;

vector<int> g[100001];
int n, m;
bool flag = 0;
vector<int> ans;
vector<int> used(100001, 0);
void top_sort(int v)
{
	used[v] = 1;
	for(size_t i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(used[u] == 1)
			flag = 1;
		if(used[u] == 0)
			top_sort(u);
	}
	used[v] = 2;
	ans.push_back(v);
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("topsort.in", "r", stdin);
	freopen("topsort.out", "w", stdout);
	cin>>n>>m;
	for(int i = 0; i<m; i++)
	{
		int x, y;
		cin>>x>>y;
		g[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			top_sort(i);
		}
	}
	if(flag)
	{
		cout<<-1;
		return 0;					
	}
	for(size_t i = ans.size(); i--;)
	{	
		cout<<ans[i]<<' ';
	}
	return 0;
}