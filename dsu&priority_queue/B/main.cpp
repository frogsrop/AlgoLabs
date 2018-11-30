#include<bits/stdc++.h>
 
using namespace std;
 
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
    freopen("dsu.in","r",stdin);
    freopen("dsu.out","w",stdout);
    int n;
    cin>>n;
    dsu m(n+1);
    char s[100];
    while(scanf("%s",s)==1)
	{
        if(strlen(s)==3)
		{
		    int x;
        	scanf("%d",&x);
		    x--;
            int head=m.getx(x);
            printf("%d %d %d\n",m[head].min_+1,m[head].max_+1,m[head].am);
		
        }
        if(strlen(s)==5)
        {
            int x,y;
            scanf("%d %d",&x,&y);
			x--;
            y--;
            m.Union(x,y);
        }
    }
    return 0;
}