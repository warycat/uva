#include<iostream>
#include<cstdio>
using namespace std;

int base;
int lsb,bit;
int n;

int main()
{
	while(cin>>base>>lsb>>bit){
		int carry=0;
	       	int a=lsb; 
		int t;
		int len=1;
		while((t=a*bit+carry)!=lsb){
//			printf("%d %d %d %d\n",a,carry,bit,t);
			a=t%base;
			carry=t/base;
//			printf("%d %d\n",a,carry);
			len++;
		}
		cout<<len<<endl;
	}
	return 0;
}
	
