#include<iostream>
#include<cstdio>
using namespace std;

char f[256];

int main()
{
	int c;
	f['\n']='\n';
	f['-']='-';
	f['0']='0';
	f['1']='1';
	f['A']=f['B']=f['C']='2';
	f['D']=f['E']=f['F']='3';
	f['G']=f['H']=f['I']='4';
	f['J']=f['K']=f['L']='5';
	f['M']=f['N']=f['O']='6';
	f['P']=f['Q']=f['R']=f['S']='7';
	f['T']=f['U']=f['V']='8';
	f['W']=f['X']=f['Y']=f['Z']='9';

	while((c=getchar())!=EOF){
		putchar(f[c]);	
	}
	return 0;
}
