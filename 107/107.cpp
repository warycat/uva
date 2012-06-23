#include<iostream>
#include<cmath>
using namespace std;

int n,k;
int A,B;
int P,Q;

int power(int a,int b)
{
	int t=1;
	for(int i=0;i<b;i++)t*=a;
	return t;
}

void guess()
{
	int i=1;
	for(k=0;k<32;k++)
		for(n=1;n<65536;n++)
			if(power(n+1,k)==A&&power(n,k)==B)return;
}

void count()
{
	P=0;
	Q=0;
	int cats=1;
	for(int i=0;i<=k;i++){
		Q+=A*cats;
		A/=n+1;
		cats*=n;
	}
	cats=B;
	for(int i=0;i<=k;i++){
		P+=B;
		B/=n;
	}
	P-=cats;
}

int main()
{
	while(cin>>A>>B&&A&&B){
//		cout<<A<<" "<<B<<endl;
		guess();
		count();
//		cout<<n<<" "<<k<<endl;
		cout<<P<<" "<<Q<<endl;
	}
	return 0;
}	
