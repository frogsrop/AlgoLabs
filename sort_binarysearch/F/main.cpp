#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("antiqs.in","r",stdin);
	freopen("antiqs.out","w",stdout);
	int n,a[70003];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;		
	}
    for(int i=0;i<n;i++)
	{
		swap(a[i], a[i/2]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}