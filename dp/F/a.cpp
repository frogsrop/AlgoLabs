#include<iostream>
#include<string>
using namespace std;

const int N = 11111;
	
bool ch1[N], ch2[N];
int i, j, l1, l2;
string s1, s2, s3;

void question() {
	ch1[j] = ch2[j-1];
}

void star(){
	if (ch2[j] || ch2[j-1] || ch1[j-1])
		ch1[j] = 1;
	else
		ch1[j] = 0;
}

int main(){
    cin>>s1;
  	cin>>s2;
  	l1 = s1.size(); 
  	l2 = s2.size();
  	for(j = 1; j <= l2; j++)
		ch2[j] = 0;
	ch2[0] = 1;
	for(i = 1;i <= l1; i++){ 
		ch1[0] = (ch2[0] && ( s1[i - 1] == '*' ));
		for(j = 1; j <= l2; j++){    
          	switch (s1[i - 1]){
          		case '*':
          			star();
          			break;
          		case '?':
          			question();
          			break;
          		default:
          			ch1[j] = (ch2[j - 1] && (s2[j - 1] == s1[i - 1]));
          			break;
          	}
            	
       	}
       	for(int k = 0; k <= l2; k++)
    		ch2[k] = ch1[k];
    }
 	cout<<(ch2[l2] ? "YES" : "NO");
	return 0;
}