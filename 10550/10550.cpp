#include <iostream>
#include <cstdio>
using namespace std;

int turn(int a, int b)
{
	if(a-b>0)
		return (a-b)*9;
	else
		return (a-b+40)*9;
}

int main()
{
	int d1;
	int d2;
	int d3;
	int d4;
	while(cin>>d1>>d2>>d3>>d4){
		if(d1==0&&d2==0&&d3==0&&d4==0)break;
		printf("%d\n",1080+turn(d1,d2)+turn(d3,d2)+turn(d3,d4));
	}
	return 0;
}
