#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 200;
const ll INF = N * 10005;

ll g[N + 1][N + 1];
ll d[N + 1];
int u[N + 1];
int s, f, n, m;
         
int main()
{
	//ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			g[i][j] = INF;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d %d",&x,&y);
		scanf("%lld", &(g[x][y]));
	}
	//Floid
	for (int k = 1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i==j)
				cout<<0<<' ';
			else
				cout<<g[i][j]<<' ';
		}
		cout<<endl;
	}	
	return 0;
}