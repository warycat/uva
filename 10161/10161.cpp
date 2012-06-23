#include<iostream>
using namespace std;

long long n;
long long x;
long long y;
long long i;

int main()
{
	while(cin>>n&&n){
		for(i=1;i*i<n;i++);
		long long remain = n-(i-1)*(i-1);
		if(remain==i){
			x=i;
			y=i;
		}
		if(remain<i){
			if(i%2){
				x=i;
				y=remain;
			}else{
				y=i;
				x=remain;
			}
		}
		if(remain>i){
			remain-=i;
			if(i%2){
				x=i-remain;
				y=i;
			}else{
				y=i-remain;
				x=i;
			}
		}
//		printf("*%lld %lld %lld\n",n,i,remain);
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}