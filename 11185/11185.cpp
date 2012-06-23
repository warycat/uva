#include<iostream>
#include<cstdio>
using namespace std;


long long N;

void print(int v)
{
	if(v){
		print(v/3);
		printf("%d",v%3);
	}
}

int main()
{
	while(cin>>N&&N>=0){
		if(N)
			print(N);
		else
			printf("0");
		printf("\n");
	}
	return 0;
}
