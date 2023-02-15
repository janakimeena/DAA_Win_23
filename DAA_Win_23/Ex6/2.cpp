// Recursive matrix multiplication
#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
int matrix_chain_mul(int i, int j, vector<int> &p)
{
    int min_cost = INT_MAX,k,left_cost,right_cost,total_cost;    
    if(i==j)
        return 0;
    for(k=i;k<j;k++)
    {       
        left_cost = matrix_chain_mul(i,k,p);
        right_cost = matrix_chain_mul(k+1,j,p);
        total_cost = left_cost + right_cost + p[i-1] * p[k] * p[j];
        if(total_cost<min_cost)
        {
            min_cost = total_cost;
            
        }
    }
    return min_cost;
}
int main()
{
    int n,ele,i;
    vector<int> p;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        p.push_back(ele);
    }
    cout<<matrix_chain_mul(1,n-1,p);
}



