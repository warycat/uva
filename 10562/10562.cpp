#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

char a[300][300];
int n;
char s[300];

void readTree()
{
	n=0;
	int j=0;
	int c;
	while((c=getchar())!=EOF){
		if(c=='\n'){
			n++;
			j=0;
		}else{
			if(c=='#')break;
			a[n][j++]=c;
		}
	}
	getchar();
}

void clear()
{
	for(int i=0;i<300;i++)
		for(int j=0;j<300;j++)
			a[i][j]=' ';
}

int isSymbol(char c)
{
	if(c==' '||c=='|'||c=='-'||c=='#'||c=='\n')return 0;
	else return 1;
}

void printTree(int l,int r,int i)
{
	cout<<"(";
	for(int j=l;j<=r;j++)if(isSymbol(a[i][j])){
		cout<<a[i][j];
		if(a[i+1][j]=='|'){
			int ll=j;
			int rr=j;
			while(ll>=0&&a[i+2][ll-1]=='-')ll--;
			while(rr>=0&&a[i+2][rr+1]=='-')rr++;
			printTree(ll,rr,i+3);
		}else
			cout<<"()";
	}
	cout<<")";
}

void debug()
{
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
}

int main()
{
	gets(s);
	int tc = atoi(s);
	for(int i=0;i<tc;i++){
		clear();
		readTree();
		printTree(0,200,0);
		cout<<endl;
	}
	return 0;
}
