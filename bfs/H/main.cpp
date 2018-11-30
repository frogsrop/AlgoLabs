#include<bits/stdc++.h>
using namespace std;

int n,m;
set<pair<int,pair<int,int>>> s;	
class obj
{
    public:
    int p,c,min_,max_,am;
    obj()
    {
        p=0;
        min_=0;
        max_=0;
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
            d[i].min_=i;
            d[i].max_=i;
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
        d[headx].min_=min(d[headx].min_,d[heady].min_);
        d[headx].max_=max(d[headx].max_,d[heady].max_);
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
		s.insert(make_pair(k,make_pair(l,r)));
	}
	dsu j(n+1);
	int ans=0;
	while(s.size())
	{
		int v=(*s.begin()).second.first, u=(*s.begin()).second.second;
		if(j.getx(v)!=j.getx(u))
		{
			j.Union(v,u);
			ans+=(*s.begin()).first;
		}
		s.erase(s.begin());
	}
	cout<<ans;
	return 0;

}