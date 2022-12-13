#include<iostream>
using namespace std;
#include<vector>
#include<string>
// Student class with name and marks as data members
class student
{
	string name;
	int marks;
	public:
	// Overloading extraction Operator
	friend istream& operator>>(istream&,student&);
	// Overloading insertion Operator
	friend ostream& operator<<(ostream&,student&);
	// Overloading less than operator to compare marks
	bool operator<(student&);
	// Overloading greater than operator to compare marks
	bool operator>(student&);
};
istream& operator>>(istream& in, student& s)
{
	cout<<"Enter name and marks";
	in>>s.name>>s.marks;
	return in;
}
ostream& operator<<(ostream& out, student& s)
{
	out<<s.name<<"\t"<<s.marks<<endl;
	return out;
}
bool student::operator<(student& s)
{
	return (marks<s.marks);
}
bool student::operator>(student& s)
{
	return(marks>s.marks);
}
int main()
{
	int i,n;
	student min,max,s;
	vector<student> a;
	cout<<"Enter number of elements";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		a.push_back(s);
	}
	min = a[0];
	max = a[0];
	for(auto it=a.begin();it!=a.end();it++)
	{
		cout<<*it;
		if(*it<min)
			min = *it;
		if(*it>max)
			max = *it;

	}
	cout<<"Minimum is " <<min<<endl;
	cout<<"Max is "<<max<<endl;
}
