#include<iostream>
#include<cstdio>
using namespace std;
int tc;
char a[50][50];
int r,c;
int n;
string s;
int dx[]={+1,-1, 0, 0,+1,-1,+1,-1};
int dy[]={ 0, 0,+1,-1,+1,-1,-1,+1};

void readTable()
{
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}
}	

int check(int x, int y,char t)
{
	if(x>=0&&x<r&&y>=0&&y<c){
		if(tolower(a[x][y])==tolower(t))return 0;
	}
	return 1;
}

int searchWord(int x,int y)
{
	for(int k=0;k<8;k++){
		int i;
		for(i=0;i<s.size();i++)
			if(check(x+i*dx[k],y+i*dy[k],s[i]))break;
		if(i==s.size()){
			return 1;
		}
	}
	return 0;
}
	
void searchTable()
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(searchWord(i,j)){
				cout<<i+1<<" "<<j+1<<endl;
				return;
			}
}

int main()
{
	cin>>tc;
	for(int i=0;i<tc;i++){
		if(i)cout<<endl;
		cin>>r>>c;
		readTable();
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>s;
			searchTable();
		}
	}
	return 0;
}

