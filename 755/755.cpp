#include<iostream>
#include<cstdlib>
using namespace std;

char buf[1000];
int a[10000000];
int n;

int main()
{
	int tc;
	cin.getline(buf,1000);
	tc=atoi(buf);
	for(int i=0;i<tc;i++){
		cin.getline(buf,1000);
		cin.getline(buf,1000);
		n=atoi(buf);
		for(int j=0;j<n;j++){
			cin.getline(buf,1000);
			puts(buf);
		}
	}
	return 0;
}