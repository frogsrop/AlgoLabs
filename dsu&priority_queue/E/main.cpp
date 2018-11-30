#include<bits/stdc++.h>

using namespace std;


class dsu
{
    public:
	
	int* parent;
	int* rank;
	int *mx,*mn;
	dsu(int n)
	{
		parent = new int[n];
		rank = new int[n];
		mx=new int[n];
		mn=new int[n];
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
			rank[i]=0;
			mx[i]=mn[i]=i;
		}
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
			if(rank[x]>rank[y])
			{
				swap(x,y);
			}
			parent[x] = y;
			mx[y]=max(mx[y],mx[x]);
			mn[y]=min(mn[y],mn[x]);
			if(rank[x]==rank[y])
			{
				rank[y]++;
			}
		}
	}  	
};
int main()
{
	freopen("restructure.in","r",stdin);
    freopen("restructure.out","w",stdout);
    int n;
    int m;
	cin>>n;
	cin>>m;
	dsu d(n);
	dsu hlp(n);
	for(int i=0;i<m;i++)
    {
        int buf;
        scanf("%d",&buf);
        if(buf==1)
        {
        	int x,y;
        	scanf("%d %d",&x,&y);
        	x--;
        	y--;
        	d.union_(x,y);
        }
        if(buf==2)
        {
        	int x,y;
        	scanf("%d %d",&x,&y);
        	x--;
        	y--;
        	for(int i=x;i<y;i++)
        	{
        		int xhlp=hlp.get(i),yhlp=hlp.get(i+1);
        		if(xhlp==yhlp)
        		{
        			i=hlp.mx[xhlp];
        			i--;
        		}
        		else
        		{
        			d.union_(i,i+1);
        			hlp.union_(i,i+1);
        		}
        		
        	}
        }
        if(buf==3)
        {   
        	int x,y;
        	scanf("%d %d",&x,&y);
        	x--;
        	y--;
        	if(d.get(x)==d.get(y))
        	{
        		printf("YES\n");
        	}
        	else
        	{
        		printf("NO\n");
        	}
        }
    }
	return 0;
}
