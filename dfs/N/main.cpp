#include<bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int g[MAX][MAX], take[MAX][MAX];
int used[MAX];
int n;
void dfs(int v, int type)
{
	int i;
	used[v] = 1;
	for(i = 0; i < n; i++)
	{
		if(type)
		{
			if(take[i][v] && !used[i])
				dfs(i,type);
		}
		else
		{
			if (take[v][i] && !used[i])
				dfs(i,type);
		}	
	}
}

bool check()
{
  for(int i = 0; i < n; i++)
    if (!used[i]) return 0;
  return 1;
}

void clUsed()
{
	for(int i = 0 ;i<MAX;i++)
		used[i] = 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("avia.in","r",stdin);
    freopen("avia.out","w",stdout);
    cin>>n;
    for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
		    int value;
			cin>>value;
			g[i][j] = value;
		}
	}
	int l = 0; 
	int r = 0xFFFFFFFF>>1;
	while(l < r)
	{
		int mid = (l + r) / 2;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
    		{
    			if(g[i][j] <= mid)
    				take[i][j] = 1;
    			else
    				take[i][j] = 0;
    		}
	 	}
	 	clUsed();
	 	dfs(0,0); 
  		int flag = 0;
  		if(check())
  		{
    		clUsed();
    		dfs(0,1);
    		if (!check())
    		{ 
    			flag = 1;
			}
  		} 
  		else 
  		{
  			flag = 1;
  		}
  		if (!flag) 
  			r = mid; 
  		else 
  			l = mid + 1;
	}
	cout<<l;
	return 0;
}