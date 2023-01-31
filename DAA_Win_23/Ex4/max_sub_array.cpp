#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
struct details
{
    int low;
    int high;
    int sum;
};
details find_max_crossing_subarray(vector<int> a, int low, int mid, int high)
{
    int left_sum, right_sum, sum, i, max_left, max_right;
    details d;
    sum = 0;
    left_sum = INT_MIN;
    for(i=mid;i>=low;i--)
    {
        sum += a[i];
        if (sum>left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    right_sum = INT_MIN;
    sum=0;
    for(i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        if (sum>right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    d.low = max_left;
    d.high = max_right;
    d.sum = left_sum + right_sum;
    return d;
}
details find_maximum_subarray(vector<int> a,int low,int high)
{
    details left_details,right_details,cross_details,d;
    int mid;
    if(low==high)
    {
        d.low = low;
        d.high = high;
        d.sum = a[low];
        return d;
    }
    mid = (low+high)/2;
    left_details = find_maximum_subarray(a,low,mid);
    right_details = find_maximum_subarray(a,mid+1,high);
    cross_details = find_max_crossing_subarray(a,low,mid,high);
    if((left_details.sum>=right_details.sum)&&(left_details.sum>=cross_details.sum))
        return left_details;
    else if((right_details.sum>=left_details.sum)&&(right_details.sum>=cross_details.sum))
        return right_details;
    else
        return cross_details;
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
    ans = find_maximum_subarray(A,0,n-1);
    cout<<ans.low<<" "<<ans.high<<" "<<ans.sum<<endl;
}