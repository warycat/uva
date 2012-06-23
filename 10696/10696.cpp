#include<iostream>
#include<cstdio>
using namespace std;

int N;

int f91(int x)
{
	if(x<=100)return f91(f91(x+11));
	if(x>=101)return x-10;
	return 0;
}

int main()
{
	while(cin>>N&&N){
		printf("f91(%d) = %d\n",N,f91(N));
	}
	return 0;
}	
