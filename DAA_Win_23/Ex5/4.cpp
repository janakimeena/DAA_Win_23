#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
int maximum(int a, int b)
{    
    if(a>b)
        return a;
    return b;
}
int bottom_up_cut_rod(vector<int> &p, int length)
{    
    vector<int> r(100,0);
    int i,q,j;
    r[0] = 0;
    for (j=1;j<=length;j++)
    {
        q = INT_MIN;
        for(i=1;i<=j;i++)
        {
            q = maximum(q,p[i-1]+r[j-i]);
        }
        r[j] = q;
    }
    return r[length];
}

int main()
{
    vector<int> p;
    int i,n,price,max_profit;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>price;
        p.push_back(price);
    }
    max_profit = bottom_up_cut_rod(p,n);
    cout<<max_profit;
}


