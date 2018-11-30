#include<bits/stdc++.h>

using namespace std;

vector<int> g[20001];
vector<int> h[20001];

vector<int> used1(20001, 0);
vector<int> used2(20001, 0);

vector<int> ord;

int n,m;

void dfsSort(int v)
{
	used1[v] = 1;
	for(size_t i = 0; i < g[v].size(); i++)
	{
		int  u = g[v][i];
		if(!used1[u])
		{
			dfsSort(u);
		}
	}
	ord.push_back(v);
}
void dfsCollor(int v, int& collor)
{
	used2[v] = collor;
	for(size_t i = 0; i < h[v].size(); i++)
	{
		int  u = h[v][i];
		if(used2[u] == 0)
		{
			dfsCollor(u, collor);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("cond.in", "r", stdin);
	freopen("cond.out", "w", stdout);
	cin>>n>>m;
	for(int i = 0; i < m ; i++)
	{
		int x, y;
		cin >> x >> y;  
		g[x].push_back(y);
		h[y].push_back(x);
	}
	for(int  i = 1; i <= n; i++)
	{
		if(!used1[i])
		{
			dfsSort(i);
		}
	}
	int collor = 1;
	for(int i = n-1; i >= 0; i--)
	{
		if(!used2[ord[i]])
		{
			dfsCollor(ord[i], collor);
			collor++;
		}
	}   
	cout << collor - 1 << endl;
	for(int i = 1; i <= n; i++)
	{
		cout << used2[i] << ' ';
	}
	return 0;
}