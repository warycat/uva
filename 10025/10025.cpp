#include<iostream>
using namespace std;


int formula(int k)
{
	if(k==0)return 3;
	int n;
	for(n=1;n*(n+1)/2<k;n++);
	while((n*(n+1)/2-k)%2)n++;
	return n;
}


int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		int k;
		cin>>k;
		k=max(k,-k);
		if(i)cout<<endl;
		cout<<formula(k)<<endl;
	}
	return 0;
}	
