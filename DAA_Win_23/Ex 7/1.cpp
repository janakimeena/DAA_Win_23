// Recursive routine
#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
int lcs_length(string x, string y, int x_index,int y_index)
{
    
    int m,n,i,j,l1,l2;
    m = x.length();
    n = y.length();
    if((x_index>=m)||(y_index>=n))
        return 0;
    if(x[x_index]==y[y_index])
    {        
        return lcs_length(x,y,x_index+1,y_index+1)+1;
    }
    else
    {
        l1 = lcs_length(x,y,x_index,y_index+1);
        l2 = lcs_length(x,y,x_index+1,y_index);
        return l1>l2? l1: l2;

    }
}
int main()
{
    string x,y;
    int i,j;
    cin>>x>>y;    
    cout<<lcs_length(x,y,0,0);    
}
