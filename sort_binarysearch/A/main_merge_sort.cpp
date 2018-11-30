#include<bits/stdc++.h>
 
using namespace std;
 
void merge_sort(int* a,int size)
{
    if(size==1)
    {
        return;
    }
    else
    {
        int m=size/2;
        merge_sort(a,m);
        merge_sort(a+m,size-m);
        int l=0,r=m;
        int* b;
        b=new int[300005];
        for(int i=0;i<size;i++)
        {
            if(l==m)
            {
                b[i]=a[r];
                r++;
                continue;   
            }
            if(r==size)
            {
                b[i]=a[l];
                l++;
                continue;   
            }
            if(a[l]<=a[r])
            {
                b[i]=a[l];
                l++;    
            }
            else
            {
                if(a[l]>a[r])
                {
                    b[i]=a[r];
                    r++;
                }
            }
        }
        for(int i=0;i<size;i++)
        {
            a[i]=b[i];
        }
        free(b);
        return;
    }
}
 
int main()
{
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    ios::sync_with_stdio(false);
    int n;
    int x[300005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    merge_sort(x,n);
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<' ';
    }
    return 0;
}