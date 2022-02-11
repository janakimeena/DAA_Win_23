#include<iostream>
using namespace std;
int main()
{
    int elements[100000],key,i,j,n,num_comp;
    //cout<<"Enter number of elements";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>elements[i];
    num_comp=0;
    for(j=1;j<n;j++)
    {
        key = elements[j];
        i = j-1;
        while((i>=0)&&(elements[i]>key))
        {
		num_comp++;
            elements[i+1] = elements[i];
            i = i-1;
        }
        elements[i+1] = key;
    }
	cout<<" Number of shifts "<<num_comp;
/*   for(i=0;i<n;i++)
    {
        cout<<elements[i]<<" ";
    }*/
}
