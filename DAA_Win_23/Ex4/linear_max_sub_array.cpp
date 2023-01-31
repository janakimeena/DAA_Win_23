#include<iostream>
using namespace std;
#include<vector>
struct details
{
    int low;
    int high;
    int sum;
    
};
details linear_max_sub_array(vector<int> elements)
{
    int global_max = elements[0];
    // we will sum up the values of array in this variable
    // this variable will be either positive or zero only
    int positive_sum_till_here = 0,max_len =0;
    int n,i,low,high,global_low;
    details d;
    n = elements.size();
    // initialize the indices appropriately
    low = 0;
    global_low = 0;
    high = n-1;
    for(i=0;i<n;i++)
    {
        cout<<"Positive sum "<<positive_sum_till_here<<endl<<" ";
        cout<<"Global max"<<global_max<<endl;
        // add each element in array to positive_sum_till_here variable
        positive_sum_till_here+=elements[i];
        // if it becomes greater than global_max then
        // make global max as the last index which negated the sum
        // make current index as high
        if(positive_sum_till_here>global_max)
        {
            global_max = positive_sum_till_here;
            global_low = low;
            high = i;
            max_len = high-low+1;
        }
        else if(((positive_sum_till_here==global_max)&&((high-low+1)>max_len)))
        {
            global_max = positive_sum_till_here;
            global_low = low;
            high = i;
            max_len = high-low+1;
        }
        //if positive sum becomes negative then make it as zero and make 
        // low as the next index of the array
        if(positive_sum_till_here<0)
        {
            positive_sum_till_here = 0;            
            low = i+1;
        }
    }
    d.low = global_low+1;
    d.high = high+1;
    d.sum = global_max;
    return d;
}
int main()
{
    vector<int> elements;
    int i,n,ele;
    details d;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    d = linear_max_sub_array(elements);
    cout<<d.low<<" "<<d.high<<" "<<d.sum;
}
