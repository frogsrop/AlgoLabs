//��� ��� ������� �����

#include<iostream>
#include<cstdio>
#include<fstream>

#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>

#include<algorithm>
#include<cmath>



#define ll long long 
#define pb push_back
#define f first
#define s second
#define all(c) c.begin(),c.end()
#define len(s) s.size()



using namespace std;

    int A[1001][10005];
	int k,w[10005],p[1000],W;
	vector<int> v;
		void Print(int s, int n)
		{
  			if (A[s][n]==0) // ������������ ������ ��� ���������� (s,n)
   	 			return;        // ����� ������� ��������, 
                   				// ������� ������ �� �������
  			else 
  				if (A[s-1][n] == A[s][n]) 
    					Print(s-1,n);  // ����� ��������� ������ ��� �������� s
  				else
  				{                               
    					Print(s-1,n-w[s]); // ������� s ������ ����������� 
    					v.pb(s);     // ����� � ������
 	 			}
		}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
    
	cin>>k>>W;
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>p[i];
	}
	for(int s=1;s<=k;++s)       // s - ������������ ����� ��������, 
	{                           // ������� ����� ������������
    		for(int n=0;n<=W;++n)   // n - ����������� �������
    		{
        		A[s][n]=A[s-1][n]; 
        		if ( n>=w[s] && ( A[s-1][n-w[s]]+p[s] > A[s][n]) )
        		{
        	    	A[s][n] = A[s-1][n-w[s]]+p[s];
        	    }
    		}
	}
	Print(k,W);
	cout<<v.size()<<endl;
	for(auto &t:v)
	{
		cout<<t<<' ';
	}
	return 0;
}
                                       