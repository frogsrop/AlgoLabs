#include<bits/stdc++.h>

using namespace std;

int parent[300005];
int mx[300005];
int mn[300005];
int am[300005];
int r[300005];
void make(int x)
{
	parent[x]=x;
	mx[x]=x;
	mn[x]=x;
	am[x]=1;
	r[x]=0;
}

int get(int x)
{
	if(parent[x]==x)
	{
		return x;
	}
	else
	{
		int root=get(parent[x]);
		parent[x]=root;
		return root;
	}
}

void union_(int x, int y) {
	x = get(x);
	y = get(y);
	if (x != y) {
		if(r[x] < r[y])
			swap (x, y);
		parent[y] = x;
		am[x] += am[y];
		if(r[x]==r[y])
		{
			r[x]++;
		}
		mn[x]=min(mn[x],mn[y]);
		mx[x]=max(mx[x],mx[y]);
	}
}

int main()
{
	freopen("dsu.in","r",stdin);
	freopen("dsu.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		make(i);
	}
	char s[100];
	while(scanf("%s",s)==1)
	{
		int x=0,y=0;
		if(strlen(s)==3)
		{
			scanf("%d",&x);
			int head=get(x);
			printf("%d %d %d\n",mn[head],mx[head],am[head]);
		}
		if(strlen(s)==5)
		{
			scanf("%d %d",&x,&y);
			union_(x,y);	
		}
	}
	return 0;
}
