#include<iostream>
#include<cstdio>
using namespace std;

long long N,S2[101],R2[101],S3[101],R3[101],S4[101],R4[101];
long long A1[101],A2[101],A3[101],A4[101];
int main()
{
	A1[0]=A2[0]=A3[0]=S2[0]=S3[0]=S4[0]=R2[0]=R3[0]=R4[0]=0;
	for(int i=1;i<=100;i++){
		A1[i]=(i+1)*i/2;
		A2[i]=A1[i]*A1[i];
		A3[i]=A2[i]*A1[i];
		A4[i]=A3[i]*A1[i];
		S2[i]=S2[i-1]+i*i;
		S3[i]=S3[i-1]+i*i*i;
		S4[i]=S4[i-1]+i*i*i*i;
		R2[i]=A2[i]-S2[i];
		R3[i]=A3[i]-S3[i];
		R4[i]=A4[i]-S4[i];
	}
	while(cin>>N){
		int i,j,k,l;
//		printf("%lld %lld %lld\n",A2[N],A3[N],A4[N]);
		printf("%lld %lld %lld %lld %lld %lld\n",
				S2[N],R2[N],S3[N],R3[N],S4[N],R4[N]);
	}
	return 0;
}
