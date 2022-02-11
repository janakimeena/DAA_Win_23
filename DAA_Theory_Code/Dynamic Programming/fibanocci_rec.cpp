#include<iostream>
using namespace std;
int fiba(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fiba(n-1)+fiba(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<fiba(n);
}