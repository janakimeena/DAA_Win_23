#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>
long double fact(int n)
{
    static vector<long double> factorial(5000,0);
    long double res;
    if(n==1)
        return 1;
    if(factorial[n-1]!=0)
    {
        cout<<"Returing by refering table"<<n<<endl;
        return factorial[n-1];
    }
    res = (fact(n-1)*n);
    factorial[n-1] = res;
    return res;
}
int main()
{
    int n,r;
    long double n_fact,r_fact,n_minus_r_fact,ncr;
    cout<<"Enter value of n and r";
    cin>>n>>r;
    n_fact = fact(n);
    cout<<"N fact is "<<n_fact<<endl;
    r_fact = fact(r);
    cout<<"r fact is "<<r_fact<<endl;
    n_minus_r_fact = fact(n-r);
    cout<<"N-r fact is "<<n_minus_r_fact<<endl;
    ncr = n_fact/(n_minus_r_fact*r_fact);
    cout<<ncr<<endl;
}