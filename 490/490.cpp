#include <cstdio>
#include <iostream>
#define MAX_N 100
using namespace std;

char a[MAX_N][MAX_N];

int main()
{
	int c;
	for(int i=0;i<MAX_N;i++)
		for(int j=0;j<MAX_N;j++)
			a[i][j]=' ';
	int i = 0;
	int j = 0;
	int row = 0;
	int col = 0;
	while((c=getchar())!=EOF){
		if(c=='\n'){
			col=(col>j)?col:j;
			j=0; 
			i++; 
			row++;
		}else 
			a[i][j++] = c;
	}
	for(int j = 0;j<col;j++){
		for(int i = row-1; i>=0; i--)
			cout << a[i][j];
		cout << endl;
	}
	return 0;
}
	

