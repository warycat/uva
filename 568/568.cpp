#include<iostream>
#include<cstdio>
using namespace std;

int n;
long long d;

int main()
{
	while(cin>>n){
		d=1;
		for(int i=1;i<=n;i++){
			int t=i;
			while(t%10==0)t/=10;
			while(d%10==0)d/=10;
			d*=t;
			while(d%10==0)d/=10;
			d%=100000000;
			
		}
		printf("%5d -> %lld\n",n,d%10);
	}
	return 0;
}
