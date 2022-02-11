#include<iostream>
using namespace std;
#include<vector>
long int fiba(int n)
{
    static vector<int> fiba_computed(100,-1);
    long int i,c;
    fiba_computed[0] = 0;
    fiba_computed[1] = 1;
    if (fiba_computed[n-1]!=-1)
        return fiba_computed[n-1];
    c = fiba(n-1)+fiba(n-2);
    fiba_computed[n-1] = c;
    return c;
}
int main()
{
    int n;
    cin>>n;
    cout<<fiba(n);
}