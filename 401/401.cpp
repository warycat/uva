#include<iostream>
#include<string>
using namespace std;
char r[256];
void init()
{
	int i;
	for(i=0;i<256;i++)r[i]=0;
	r['A']='A';	r['E']='3';	r['H']='H';	r['I']='I';
	r['J']='L';	r['L']='J';	r['M']='M';	r['O']='O';
	r['S']='2';	r['T']='T';	r['U']='U';	r['V']='V';
	r['W']='W';	r['X']='X';	r['Y']='Y';	r['Z']='5';
	r['1']='1';	r['2']='S';	r['3']='E';	r['5']='Z';
	r['8']='8';
}
int pal(string s)
{
	int t=s.size();
	for(int i=0;i<t;i++)if(s[i]!=s[t-1-i])return 0;
	return 1;
}
int mir(string s)
{
	int t = s.size();
	for(int i=0;i<t;i++)if(s[i]!=r[s[t-1-i]])return 0;
	return 1;
}
int main()
{
	string s;
	int c;
	init();
	while(cin>>s){
		c = pal(s)*2+mir(s);
		cout<<s;
		switch(c){
			case 0:	cout<<" -- is not a palindrome.\n\n";
				break;
			case 2:	cout<<" -- is a regular palindrome.\n\n";
				break;
			case 1:	cout<<" -- is a mirrored string.\n\n";
				break;
			case 3:	cout<<" -- is a mirrored palindrome.\n\n";
				break;
			default:cout<<"error\n";
		}
	}
	return 0;
}
