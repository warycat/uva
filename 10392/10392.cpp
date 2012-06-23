#include<iostream>
#include<cmath>
using namespace std;

unsigned long long n;

int main()
{
	while(cin>>n&&n!=-1){
		for(int i=2;n!=1&&i<=sqrt(n);i++){
			while(n%i==0){
				cout<<"    "<<i<<endl;
				n/=i;
			}
		}
		if(n!=1)cout<<"    "<<n<<endl;
		cout<<endl;
	}
	return 0;
}
