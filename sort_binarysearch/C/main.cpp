#include<bits/stdc++.h>

using namespace std;

int S (int* a, int n, int k)
{
	int l=1,r=n;
	while(1)
	{
		if(r<=l+1)
		{
			if(r==l+1 && a[r]<a[l])
			{
				swap(a[l], a[r]);
			}
			return a[k];
		}
		int m=(l+r)/2;
		swap(a[m], a[l+1]);
		if(a[l]>a[l+1])
		{
			swap(a[l], a[l+1]);
		}
		if(a[l+1]>a[r])
		{
			swap(a[l+1], a[r]);
		}
		if(a[l]>a[l+1])
		{
			swap(a[l], a[l+1]);
		}
		int	i=l+1, j=r;
		int	mid=a[l+1];
		while(1)
		{
			while(a[++i]<mid);
			while(a[--j]>mid);
			if(i>j)
			{		
				break;
		    }
			swap(a[i], a[j]);
		}
		a[l+1]=a[j];
		a[j]=mid;
		if(j>=k)
		{
			r=j-1;
		}
		if(j<=k)
		{
			l=i;
		}
	}
}

int a[3*10000001];
	
int main()
{
	//freopen("kth.in","r",stdin);
	//freopen("kth.out","w",stdout);
	ifstream in("kth.in");
	ofstream out("kth.out");
	int n,m;
	in>>n;
	in>>m;
	int ba,bb,bc,ba1,ba2;
	in>>ba>>bb>>bc>>ba1>>ba2;
	a[1]=ba1;
	a[2]=ba2;
	for(int i=3;i<=n;i++)
	{
		a[i]=ba*a[i-2]+bb*a[i-1]+bc;
	}	
	/*for(int i=1;i<=n;i++)
	{
		out<<a[i]<<' ';
	}
	out<<endl;   */
	out<<S(a,n,m);
	return 0;
}