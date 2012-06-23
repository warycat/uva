#include<iostream>
#include<cmath>
using namespace std;

long long n;

int light()
{
	long long root=(long long)floor(sqrt(n));
	if(root*root==n)return 1;
	else return 0;
}	

int main()
{
	while(cin>>n&&n){
		if(light())
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
