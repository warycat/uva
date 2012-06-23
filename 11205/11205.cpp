#include<iostream>
#include<cstdio>
using namespace std;

int led;
int P;
int a[100];
int N;
int K;
int stop;

void print(int v)
{
	for(int i=0;i<P;i++)
		printf("%x",(v>>i)&1);
	printf("\n");
}

void match()
{
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++){
			if(((a[i]^a[j])&led)==0){
				return;
			}
		}
//	print(led);
//	printf("\n");
	stop=1;
}


void perm(int k,int l)
{
	if(k==K){
		match();
	}else{
		for(int i=l;i<P;i++){
			led|=(1<<i);
			perm(k+1,i+1);
			led&=~(1<<i);
		}
	}
}

int check()
{
//	printf("K %x\n",K);
	led=0;
	perm(0,0);
	return stop;
}

int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>P>>N;
		for(int j=0;j<N;j++){
			int v=0;
			int t;
			for(int k=0;k<P;k++){
				cin>>t;
				v|=(t<<k);
			}
			a[j]=v;
//			print(a[j]);
		}
		stop=0;
		for(K=1;K<P;K++)
			if(check())break;
		cout<<K<<endl;
	}
	return 0;
}

				

		
