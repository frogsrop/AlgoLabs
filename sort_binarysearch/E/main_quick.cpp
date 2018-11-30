#include<bits/stdc++.h>

using namespace std;


int main()
{
	freopen("radixsort.in","r",stdin);
	freopen("radixsort.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	string x[1005];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	vector<int> v[27], w[27];
	for(int i=0;i<n;i++)
	{
		v[int(x[i][m-1]-'a')].push_back(i);
	}
	for(int i=1;i<k;i++)
	{
		for(int j=0;j<27;j++)
		{
			if(v[j].size()>0)
			{
				while(v[j].size())
				{
					w[int(x[v[j][0]][m-i-1]-'a')].push_back(v[j][0]);
					v[j].erase(v[j].begin());
				}
			}
		}
		swap(v,w);		
	}
	for(int j=0;j<27;j++)
	{
		if(v[j].size()>0)
		{
			for(int i=0;i<int(v[j].size());i++)
				cout<<x[v[j][i]]<<endl;
		}
	}
	return 0;
}                                                 