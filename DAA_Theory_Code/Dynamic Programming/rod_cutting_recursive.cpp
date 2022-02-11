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
int cut_rod(vector<int> p, int length)
{    
    int i;
    int q=INT_MIN;
    if(length==0)
        return 0;
    for(i=1;i<=length;i++)
    {
        q = maximum(q,p[i-1]+cut_rod(p,length-i));
    }
    return q;
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
    max_profit = cut_rod(p,n);
    cout<<max_profit;
}