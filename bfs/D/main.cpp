#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 300001;
const ll INF = N*1ll*1000000005;

vector<pair<int, int>> g[N]; 
ll d[N + 1];
int u[N + 1];
int s, f, n, m;
         
int main()
{
	//ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		int x, y , z;
		scanf("%d %d %d", &x, &y, &z);
		g[x].push_back(make_pair(y, z));
		g[y].push_back(make_pair(x, z));
	}
	for(int i = 1; i <= n; i++)
	{
		d[i] = INF;
		u[i] = 0;
	}
	d[1] = 0;
	//djikstra  fast
	set<pair<int,int>> q;
	q.insert(make_pair(0, 1));	
	while(!q.empty())
	{
		int v = q.begin()->second;
		int val = q.begin()->first;
		q.erase(q.begin());
		for(size_t i = 0; i< g[v].size(); i++)
		{
			int to = g[v][i].first;
			if(u[to] == 1)
				continue;
			if(q.find(make_pair(d[to], to)) != q.end())
				q.erase(make_pair(d[to], to));
			d[to] = min(d[to], 0ll + val + g[v][i].second);
			q.insert(make_pair(d[to], to));
		}
		u[v] = 1;	
	}
	for(int i = 1; i<=n; i++)
	{
		cout << d[i] << ' ';
	}
	return 0;
}