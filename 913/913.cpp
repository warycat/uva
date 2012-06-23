#include<iostream>
using namespace std;

long long k;
long long n;
long long last;
long long sum;

int main()
{
	while(cin>>k){
		n = (k+1)/2;
		last = 2*(n*(n+1)-n)-1;
		sum = 3 * last - 6;
		cout<<sum<<endl;
	}
	return 0;
}
