#include<bits/stdc++.h>
using namespace std;

int n,m;
set<pair<int,pair<int,int>>> s;	
class obj
{
    public:
    int p,c;
    obj()
    {
        p=0;
        c=0;
        am=0;
    }
};                                                                                                                                    
class dsu
{
    public:
    obj* d;
    dsu(int n)
    {
        d = new obj[n];
        for(int i=0;i<n;i++)
        {
            d[i].p=i;
            d[i].c=i;
            d[i].am=1;
        }
    }
    int getx(int x)
    {
        if(d[x].p==x)
        {
            return x;
        }
        else
        {
            int ans=getx(d[x].p);
            d[x].p=ans;
            return ans;
        }
    }
    void Union(int x,int y)
    {
        int headx=getx(x);
        int heady=getx(y);
        if(headx==heady)
            return;
        d[heady].p=d[headx].c;
        d[headx].c=d[heady].c;
        if()
        d[headx].am=d[headx].am+d[heady].am;
    }

    obj operator[](int x)
    {
        return d[x];
    }
};
int main()
{
	cin>>n>>m;
	for(int i = 0;i<m;i++)
	{
		int l,r,k;
		cin>>l>>r>>k;
		s.insert(make_pair(k, make_pair(l, r)));
	}
	long long ans = 1000000001+1000000001;
	for(int i = 0;i < m;i++)
	{
		dsu j(n+1);
		long long mn=1000000001,mx=-1000000001;
		int k = 0;
		for(auto&t:s)
		{
			if(k>=i)
			{
				int v=t.second.first, u=t.second.second;
				if(j.getx(v)!=j.getx(u))
				{
					mn = min(mn, t.first * 1ll);
					mx = max(mx, t.first * 1ll);
					j.Union(v,u);
				}
			}
			k++;               
		} 
		int ch = 1;
		for(int z = 2;z<n;z++)
			if(j.getx(z) != j.getx(1))
				ch = 0;
		if(ch)
		{
			if(ans > abs(mx-mn))
				ans = abs(mx-mn);			
		}	
	}
	if(ans != 1000000001+1000000001)  
	{	
	    cout<<"YES\n";
		cout<<ans;
	}
	else
	{
		cout<<"NO";
	}
	return 0;

}