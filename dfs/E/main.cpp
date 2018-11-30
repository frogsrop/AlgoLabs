#include<bits/stdc++.h>

using namespace std;

vector<int> g[100001];
int n, m;
vector<int> p;
vector<int> ans;
int used[100001];
void isCyclic(int v)
{
	used[v] = 1;
	p.push_back(v);
	for(size_t i = 0; i < g[v].size(); i++)
	{
		int u = g[v][i];
		if(used[u] == 0)
			isCyclic(u);
		else
		if(used[u] == 1)
		{
			ans = p;
			ans.push_back(u);
		}
	}
	used[v] = 2;
	p.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("cycle.in", "r", stdin);
	freopen("cycle.out", "w", stdout);
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
    	int x, y;
    	cin>>x>>y;
    	g[x].push_back(y);
    }
    for(int i = 1; i <= n; i++)
    {
    	if(used[i] == 0)
    	{
    		p.clear();
    		isCyclic(i);  
    	} 
    }

    if(ans.size())
    {              	
    	cout<<"YES\n";
    	int x = ans.back();
    	int i = 0; 
    	while(ans[i] != x)
    		i++;     
    	for(;i < (int)ans.size()-1; i++)
    		cout<<ans[i]<<' ';
    	
    }
    else
    {
    	cout<<"NO";
    }
	return 0;
}