#include<iostream>
#include<cmath>
using namespace std;

double x,k,p,q;
unsigned long long X,K,P,Q;

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>X>>K;
		x = X;
		k = K;
		unsigned long long F = floor(x/k);
		unsigned long long C = ceil(x/k);
		for(P=0;P<=K;P++){
			if((X-P*F)%C==0){
				Q = (X-P*F)/C;
				cout<<P<<" "<<Q<<endl;
				break;
			}
		}
	}
	return 0;
}
