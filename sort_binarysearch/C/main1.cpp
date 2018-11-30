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
				swap(a[l], a[r]);
			return a[k];
		}
		int mid=(l+r)/2;
		swap (a[mid], a[l+1]);
		if (a[l]>a[r])
			swap(a[l], a[r]);
		if (a[l+1]>a[r])
			swap(a[l+1], a[r]);
		if (a[l]>a[l+1])
			swap(a[l], a[l+1]);
		int	i=l+1, j=r;
		int	cur=a[l+1];
		while(1)
		{
			while(a[++i]<cur);
			while(a[--j]>cur);
			if(i>j)
				break;
			swap(a[i], a[j]);
		}
		a[l+1]=a[j];
		a[j]=cur;
		if (j>=k)
			r=j-1;
		if (j<=k)
			l=i;

	}
}

int a[3*10000001];
	
int main()
{
	freopen("kth.in","r",stdin);
	freopen("kth.out","w",stdout);
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	/*for(int i=1;i<=n;i++)
	{
		out<<a[i]<<' ';
	}
	out<<endl;   */
	cout<<S(a,n,m);
	return 0;
}                 	