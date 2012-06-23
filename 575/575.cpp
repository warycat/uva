#include<iostream>
using namespace std;

string s;
int n;

int main()
{
	while(cin>>s&&s!="0"){
//		cout<<s<<endl;
		n=s.size();
		long long sum = 0;
		for(int i=0;i<n;i++)
			sum+=(s[i]-'0')*((1<<(n-i))-1);
		cout<<sum<<endl;
	}
	return 0;
}	
