#include<bits/stdc++.h>
 
using namespace std;
 
bool a[1005][1005];
int b[1005][1005],c[1005][1005];
int red[1005][10];
int qx[1000005],qy[1000005],s[1000005];
int f, r, n, u, v, k, i, j;
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<10;j++)
		{
			red[i][j]=(i*10+j)%n;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
		a[i][j] = 0;
 
		}
	}
	a[0][0] = 1;
	qx[0] = 0;
	qy[0] = 0;
	f = 0;
	r = 1;
 	
 	while(f<r)
	{ 
 		i = qx[f];
 		j = qy[f];
		f++;
 		if (i == 0 && j == n)
 		{
 			i = 0;
 			j = n;
 			k = 0;
 			while (j > 0)
 			{
 				u = b[i][j];
 				v = c[i][j];
 					s[k] = j - v;
 				k++;
 				i = u;
 				j = v;
 			} 
 			for(i=k-1;i>=0;i--){
 				cout<<s[i];               
 			}
 			return 0;
 		}  	
 		for(k=0;k<10;k++)
 		{ 
 			u = red[i][k];
 			v = j + k;
 			if (v > n) 
 				break;
 			if(!a[u][v])
 			{
 				a[u][v] = true;
 				b[u][v] = i;
 				c[u][v] = j;
 				qx[r] = u;
 				qy[r] = v;
 				r++;
 			}
 		}
	}
}