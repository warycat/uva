#include<iostream>
#include<cstring>
using namespace std;

char a[20];
char b[20];
char ra[20];
char rb[20];

int main()
{
	while(cin>>a>>b&&!(strcmp(a,"0")==0&&strcmp(b,"0")==0)){
		for(int i=0;i<strlen(a);i++)ra[i]=a[strlen(a)-1-i];	
		for(int i=0;i<strlen(b);i++)rb[i]=b[strlen(b)-1-i];	
		ra[strlen(a)] = rb[strlen(b)] = '\0';
		int cnt = 0;
		int carry = 0;
		for(int i=0;i<20;i++){
			int sum = 0;
			sum += carry;
			if(i<strlen(ra))sum+=ra[i]-'0';
			if(i<strlen(rb))sum+=rb[i]-'0';
			carry = sum / 10;
			if (carry) cnt++;
		}
		if (cnt == 0)cout<<"No carry operation."<<endl;
		else if (cnt == 1)cout<<"1 carry operation."<<endl;
		else cout<<cnt<<" carry operations."<<endl;
	}
	return 0;
}

