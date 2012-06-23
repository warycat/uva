#include<iostream>
#include<cstdlib>
using namespace std;

int dots;
int dice[2500];
int n;
char image[50][50];
int w,h;


bool isValid(int i,int j)
{
	return i>=0 && i<h && j>=0 && j<w;
}

void readDot(int i,int j)
{
	if(isValid(i,j)){
		switch(image[i][j]){
			case '.':
				break;
			case '*':
				break;
			case 'X':
				image[i][j]='*';
				readDot(i-1,j);
				readDot(i+1,j);
				readDot(i,j-1);
				readDot(i,j+1);
				break;
		}
	}
}


void readDice(int i,int j)
{
	if(isValid(i,j)){
		switch(image[i][j]){
			case '.':
				break;
			case 'X':
				readDot(i,j);
				dots++;
				readDice(i,j);
				break;
			case '*':
				image[i][j]='.';
				readDice(i-1,j);
				readDice(i,j-1);
				readDice(i,j+1);
				readDice(i+1,j);
				break;
		}
	}
}

int cmp(int *p, int *q)
{
	return *p - *q;
}



int main()
{
	for(int tc = 1;cin>>w>>h&&w&&h;tc++){
		cout<<"Throw "<<tc<<endl;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>image[i][j];
		n=0;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(image[i][j]!='.'){
					dots=0;
					readDice(i,j);
					dice[n++]=dots;
				}
		qsort(dice,n,sizeof(int),(int(*)(const void*, const void*))cmp);
		for(int i=0;i<n;i++)
			cout<<dice[i]<<((i==n-1)?'\n':' ');
		cout<<endl;
	}
	return 0;
}

