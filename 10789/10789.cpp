#include<iostream>
using namespace std;

string s;

int a[128];
int n;

bool isPrime(int x)
{
	if(x==0)return false;
	if(x==1)return false;
	for(int i=2;i<x;i++)
		if(x%i==0)return false;
	return true;
}

void freq()
{
	for(int i=0;i<128;i++)a[i]=0;
	int ss = s.size();
	for(int i=0;i<ss;i++)a[s[i]]++;
}

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>s;
		freq();
		cout<<"Case "<<i+1<<": ";
		int cnt=0;
		for(char i='0';i<='9';i++){
			if(isPrime(a[i])){
				cout<<i;
				cnt++;
			}
		}
		for(char i='A';i<='Z';i++){
			if(isPrime(a[i])){
				cout<<i;
				cnt++;
			}
		}
		for(char i='a';i<='z';i++){
			if(isPrime(a[i])){
				cout<<i;
				cnt++;
			}
		}
		if(!cnt)cout<<"empty";
		cout<<endl;
	}
	return 0;
}


