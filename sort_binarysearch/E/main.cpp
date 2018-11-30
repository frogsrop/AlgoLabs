#include<bits/stdc++.h>

using namespace std;

vector<int> b[1003];
void merge_sort(vector<int>* a,int size,int step)
{
	if(size==1)
	{
		return;
	}
	else
	{
		int m=size/2;
		merge_sort(a,m,step);
		merge_sort(a+m,size-m,step);
		int l=0,r=m;
		for(int i=0;i<size;i++)
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
			if(a[l][step]<=a[r][step])
			{
				b[i]=a[l];
				l++;	
			}
			else
			{
				if(a[l][step]>a[r][step])
				{
					b[i]=a[r];
					r++;
				}
			}
		}
		for(int i=0;i<size;i++)
		{
			a[i]=b[i];
		}
		return;
	}
}

int main()
{
	freopen("radixsort.in","r",stdin);
	freopen("radixsort.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> x[1005];
	for(int i=0;i<n;i++)
	{
		char buf;
		scanf("%c",&buf);
		for(int j=0;j<m;j++)
		{              			
			scanf("%c",&buf);
			x[i].push_back(buf-'a');
			b[i].push_back(buf-'a');
		}
	}
	for(int i=0;i<k;i++)
	{
		merge_sort(x,n,m-i-1);
	}
	for(int i=0;i<n;i++)
	{
		
		for(auto &t:v)
		{}
		for(auto &t:x[i])
		{          
			printf("%c",char(t+'a'));
		}
		printf("\n");
	}
	return 0;
}                                                 