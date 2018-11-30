#include<bits/stdc++.h>

using namespace std;

unsigned int b[1000003];

long long ans=0;

void merge_sort(unsigned int* a,unsigned int size)
{
	if(size==1)
	{
		return;
	}
	else
	{
		unsigned int m=size/2;
		merge_sort(a,m);
		merge_sort(a+m,size-m);
		unsigned int l=0,r=m;
		for(unsigned int i=0;i<size;i++)
		{
			if(l==m)
			{
				b[i]=a[r];
				r++;
				continue;	
			}
			if(r==size)
			{
				b[i]=a[l];
				l++;
				continue;	
			}
			if(a[l]<=a[r])
			{
				b[i]=a[l];
				l++;	
			}
			else
			{
				ans=ans+(m-l)*1ll;
				b[i]=a[r];
				r++;
			}
		}
		for(unsigned int i=0;i<size;i++)
		{
			a[i]=b[i];
		}
		return;
	}
}
unsigned int cur=0;
unsigned int q,w;
unsigned int nextRand()
{
	cur = cur * q + w;
	return cur>>8;
}

unsigned int x[1000005];

int main()
{
	freopen("invcnt.in","r",stdin);
	freopen("invcnt.out","w",stdout);
	ios::sync_with_stdio(false);
	unsigned int n,m;      
	cin>>n>>m;    	
	cin>>q>>w;
	for(unsigned int i=0;i<n;i++)
	{
		x[i]=nextRand()%m;
	}	
	merge_sort(x,n);
	cout<<ans;
	return 0;
}                                                 