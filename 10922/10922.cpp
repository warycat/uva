#include<iostream>
using namespace std;

int rec(int n)
{
	if(n%9!=0)return 0;
	if(n==9)return 1;
	int t=0;
	for(;n;n/=10)t+=n%10;
	return rec(t)+1;
}

int main()
{
	string s;
	while(cin>>s&&s!="0"){
		int sum=0;
		for(int i=0;i<s.size();i++)sum+=s[i]-'0';
		int degree=rec(sum);
		if(degree)
			cout<<s<<" is a multiple of 9 and has 9-degree "<<degree<<".\n";
		else
			cout<<s<<" is not a multiple of 9.\n";
		
	}
	return 0;
}
