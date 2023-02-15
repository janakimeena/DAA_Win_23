#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
void matrix_chain_order(vector<int> p, vector<vector<int> >& m, vector<vector<int> >& s)
{
    cout<<"entered"<<endl;
    int n,l,i,j,k,q;
    n = p.size()-1;
    // try length of chain from 2 to n
    for(l=2;l<=n;l++)
    {
        // From where does the chain starts is in 'i'
        //cout<<"l is "<<l<<endl;
        for(i=1;i<=n-l+1;i++)
        {
            // till what position does the chain goes is in 'j'
            j = i+l-1;
            //cout<<"i is "<<i<<" j is "<<j;
            m[i-1][j-1] = INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                //cout<< " k is "<<k<<endl;
                q = m[i-1][k-1] + m[k][j-1] + p[i-1]*p[k]*p[j];
                if(q<m[i-1][j-1])
                {
                    m[i-1][j-1] = q;
                    s[i-1][j-1] = k;
                }
            }
        }
    }
}
void print_Optimal_Parens(vector<vector<int> >& s, int i, int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        print_Optimal_Parens(s,i,s[i-1][j-1]);
        print_Optimal_Parens(s,s[i-1][j-1]+1,j);
        cout<<")";
    }
}
int main()
{    
    int n,i,j;
    cin>>n;
    vector<int> p(n);
    for(i=0;i<n;i++)
        cin>>p[i];
    vector<vector<int> > m(n-1,vector<int>(n-1,0));
    vector<vector<int> > s(n-1,vector<int>(n-1,0));
    matrix_chain_order(p,m,s);
    cout<<"m table is "<<endl;
    for(i=0;i<n-2;i++)
    {
        for(j=1;j<n-1;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    cout<<"s table is "<<endl;
    for(i=0;i<n-2;i++)
    {
        for(j=0;j<n-1;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<"Minimum cost is "<<m[0][n-2]<<endl;
    print_Optimal_Parens(s,1,n-1);
}



