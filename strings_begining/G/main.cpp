#include<bits/stdc++.h>
 
using namespace std;

const int MAX = 1000;
const int K = 30;
struct vertex 
{
    int next[K];
    bool leaf;
    int p;
    char pch;
    int link;
    int go[K];
};
  
vertex t[MAX+1];
int sz;
  
void init() {
    t[0].p = t[0].link = -1;
    memset (t[0].next, 255, sizeof t[0].next);
    memset (t[0].go, 255, sizeof t[0].go);
    sz = 1;
}
  
void add_string (const string & s) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        char c = char((int)s[i] - (int)'a');
        if (t[v].next[(int)c] == -1) {
            memset (t[sz].next, 255, sizeof t[sz].next);
            memset (t[sz].go, 255, sizeof t[sz].go);
            t[sz].link = -1;
            t[sz].p = v;
            t[sz].pch = c;
            t[v].next[(int)c] = sz++;
        }
        v = t[v].next[(int)c];
    }
    t[v].leaf = true;
}
  
int go (int v, char c);
  
int get_link (int v) {
    if (t[v].link == -1)
    {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go (get_link (t[v].p), t[v].pch);
    }
    return t[v].link;
}
  
int go (int v, char c) {
    if (t[v].go[(int)c] == -1)
    {
        if (t[v].next[(int)c] != -1)
            t[v].go[(int)c] = t[v].next[(int)c];
        else
            t[v].go[(int)c] = v==0 ? 0 : go (get_link (v), c);
    }
    return t[v].go[(int)c];
}
 
int main()
{
    init();
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
    	string s;
    	cin >> s;
		add_string(s)
	} 
    return 0;
}