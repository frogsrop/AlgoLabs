#include<bits/stdc++.h>

using namespace std;


class dsu
{
    public:
	
	int* parent;

	dsu(int n)
	{
		parent = new int[n];
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
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
			parent[x] = y;
		}
	}  	
};
int main()
{
	freopen("parking.in","r",stdin);
    freopen("parking.out","w",stdout);
    int n;
	cin>>n;
	dsu d(n);   
	for(int i=0;i<n;i++)
    {
        int buf;
        cin>>buf;
        buf--;
        int ans=d.get(buf);
        cout<<ans+1<<' ';
        d.union_(ans,(ans+1)%n);
    }
	return 0;
}
