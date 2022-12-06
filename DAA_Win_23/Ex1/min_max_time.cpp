#include<iostream>
using namespace std;
#include<vector>
#include <ctime> 
int main()
{
	int i,n, min,max,ele;
//	int a[20];
	vector<int> a;
	cin>>n;
	cout<<"Enter elements";
	for(i=0;i<n;i++)
	{
		cin>>ele;
		a.push_back(ele);
	}
	min = a[0];
	max = a[0];
	//  number of clock ticks elapsed since an epoch related to the particular program execution
	clock_t tStart = clock();
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
			min = a[i];
		if(a[i]>max)
			max = a[i];

	}
	//  number of clock ticks elapsed since an epoch related to the particular program execution
	// divide by CLOCKS_PER_SEC to get number of seconds taken
	double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	cout<<"Time taken is "<<time1<<endl;
	cout<<"Minimum is " <<min<<endl;
	cout<<"Max is "<<max<<endl;
}



