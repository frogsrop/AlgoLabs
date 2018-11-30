#include<bits/stdc++.h>

using namespace std;

int n,m,a[5005],b[5005],c[5055][5055];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("levenshtein.in","r",stdin);
	freopen("levenshtein.out","w",stdout);
    cin>>s;
	n=s.size();
	for(int i=0;i<(int)s.size();i++)
	{
		a[i+1]=int(s[i]);
	}
	cin>>s;
	m=s.size();
	for(int i=0;i<(int)s.size();i++)
	{
		b[i+1]=int(s[i]);
	}
	for(int i=1;i<=max(n,m);i++)
	{
		c[0][i]=c[i][0]=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
				c[j][i]=c[j-1][i-1]+!(a[j]==b[i]);
				c[j][i]=min(c[j][i],min(c[j-1][i],c[j][i-1])+1);
		}
	}
	cout<<c[n][m];
	return 0;
}




