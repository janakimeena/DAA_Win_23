#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
// 13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
struct details
{
    int low;
    int high;
    int sum;
};
details find_maximum_subarray(vector<int> a)
{
    int i, j, n, max_left,max_right, max_sum,curr_sum;
    details d;
    max_sum = INT_MIN;
    n = a.size();
    for(i=0;i<n;i++)
    {
        curr_sum = a[i];
        // size of sub_array is 1 and ith element is part of it
        if(curr_sum>max_sum)
        {
            max_sum = curr_sum;
            max_left = i;
            max_right = i;
        }
        // size of subarray will be from 2 to n - i and ith element is part of it
        for(j=i+1;j<n;j++)
        {
            curr_sum += a[j];
            if(curr_sum>max_sum)
            {
                max_sum = curr_sum;
                max_left = i;
                max_right = j;
            }
        }
    }
    d.low = max_left;
    d.high = max_right;
    d.sum = max_sum;
    return d;
}
int main()
{
    vector<int> A;
    int low,high,n,i,ele;
    details ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        A.push_back(ele);
    }
    cout<<"Finished IP";
    ans = find_maximum_subarray(A);
    cout<<ans.low<<" "<<ans.high<<" "<<ans.sum<<endl;
}
