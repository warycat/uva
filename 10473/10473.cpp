#include<iostream>
using namespace std;

string s;
char h[]="0123456789ABCDEF";

void printHex(int x)
{
	if(x){
		printHex(x/16);
		cout<<h[x%16];
	}
}

void decToHex()
{
	int x=0;
	for(int i=0;i<s.size();i++){
		x*=10;
		x+=s[i]-'0';
	}
	cout<<"0x";
	printHex(x);
	cout<<endl;
}

void hexToDec()
{
	int x=0;
	for(int i=2;i<s.size();i++){
		char c = s[i];
		x*=16;
		if(isalpha(c))x+=toupper(c)-'A'+10;
		else x+=c-'0';
	}
	cout<<x<<endl;
}
		

int main()
{
	while(cin>>s){
		if(s[0]=='-')break;
		if(s.compare(0,2,"0x")==0)hexToDec();
		else decToHex();
	}
	return 0;
}
