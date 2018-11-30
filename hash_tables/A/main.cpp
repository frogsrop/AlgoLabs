#include<bits/stdc++.h>
 
using namespace std;
 
class ver 
{
    public:
        long long val;
        ver *l, *r;
         
        ver()
        {
            val = 0;
            l = nullptr;
            r = nullptr;
        }
};
 
class tree {
    private:
        ver* v = nullptr;
        ver*& find(long long x)
        {
            ver* cur = v;
            if(v == nullptr || v -> val == x)
            {
                return v;
            }
            else
            {
                while(1)
                {
                    if(cur->val >= x) 
                    {
                        if(cur -> l == nullptr || cur -> l -> val == x)
                        {
                            return cur -> l;
                        }   
                        cur = cur->l;
                    }
                    if(cur->val < x)  
                    {
                        if(cur -> r == nullptr || cur -> r -> val == x)
                        {
                            return cur -> r;
                        }   
                        cur = cur->r;
                    }
             
                }
            }
        }
         
    public:
        long long next(long long x)
        {  
            long long n;
            ver* cur = v;
            while(cur != nullptr && cur->val <= x)
                cur = cur->r;
            if(cur == nullptr)
                return x;
            n = cur->val;
            while(cur!=nullptr)
            {
                if(cur -> val > x)
                {
                    if(cur -> l != nullptr)
                    {
                        if(cur -> l ->val > x && cur -> l ->val < n)
                        {
                            n=cur->l->val;
                        }
                    }   
                    cur = cur->l;
                }
                else            
                if(cur -> val <= x)
                {
                    if(cur -> r != nullptr)
                    {
                        if(cur -> r -> val > x && cur -> r -> val < n)
                        {
                            n = cur->r->val;
                        }
                    }   
                    cur = cur->r;
                }
            }
            return n;
        }
        long long prev(long long x)
        {  
            long long n;
            ver* cur = v;
            while(cur != nullptr && cur->val >= x)
                cur = cur->l;
            if(cur == nullptr)
                return x;
            n = cur->val;
            while(cur!=nullptr)
            {                   
                if(cur -> val < x)
                {
                    if(cur -> r != nullptr)
                    {
                        if(cur -> r -> val < x && cur -> r ->val > n)
                        {
                            n=cur->r->val;
                        }
                    }   
                    cur = cur->r;
                }
                else            
                if(cur -> val >= x)
                {
                    if(cur -> l != nullptr)
                    {
                        if(cur -> l -> val < x && cur -> l -> val > n)
                        {
                            n = cur->l->val;
                        }
                    }   
                    cur = cur->l;
                }
            }
            return n;
        }
        void push(long long x)
        {
            ver*& z = find(x);
            if(z == nullptr)
            {
                z = new ver();
                z -> val = x;
            }
        }
        void erase(long long x)
        {
            ver*& z = find(x);
            if(z != nullptr)
            {
                if(z->l == nullptr && z->r ==nullptr)
                {
                    z = nullptr;
                    return;
                }
                if(z->l == nullptr)
                {
                    z = z->r;
                    return; 
                }
                if(z->r == nullptr)
                {
                    z = z->l;
                    return;
                }
                long long u = next(x);
                if(u != x)
                {
                    swap(find(u)->val, z->val);
                    erase(x);
                }
                else
                {
                    return;
                }
            }           
        }
        bool exists(long long x){
            if(find(x)==nullptr)
                return 0;
            else return 1;
        }
};
 
tree v[1000000];
            
 
int main()
{
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    ios_base::sync_with_stdio(false);
    string s;
    while(cin >>s)
    {
        if(s == "insert")   
        {
            int val;
            int hash;
            cin>>val;
            hash = abs(val) % 1000000;
            v[hash].push(val);
        }   
        if(s == "exists")
        {
            int val;
            int hash;
            cin>>val;
            hash = abs(val) % 1000000;
            cout<<(v[hash].exists(val)?"true\n":"false\n");
        }
        if(s == "delete")   
        {
            int val;
            int hash;
            cin>>val;
            hash = abs(val) % 1000000;
            v[hash].erase(val);
        }   
         
    }
    return 0;
}