#include<bits/stdc++.h>

using namespace std;

int p[100],m[100][100],s[100][100];

int get(int i,int j)
{
	int k,res;
	if(m[i][j]!=-1) 
	{		
		return m[i][j];
	}
	res=get(i+1, j) + p[i-1]*p[i]*p[j]; 	
	s[i][j]=i;
	for(int k=i+1;i<=j-1;i++)
	{
		if(res>get(i, k) + get(k+1, j) + p[i-1]*p[k]*p[j]) 
		{	res= get(i, k) + get(k+1, j) + p[i-1]*p[k]*p[j];
			s[i][j]=k;   
		}
	}
	m[i][j]=res;
	return res;
}
void out(int i,int  j)
{	
	if (i==j) 
		cout<<'A'<<i;
	else
	{
		cout<<'(';
		out(i, s[i][j]);
		cout<<'*';
		out(s[i][j]+1, j);
		cout<<')';
	}
}
int main()
{
	
}

