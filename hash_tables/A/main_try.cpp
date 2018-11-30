#include<bits/stdc++.h>
  
using namespace std;
  
class mySet { 
    public:
    static const unsigned int SZ = 1000000; 
    list<int> st[SZ];
    int size = 0;
    bool get(int s)
    {
        int hash = abs(s) % SZ;
        for(auto i = st[hash].begin(); i != st[hash].end();i++)
        {
            if((*i)==s)
                return 1;
        }
        return 0;
    }      
    void push(int s)
    {
        if(get(s))
            return;
        size++;
        int hash = abs(s) % SZ;
        st[hash].push_back(s);  
    }               
    void dlt(int s)
    {
        if(!get(s))
            return;
        size--;
        int hash = abs(s) % SZ;
        for(auto i = st[hash].begin(); i != st[hash].end();i++)
        {
            if((*i)==s)
            {
                st[hash].erase(i);
                return;
            }
        }
    }         
};               
             
  
int main()
{
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    ios_base::sync_with_stdio(false);
    mySet r;
    string s;
    while(cin >>s)
    {
        if(s == "insert")   
        {
            int val;
            cin>>val;
            r.push(val);
        }   
        if(s == "exists")
        {
            int val;
            cin>>val;
            if(r.get(val) == 1)
                cout<<"true\n";
            else
                cout<<"false\n";
        }
        if(s == "delete")   
        {
            int val;
            cin>>val;
            r.dlt(val);
        }   
          
    }
    return 0;
}