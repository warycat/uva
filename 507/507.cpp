#include<iostream>
#include<cstdio>
using namespace std;

int a;
int s;
int n;

int l,r;
int ll;
int rr;
int sum;
int maxsum;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		ll=0;
		rr=0;
		sum=-1;
		maxsum=0;
		for(int j=1;j<s;j++){
			cin>>a;
			if(sum<0){
				sum=0;
				if(a>0)l=j;
			}
			r=j+1;
			sum+=a;
			if(sum>maxsum){
				maxsum=sum;
				ll=l;
				rr=r;
			}else if(sum==maxsum){
				if((r-l)>(rr-ll)){
					ll=l;
					rr=r;
				}
			}
		}
		if(maxsum==0)
			printf("Route %d has no nice parts\n",i+1);
		else
			printf("The nicest part of route %d is between stops %d and %d\n",i+1,ll,rr);
	}
}
