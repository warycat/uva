#include<iostream>
using namespace std;

string a[200];
string s[200];
int n;

void printseq()
{
	int i=n-1;
	int j=n-1;
	while(i>=0&&j>=0){
		if(a[i]==s[j])j--;
		else i--;
	}
	while(j>=0)cout<<s[j--]<<endl;
}


int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		cin>>n;
		cin.get();
		for(int j=0;j<n;j++)getline(cin,a[j]);
		for(int j=0;j<n;j++)getline(cin,s[j]);
//		for(int j=0;j<n;j++)cout<<a[j]<<endl;
//		for(int j=0;j<n;j++)cout<<s[j]<<endl;
		printseq();
		cout<<endl;
	}
	return 0;
}
