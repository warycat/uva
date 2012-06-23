#include<iostream>
#include<cstdio>
using namespace std;

int K,A,B,C,D;

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>K;
		int j;
		for(j=2;j<K;j++)if(K%j==0)break;
		A=j;
		for(j=2;j<K;j++)if(K%(j*A)==0)break;
		C=j*A;
		B=K/A;
		D=K/C;
		printf("Case #%d: %d = %d * %d = %d * %d\n",i+1,K,A,B,C,D);
	}
	return 0;
}
