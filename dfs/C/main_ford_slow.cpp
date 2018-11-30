#include<bits/stdc++.h>

using namespace std;
             
vector< pair< int, pair<int, int> > >  g;
int ans[100001];
int n, m;
int s,p;
void fordBelm()
{
	for(;;)
	{
		bool changed = 0;
		for(int j = 0; j < m; j++)
		{
			if(ans[g[j].second.first] < int(0xFFFFFFFFu >> 1))
			{
				if(ans[g[j].second.second] > ans[g[j].second.first] + g[j].first)
				{
					ans[g[j].second.second] = ans[g[j].second.first] + g[j].first;
					changed = 1;	
				}             
			}
		}
		if(!changed)
			break;
	}
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
		g.push_back(make_pair(z, make_pair(x, y)));
	}
	for(int i = 1; i <= n; i++)
	{
		ans[i] = int(0xFFFFFFFFu >> 1);
	}
	ans[s] = 0;
	fordBelm();
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