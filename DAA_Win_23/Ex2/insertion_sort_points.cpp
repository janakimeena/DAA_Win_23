// 10
// 1 5 8 9 10 17 17 20 24 30

#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
class point
{
    int x,y;
    public:
    bool operator>(point);
    friend istream& operator>>(istream&,point&);
    friend ostream& operator<<(ostream&,point&);
};
bool point::operator>(point p)
{
    float dis1,dis2;
    dis1 = sqrt(x*x+y*y);
    dis2 = sqrt(p.x*p.x+p.y*p.y);
    return (dis1>dis2);
}
istream& operator>>(istream& in, point &p)
{
    in>>p.x>>p.y;
    return in;
}
ostream& operator<<(ostream& out,point &p)
{
    out<<p.x<<" "<<p.y<<endl;
}
int main()
{
    vector<point> elements;
    point key,ele;
    int i,j,n;
    //cout<<"Enter number of elements";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);        
    }
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
