#include<iostream>
using namespace std;

int a[1000000];
int N;
void init()
{
	for(int i=0;i<1000000;i++)a[i]=1;
	for(long long i=2;i<1000000;i++){
		if(a[i]==0)continue;
		for(long long j=2;i*j<1000000;j++)a[i*j]=0;
	}
}
int reverse(int v)
{
	int t=0;
	while(v){
		t=t*10+v%10;
		v/=10;
	}
	return t;
}
int prime(int n)
{
	if(a[n]==0)return 0;
	else if(n==reverse(n))return 1;
	else if(a[reverse(n)]==0)return 1;
	else return 2;	
}
int main()
{
	init();
	while(cin>>N){
		switch(prime(N)){
			case 0:cout<<N<<" is not prime.\n";
			       break;
			case 1:cout<<N<<" is prime.\n";
			       break;
			case 2:cout<<N<<" is emirp.\n";
			       break;
			default:cout<<"error\n";
		}
	}
	return 0;
}
