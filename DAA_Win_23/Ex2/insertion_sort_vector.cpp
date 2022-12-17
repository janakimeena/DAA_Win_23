#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> elements(20,0);
    int key,i,j,n;
    //cout<<"Enter number of elements";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>elements[i];
    
    for(j=1;j<n;j++)
    {
        key = elements[j];
        i = j-1;
        while((i>=0)&&(elements[i]>key))
        {
            elements[i+1] = elements[i];
            i = i-1;
        }
        elements[i+1] = key;
    }

   for(i=0;i<n;i++)
    {
        cout<<elements[i]<<" ";
    }
}
