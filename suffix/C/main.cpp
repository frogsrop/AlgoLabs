#include<bits/stdc++.h>
 
using namespace std;
 
struct suff_tree
{
    const static int size = 100000;
    int sz;
    int pos[size], len[size], par[size];
    map<char, int> to[size];
    map<char, int> link[size];
    string s;
    int path[size];
 
    suff_tree(const string& s)
    {
        len[1] = 1; pos[1] = 0; par[1] = 0;
        for (int c = 0; c < 256; c++)
            link[0][char(c)] = 1;
        this->s = s;
        sz = 2;
        build();
    }
                                 
    void attach(int child, int parent, char c, int child_len)
    {
        //cout<<"child = " << child << " parent = " << parent <<" char = " << c << endl; 
        to[parent][c] = child;
        len[child] = child_len;
        par[child] = parent;
    }
     
    void extend(int i) 
    {
        int v, vlen = (int)s.size() - i, old = sz - 1, pstk = 0; 
        for (v = old; !link[v].count(s[i]); v = par[v]) {
            vlen -= len[v];
            path[pstk++] = v;
        }
        int w = link[v][s[i]]; 
        if (to[w].count(s[i + vlen])) {
            int u = to[w][s[i + vlen]]; 
            for (pos[sz] = pos[u] - len[u]; s[pos[sz]] == s[i + vlen]; pos[sz] += len[v]) {
                v = path[--pstk];
                vlen += len[v];
            }
            attach(sz, w, s[pos[u] - len[u]], len[u] - (pos[u] - pos[sz]));
            attach(u, sz, s[pos[sz]], pos[u] - pos[sz]);
            w = link[v][s[i]] = sz++;
        }
        link[old][s[i]] = sz;
        attach(sz, w, s[i + vlen], (int)s.size() - (i + vlen));
        pos[sz++] = (int)s.size() ;  
    }
 
    void build()
    {
        for(int i = (int)s.size() - 1; i >= 0; i--)
        {
            extend(i);
        }
    }
     
    void dfs(int num)
    {
        for(int i = 0;i<256;i++)
        {
            if(to[num].count(char(i)))
            {                 
                cout<<num<<' ';             
                cout<<to[num][char(i)]<<' ';
                cout<<pos[to[num][char(i)]]-len[to[num][char(i)]] + 1<<' '<<pos[to[num][char(i)]] - 1 + 1;
                cout<<endl;
                dfs(to[num][(char)i]);
            }
        }          
    } 
};
suff_tree* my; 
int main()
{   
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
 
    string s;
    cin>>s;
    my = new suff_tree(s + '$');
    cout << my->sz - 1 << ' ' << my->sz - 2 << endl;
    my->dfs(1);
      
    return 0;
}