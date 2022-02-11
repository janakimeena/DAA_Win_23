#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
int memoized_cut_rod_aux(vector<int> &p, int length,vector<int> &r);
int maximum(int a, int b)
{
    
    if(a>b)
        return a;
    return b;
}
int memoized_cut_rod(vector<int> &p, int length)
{    
    vector<int> r(100,0);
    int i;
    for(i=0;i<100;i++)
        r[i] = INT_MIN;
    return memoized_cut_rod_aux(p,length,r);    
}
int memoized_cut_rod_aux(vector<int> &p, int length,vector<int> &r)
{
    int q;
    if(r[length-1]>=0)
        return(r[length-1]);
    if(length==0)
        return 0;
    q = INT_MIN;
    for(int i=1;i<=length;i++)
        q = maximum(q,p[i-1]+memoized_cut_rod_aux(p,length-i,r));
    r[length-1] = q;
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
    max_profit = memoized_cut_rod(p,n);
    cout<<max_profit;
}