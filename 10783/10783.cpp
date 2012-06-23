#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		int a,b;
		cin>>a>>b;
		int sum = 0;
		for(int j=a;j<=b;j++){
			if(j%2)sum+=j;
		}
		printf("Case %d: %d\n",i+1,sum);
	}
	return 0;
}
