#include<iostream>
#include<string>
using namespace std;

int a[150];
int n;

void add(string s)
{
	int L=s.size();
	for(int i=0;i<L;i++)a[i]+=s[L-1-i]-'0';
}

void carry()
{
	for(int i=0;i<149;i++){
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
}

void print()
{
	if(n==0)cout<<0;
	for(int i=0;i<n;i++)cout<<a[n-1-i];
	cout<<endl;
}

void calculateN()
{
	n=150;
	while(a[n-1]==0&&n>=1)n--;
}

void init()
{
	for(int i=0;i<150;i++)a[i]=0;
	n=0;
}

int main()
{
	string s;
	init();
	while(cin>>s){
		if(s=="0")break;
		add(s);
	}
	carry();
	calculateN();
	print();
	return 0;
}

