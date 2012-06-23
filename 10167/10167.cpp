#include<iostream>
#include<cstdio>
using namespace std;

int A,B;
int N;
int x[100];
int y[100];


void search()
{
	for(A=-500;A<=500;A++){
		for(B=-500;B<=500;B++){
			int left=0;
			int right=0;
			for(int i=0;i<2*N;i++){
				int t = A*x[i]+B*y[i];
				if(t>0)left++;
				if(t<0)right++;
			}
			if(left==N&&right==N)return;
		}
	}
}


int main()
{
	while(cin>>N&&N){
		for(int i=0;i<2*N;i++)cin>>x[i]>>y[i];
		search();
		printf("%d %d\n",A,B);
	}
	return 0;
}
	
