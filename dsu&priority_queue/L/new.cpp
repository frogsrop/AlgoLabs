#include<bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;

class obj{
public:
	obj* par;
	ll val;
	ll sum;
	obj()
	{
		par=this;
		val=0;
		sum=0;	
	}
};
     
class pers_stack{
public:
	obj *vers;
	int	op=0; 
	pers_stack(int sz)
	{
		op=1;
		vers=new obj[sz];
	}
	void add(int num,ll val)
	{
		vers[op].par=&vers[num];
		vers[op].val=val;
		vers[op].sum=vers[num].sum+val;	
		op++;
	}
	void erase(int num)
	{
		vers[op].par=(*vers[num].par).par;
		vers[op].val=(*vers[num].par).val;
		vers[op].sum=(*vers[num].par).sum;
		op++;
	}
	ll operator [](int x)
	{
		return vers[x].sum;
	}
};  
   
int main()
{
//	freopen("in","r",stdin);
	int n;
   	cin>>n;
   	pers_stack st(n+1);
    for(int i=1;i<=n;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	if(y==0)
    	{
    		st.erase(x);
    	}
    	else
    	{
    		st.add(x,y);
    	}
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
    	ans+=st[i];
    }
    cout<<ans;
    return 0;
}