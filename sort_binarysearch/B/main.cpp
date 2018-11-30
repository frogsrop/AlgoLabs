#include<bits/stdc++.h>

using namespace std;

int bs(int* a,int l,int r,int val,int mode)
{
	if(mode==0)
	{
		r++;
	}
	else
	{
		l--;
	}	
	while(l+1<r)
	{
		int m=(l+r)/2;
		if((mode==0?a[m]<=val:a[m]<val))
		{
			l=m;
		}
		else
		{
			r=m;
		}
	}
	if(mode==0)
	{
		if(a[l]==val)
			return l;
		else
			return -2;
	}
	else
	{
		if(a[r]==val)
			return r;
		else
			return -2;
	}
}

int main()
{
	freopen("binsearch.in","r",stdin);
    freopen("binsearch.out","w",stdout);
    int n;
    int a[100005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {   
    	int x;
    	cin>>x;
    	cout<<bs(a,0,n-1,x,1)+1<<' '<<bs(a,0,n-1,x,0)+1<<endl;
    }
	return 0;    
}