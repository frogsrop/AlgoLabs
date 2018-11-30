#include<bits/stdc++.h>

using namespace std;

int parent[300005];
int am[300005];
int r[300005];

void make(int x)
{
	parent[x]=x;
	am[x]=1;
	r[x]=0;
}

int get(int x)
{
	if(parent[x]==x)
	{
		return x;
	}
	else
	{
		int root = get(parent[x]);
		parent[x]=root;
		return root;
	}
}

void union_(int x, int y) {
	x = get(x);
	y = get(y);
	if (x != y) {
		if(r[x] < r[y])
			swap (x, y);
		parent[y] = x;
		am[x] += am[y];
		if(r[x]==r[y])
		{
			r[x]++;
		}
	}
}
const int N = 100001;
vector<int> g[N];
int used[N];
int n,m;
bool DFS(int v)
{
	used[v] = 1;
	if(g[v].size()>1)
	{
		for(size_t i = 1;i<g[v].size();i++)
		{
			int q = g[v][i-1];
			int w = g[v][i];
			if(get(v)==get(q) || get(v)==get(w))
				return 0;
			else
				union_(q, w);
		}
	}
	bool ans = 1;
	for(size_t i = 0;i<g[v].size();i++)
	{
		int u = g[v][i];
		if(used[u]==0)
		{
			ans &= DFS(u);
		}
	}
	return ans;	
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("bipartite.in","r",stdin);
	freopen("bipartite.out","w",stdout);     	
	cin>>n>>m;
	for(int i = 0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 1;i<=n;i++)
		make(i);
	bool ans = 1;	
	for(int i = 1;i<=n;i++)
	{
		if(used[i] == 0)
		{
			ans&=DFS(i);	
		}
	}
	cout<<(ans?"YES":"NO");
	return 0;
}
