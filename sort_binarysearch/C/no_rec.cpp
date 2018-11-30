#include<bits/stdc++.h>

using namespace std;

	
int a[3*10000000];
	
int main()
{
	freopen("kth.in","r",stdin);
	//freopen("kth.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ba,bb,bc,ba1,ba2;
	cin>>ba>>bb>>bc>>ba1>>ba2;
	a[0]=ba1;
	a[1]=ba2;
	for(int i=2;i<n;i++)
	{
		a[i]=ba*a[i-2]+bb*a[i-1]+bc;
	}	
	/*for(int i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}*/
	int ll=0,rr=n,k=m-1;
	t:
	if(ll<rr)
	{
		int l=ll;
		int r=rr-1;
		int mid=a[(l+r)/2];
		while(l<=r)
		{
			while(a[l]<mid)l++;
			while(a[r]>mid)r--;
			if(l<=r)
			{
				swap(a[l],a[r]);
				l++;
				r--;
			}
		}/*
		cout<<"mid "<<mid<<" ind "<<l<<endl;
		for(int i=0;i<5;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;
		*/
		if(l==k)
		{     
			cout<<a[l];
		}
		else
		{
			if(l<k)
			{
				ll=l+1;
			}
			else
			{
				rr=l+1;
			}
			goto t;
		}
	}
	return 0;
}