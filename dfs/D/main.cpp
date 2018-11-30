#include<bits/stdc++.h>

using namespace std;

vector<int>  g[100001];

bool used[100001];
bool ans[100001];
int n, m;
int s,p;
vector<int> topSort;
void dfsTopSort(int v)
{
	used[v] = 1;
	for(size_t i  = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
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
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin>>n>>m>>s;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	dfsTopSort(s);
	for(size_t i = 0; i < topSort.size(); i++)
	{
		int v = topSort[i]; 
		ans[v] = 0;         
		for(size_t j = 0; j < g[v].size(); j++)
		{
			int u = g[v][j];
			if(ans[u] == 0)
			{
				ans[v] = 1;
				break;
			}
		}
	}
	cout<<(ans[s]?"First player wins":"Second player wins");
	return 0;
	
}
