#include<bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin>>k;
	for(int i=0;i<k;i++) {       	
		string s;
		int x = i;
	    for(int j = 0;j<10;j++) {
	    	s+=(x%2?"Aa":"BB");
	    	x>>=1; 	
	    }
	    cout<<s<<endl;
	}
}