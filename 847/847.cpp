#include<iostream>
using namespace std;

int game(long long n)
{
	int d1=9,d2=2;
	int t=0;
	for(long long i=1;i<n;i*=d2,t++)swap(d1,d2);
	return t;
}

int main()
{
	long long n;
	while(cin>>n){
		int t=game(n);
		if(t%2)cout<<"Stan wins.\n";
		else cout<<"Ollie wins.\n";
	}
	return 0;
}
