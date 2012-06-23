#include<iostream>
using namespace std;

long long x;
long long rx;

bool palindrome(long long v)
{
	char s[100];
	int n;
	for(n=0;v;n++){
		s[n]=v%10;
		v/=10;
	}
	for(int i=0;i<n;i++)
		if(s[i]!=s[n-1-i])return false;
	return true;
}

long long reverse(long long v)
{
	char s[100];
	int n;
	for(n=0;v;n++){
		s[n]=v%10;
		v/=10;
	}
	long long r = 0;
	for(int i=0;i<n;i++){
		r*=10;
		r+=s[i];
	}
	return r;
}

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>x;
		int cnt = 0;
		while(!palindrome(x)){
			cnt++;
			rx = reverse(x);
			x = x+rx;
		}
		cout<<cnt<<" "<<x<<endl;
	}
	return 0;
}
