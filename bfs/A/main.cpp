#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>

#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cstring>

#include<cmath>

#include<algorithm>




#define ll long long
#define pb push_back
#define f first
#define s second
#define all(c) c.begin(),c.end()



using namespace std;

	const int N=300001;	

	int n,m,used[N],d[N],p[N];
	vector<int> graph[N];
	queue<int> q;
	void bfs(int s)
	{	
		q.push (s);
		used[s] = 1;
		p[s] = -1;
		while (!q.empty()) 
		{
			int v = q.front();
			q.pop();
			for (size_t i=0; i<graph[v].size(); i++) 
			{
				int to = graph[v][i];
				if (used[to]==0) 
				{
					used[to]=1;
					q.push(to);
					d[to] = d[v] + 1;
					p[to] = v;
				}
			}
		}
	}
int main()
{
	ios_base::sync_with_stdio(0);
	int l,k;
    cin>>m>>n;
	for(size_t i=0; i < (size_t)n;i++)
	{
       	cin>>l>>k;
       	graph[l].pb(k);
       	graph[k].pb(l);
    }
    bfs(1);
    for(size_t i = 1; i <= (size_t) m; i++)
    {
    	cout<<d[i]<<' ';
	}
	return 0;
}