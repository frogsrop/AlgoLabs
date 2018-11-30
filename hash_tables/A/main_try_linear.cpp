#include<bits/stdc++.h>
  
using namespace std;
  
class mySet { 
    public:
    vector<int> st;
    int size;
    const unsigned int q = 3;
    mySet(){
        st.resize(10,0);
    }
    bool get(int s)
    {
        int hash = abs(s)%st.size();
        int i = hash;
        if(st[i] != s && st[i]!=0)
        {
        	i = (i+q) % st.size();
        	while(i!=hash && st[i] != s && st[i]!=0)
        	{
        	    i = (i+q) % st.size();
        	}
        }
        if(st[i] == s)
            return 1;
        else
            return 0;
    }
                            
    void push(int s)
    {
        if(get(s))
            return;
        size++;
        pushing(s);
    }

    void pushing(int s)
    {
        bool flag = 1;
       	vector<int> temp;
       	if((size*100)/st.size()>=70)
        	temp.resize(st.size()*2,0);
       	else
       		temp.resize(st.size(), 0);
       	st.push_back(s);
       	while(flag)
       	{
			int pos;
			int x;
			flag = 0;
			for(int i=0;i<(int)st.size();i++)
        	{	
        		if(st[i]==0)
        			continue;
        		x = abs(st[i]) % temp.size();
         	  	pos = x;
				if(temp[x]!=0)
				{
					pos = (pos + q) % temp.size(); 
					while(pos!=x && temp[pos]!=0)
            		{
                		pos=(pos+q)%temp.size();
            		}
            	}
            	if(temp[pos]==0)
                	temp[pos]=st[i];
                else
                {
                	flag = 1;
                	break;
                }
        	}
        	if(flag)
        	{
        		temp.assign(temp.size()*2, 0);
        	}
       	}
        st.resize(temp.size());
        for(int i = 0;i<(int)st.size();i++)
            st[i] = temp[i];
    }
    void dlt(int s)
    {
        if(!get(s))
            return;
        size++;
        int pos = abs(s)%st.size();
        while(st[pos]!=s)
        {
            pos = (pos + q) % st.size();
        }               
        st[pos] = 0;
        bool flag = 1;
       	vector<int> temp;
        temp.resize(st.size(), 0);
       	while(flag)
       	{
			int pos;
			int x;
			flag = 0;
			for(int i=0;i<(int)st.size();i++)
        	{	
        		if(st[i]==0)
        			continue;
        		x = abs(st[i]) % temp.size();
         	  	pos = x;
				if(temp[x]!=0)
				{
					pos = (pos + q) % temp.size(); 
					while(pos!=x && temp[pos]!=0)
            		{
                		pos=(pos+q)%temp.size();
            		}
            	}
            	if(temp[pos]==0)
                	temp[pos]=st[i];
                else
                {
                	flag = 1;
                	break;
                }
        	}
        	if(flag)
        	{
        		temp.assign((temp.size()*3)/2, 0);
        	}
       	}
        st.resize(temp.size());
        for(int i = 0;i<(int)st.size();i++)
            st[i] = temp[i];        
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
            if(val>=0)
            	val++;
            r.push(val);
            /*cout<<"insert "<<val<<' ';
            for(int i =0 ;i<r.st.size();i++)
            	cout<<r.st[i]<<' ';
            cout<<endl;*/
        }   
        if(s == "exists")
        {
            int val;
            cin>>val;
            if(val>=0)
            	val++;
            if(r.get(val) == 1)
                cout<<"true\n";
            else
                cout<<"false\n";
            /*for(int i =0 ;i<r.st.size();i++)
            	cout<<r.st[i]<<' ';
            cout<<endl;  */
        
        }
        if(s == "delete")   
        {
            int val;
            cin>>val;
            if(val>=0)
            	val++;
            r.dlt(val);
            /*cout<<"delete "<<val-1<<' ';
            for(int i =0 ;i<r.st.size();i++)
            	cout<<r.st[i]<<' ';
            cout<<endl;*/
        
        }   
          
    }
    return 0;
}