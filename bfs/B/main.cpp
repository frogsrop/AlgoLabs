#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 2001;
const ll INF = 3000000000000;

int g[N + 1][N + 1];
ll d[N + 1];
int u[N + 1];
int s, f, n;
         
int main()
{
	//ios_base::sync_with_stdio(0);
	cin>>n>>s>>f;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &g[i][j]);
		}	
	}
	for(int i = 1; i <= n; i++)
	{
		d[i] = INF;
		u[i] = 0;
	}
	d[s] = 0;
	//djikstra
	for(int i = 1; i<=n; i++)
	{
		int v = -1;
		for(int j = 1; j <= n; j++)
		{
			if(u[j]==0 && (v==-1 || d[j]<d[v]))
			{
				//relax
				v = j;
			}
		}
		if(d[v] == INF)
			break;
		for(int j = 1; j <= n; j++)
		{
			if(g[v][j] != -1)
			{
				d[j] = min(d[j], d[v] + g[v][j]);
			}
		}
		u[v] = 1;
	}
	cout<<(d[f]==INF?-1:d[f]);
	return 0;
}