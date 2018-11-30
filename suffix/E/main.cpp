#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;

struct suff_arr
{
	string s;
	int len;
		
	vector<int> suff_arr_data;
	vector<int> lcp;

	suff_arr(const string& s)
	{
		this->s = s;
		this->s+="$";
		len = (int)s.size() + 1;	
		lcp.resize(len);
		suff_arr_data.resize(len);
		get_suff_arr();
		get_lcp();	
	}

	void calc(vector<int>& temp) 
	{
		int sum = 0;
		for(int i = 0; i < MAXN; i++) 
		{
			sum += temp[i];
			temp[i] = sum - temp[i];
		}          
	}
	
	void get_suff_arr() 
	{
		vector<int> dop;
		dop.resize(len);
	
		vector<int> color;
		color.resize(len);
	
		vector<int> temp;
		temp.resize(MAXN);
	
		for(auto i : s) 
		{
			temp[i]++;
		}

		calc(temp);
	
		for(int i = 0; i < len; i++) 
		{
			suff_arr_data[temp[s[i]]++] = i;
		}
	
		int cn = 0;
		
		char lchar = '$';			
		
		for(auto i : suff_arr_data) 
		{
			if (s[i] != lchar) 
			{
				lchar = s[i];
				cn++;
			}
			color[i] = cn;
		}
		for(int l = 1; l < len; l *= 2) 
		{
			for(int i = 0; i < len; i++) 
			{
				temp[i] = 0;
			}
			for (int i = 0; i < len; i++) 
			{
				temp[color[i]]++;
			}
			calc(temp);
			for (auto i : suff_arr_data) 
			{
				int d = (i - l + len) % len;
				dop[temp[color[d]]++] = d;
			}
			suff_arr_data = dop;
			dop[suff_arr_data[0]] = 0;
	   	
			for (int i = 1; i < len; i++) {
        	    dop[suff_arr_data[i]] = dop[suff_arr_data[i - 1]];
        	    if(color[suff_arr_data[i]] != color[suff_arr_data[i - 1]] || color[(suff_arr_data[i] + l) % len] != color[(suff_arr_data[i - 1] + l) % len])
        	    {
					dop[suff_arr_data[i]]++;        	    
        	    }
        	}
        	
        	cn = dop[suff_arr_data[len - 1]] + 1;
			color = dop;
		}
	}

	void get_lcp() 
	{
		vector<int> anti_suff;
		anti_suff.resize(len);
	   	
		for(int i = 0; i < len; i++) 
		{
			anti_suff[suff_arr_data[i]] = i;
		}
		int k = 0;
		for(int i = 0; i < len; i++) 
		{
			if(k > 0) 
			{
				k--;
			}
			if(anti_suff[i] == len - 1) 
				{
				lcp[len - 1] = -1;
				k = 0;
			} 
			else 
			{
				int j = suff_arr_data[anti_suff[i] + 1];
				while(i + k < len && j + k < len && s[i + k] == s[j + k]) 
				{
					k++;
				}
				lcp[anti_suff[i]] = k;
			}
		}          
	}
};               

int main ()
{
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);

	string s;
	
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		s += char(x + 'a' - 1);
	}
	
	//cout << s;
	
	suff_arr my(s);      
	
	int from = 0;
	int to = (int) s.size();
    
	int amount = 1;
    
    stack<pair<int, int>> st;
    
    st.push(make_pair(-1, -1));
    
    my.lcp[s.size()] = 0;

    for(int i = 0; i <= (int)s.size(); i++) 
    {
		while(st.size()) 
		{
			pair<int, int> x = st.top();
			if(x.first < my.lcp[i]) 
			{
				break;
			}
			st.pop();
			
			int cur_from = my.suff_arr_data[i];
			int cur_to = cur_from + x.first;
			
			int cur_amount = i - st.top().second;
			
			if(1ll * (to - from) * amount <= 1ll * (cur_to - cur_from) * cur_amount) 
			{
			    from = cur_from;
				to = cur_to;
			
				amount = cur_amount;
			}
		} 
        st.push(make_pair(my.lcp[i], i));
    }
         
    cout << 1ll * (to - from) * amount << endl;
    cout << to - from << endl;		
	
    for(int i = from; i < to; i++) 
    {
		cout << s[i] - 'a' + 1 << ' ';
	}
	return 0;
}