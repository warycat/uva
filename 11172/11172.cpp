#include<iostream>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		long long a,b;
		cin>>a>>b;
		if(a>b)cout<<">"<<endl;
		if(a<b)cout<<"<"<<endl;
		if(a==b)cout<<"="<<endl;
	}
	return 0;
}
