#include<iostream>
using namespace std;

int n;
int a[100000];
long long work;

int main()
{
	while(cin>>n && n){
		work = 0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++){
			int j=i+1;
			while(a[i]>0){
				while(a[j]>=0)j++;
				int t = min(a[i],-a[j]);
				a[i]-=t;
				a[j]+=t;
				work+=t*(j-i);
			}
			j=i+1;
			while(a[i]<0){
				while(a[j]<=0)j++;
				int t = min(-a[i],a[j]);
				a[i]+=t;
				a[j]-=t;
				work+=t*(j-i);
			}
		}
		cout<<work<<endl;
	}
	return 0;
}	

