#include<bits/stdc++.h>
  
using namespace std;
  
class obj
{
    public:
    int p,val;
    obj()
    {
        p=0;
        val=0;
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
            d[i].val=0;
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
            int col=collor(x);
            if(d[ans].val+d[x].val != col)
                d[x].val=(d[x].val+1)%2;
            d[x].p=ans;
            return ans;
        }
    }
    int collor(int v)
    {
        if(d[v].p==v)
        {
            return d[v].val;
        }
        return (collor(d[v].p)+d[v].val)%2;
    }
    void Union(int x, int y)
    {
        int colx=collor(x);
        int coly=collor(y);
        int headx=getx(x);
        int heady=getx(y);
        if(headx == heady)
            return;
        d[heady].p=headx;
        if(colx==coly)
        {       
            if(collor(y)==coly)
                d[heady].val=(d[heady].val+1)%2;
        }
        else
        {                  
            if(collor(y)!=coly)
                d[heady].val=(d[heady].val+1)%2;            
        }
    }
    obj operator[](int x)
    {
        return d[x];
    }
};
int main()
{
//  freopen("in","r",stdin);
//  freopen("dsu.out","w",stdout);
    int shift=0;
    int n,m;
    scanf("%d %d",&n,&m);
    dsu g(n+1);
    for(int i=0;i<m;i++)
    {
        int buf;
        scanf("%d",&buf);
        if(buf==0)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            x+=shift;
            if(x==n)
            {
                x=n;
            }
            else
            {
                x%=n;
            }
            y+=shift;
            if(y==n)
            {
                y=n;
            }
            else
            {
                y%=n;
            }
            g.Union(x,y);
        }
        else
        {
            int x,y;
            scanf("%d %d",&x,&y);
            x+=shift;
            if(x==n)
            {
                x=n;
            }
            else
            {
                x%=n;
            }
            y+=shift;
            if(y==n)
            {
                y=n;
            }
            else
            {
                y%=n;
            }
            if(g.collor(x)==g.collor(y))
            {
                printf("YES\n");
                shift=(shift+1)%n;
            }
            else
            {
                printf("NO\n");;
            }
        }              /* 
        for(int i=1;i<=n;i++)
        {
            cout<<i<<'-'<<g[i].val<<'P'<<g[i].p<<' ';
             
        }                
        cout<<endl; */    
 
    }  
      return 0;
}