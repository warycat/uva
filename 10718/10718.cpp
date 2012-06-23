#include<iostream>
using namespace std;

unsigned long N,L,U,M;

int main()
{
	while(cin>>N>>L>>U){
		M = 0;
		for(int i=31;i>=0;i--){
			unsigned long V = (1u<<i); // 1u not 1
			if ((M|V)>U)continue;
			if ((M|V)-1<L){
				M|=V;
				continue;
			}
			if((N|V)>N){
				M|=V;
			}
		}	
		cout<<M<<endl;
	}
	return 0;
}
