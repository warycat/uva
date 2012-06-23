#include<iostream>
#include<cstdio>
using namespace std;

int step;
int mod;


int choice()
{
	int t = min(step,mod);
	for(int i=2;i<=t;i++)if(step%i==0&&mod%i==0)return 0;
	return 1;
}

int main()
{
	while(cin>>step>>mod){
		if(choice())printf("%10d%10d    Good Choice\n",step,mod);
		else printf("%10d%10d    Bad Choice\n",step,mod);
		printf("\n");
	}
	return 0;
}

