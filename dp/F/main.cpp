#include<bits/stdc++.h>
using namespace std;
	const int maxl = 10005;
	int i,j,l1,l2;
	string s1,s2,s3;
	bool used1[maxl], used2[maxl];

int main()
{
	ios_base::sync_with_stdio(false);
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
    cin>>s1;
  	cin>>s2;
  	l1=s1.size(); 
  	l2=s2.size();
  	for(j=0;j<=l2;j++)
		used2[j]=0;
	used2[0] = 1;
	for(i=1;i<=l1;i++)
  	{ 
		used1[0] = (used2[0] && ( s1[i-1] == '*' ));
		for(j=1;j<=l2;j++)
		{    
			if (s1[i-1] == '?')
				used1[j] = used2[j-1];
          	else
         	if (s1[i-1] == '*') 
         	{ 
         		used1[j] = (used2[j] || used2[j-1] || used1[j-1]);
         	}
          	else
            	used1[j] = (used2[j-1] && (s2[j-1] == s1[i-1]));
       	}
       	for(int x=0;x<=l2;x++)
    		used2[x] = used1[x];
    }
 	if (used2[l2])
 		cout<<"YES";
 	else 
 		cout<<"NO";
	return 0;
}