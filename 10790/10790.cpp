#include<iostream>
#include<cstdio>
using namespace std;

long long a,b;

long long intersection()
{
	return a*(a-1)*b*(b-1)/4;
}

int main()
{
	int tc=1;
	while(cin>>a>>b){
		if(a==0&&b==0)break;
		printf("Case %d: %lld\n",tc++,intersection());
	}
	return 0;
}
