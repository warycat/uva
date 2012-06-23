#include<iostream>
#include<cstdio>
using namespace std;

char a[128];

void init()
{
	a['1']='`';
	a['2']='1';
	a['3']='2';
	a['4']='3';
	a['5']='4';
	a['6']='5';
	a['7']='6';
	a['8']='7';
	a['9']='8';
	a['0']='9';
	a['-']='0';
	a['=']='-';
	a['W']='Q';
	a['E']='W';
	a['R']='E';
	a['T']='R';
	a['Y']='T';
	a['U']='Y';
	a['I']='U';
	a['O']='I';
	a['P']='O';
	a['[']='P';
	a[']']='[';
	a['\\']=']';
	a['S']='A';
	a['D']='S';
	a['F']='D';
	a['G']='F';
	a['H']='G';
	a['J']='H';
	a['K']='J';
	a['L']='K';
	a[';']='L';
	a['\'']=';';
	a['X']='Z';
	a['C']='X';
	a['V']='C';
	a['B']='V';
	a['N']='B';
	a['M']='N';
	a[',']='M';
	a['.']=',';
	a['/']='.';
	a['\n']='\n';
	a[' ']=' ';
}


int main()
{
	char c;
	init();
	while((c=getchar())!=EOF)putchar(a[c]);
	return 0;
}

