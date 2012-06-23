#include<iostream>
#include<string>
using namespace std;

string s[2];
int n[2];
int a[2000][2000];

void print()
{
	for(int i=0;i<s[0].size();i++){
		for(int j=0;j<s[1].size();j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	while(getline(cin,s[0]),getline(cin,s[1])){
		n[0]=s[0].size();
		n[1]=s[1].size();
		for(int i=0;i<=n[0];i++){
			for(int j=0;j<=n[1];j++){
				if(i==0||j==0)a[i][j]=0;
				else {
					char c[2];
					c[0]=s[0][i-1];
					c[1]=s[1][j-1];
					if(c[0]==c[1])a[i][j]=a[i-1][j-1]+1;
					else a[i][j]=max(a[i-1][j],a[i][j-1]);
				}
			}
		}
		//print();
		cout<<a[n[0]][n[1]]<<endl;
	}
	return 0;
}
