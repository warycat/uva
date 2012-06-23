#include<iostream>
#include<cstdio>
using namespace std;

int collatzR(long long a, int l)
{
	if(a==1)return 1;
	if(a>l) return 0;
	if(a%2) return 1 + collatzR(3*a+1,l);
	else return 1 + collatzR(a/2,l);
}

int main()
{
	int A;
	int L;
	int seq = 1;
	while((cin>>A>>L)&&(A!=-1)){
		int terms = collatzR(A,L);
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",
			seq++, A, L, terms);
	}
	return 0;
}
