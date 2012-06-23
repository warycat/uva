#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string s[2][100];
int n[2];
int a[100][100];

void print()
{
	for(int i=0;i<=n[0];i++){
		for(int j=0;j<=n[1];j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
}

void LCS()
{
	for(int i=0;i<=n[0];i++){
		for(int j=0;j<=n[1];j++){
			if(i==0||j==0)a[i][j]=0;
			else{
				if(s[0][i-1]==s[1][j-1])a[i][j]=a[i-1][j-1]+1;
				else a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
	}
}

void printLCS(int i, int j)
{
//	printf("%d %d\n",i,j);
	if (i == 0 || j == 0) return;
	if (s[0][i-1] == s[1][j-1]) {
		printLCS(i-1,j-1);
		cout << (a[i][j] == 1 ? "" : " ") <<s[0][i - 1];
	} else {
		if (a[i-1][j] > a[i][j-1]) printLCS(i - 1, j);
		else printLCS(i, j - 1);
	}
}

int main()
{
	int i=0;
	int j=0;
	string t;
	while(cin>>t){
		if(t=="#"){
			n[i]=j;
			i=(i+1)%2;
			j=0;
			if(i==0){
				LCS();
				printLCS(n[0],n[1]);
				cout<<endl;
			}
		}else{
			s[i][j++]=t;
		}
	}
	return 0;
}
			
