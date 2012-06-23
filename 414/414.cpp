#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cctype>
using namespace std;

string s;
int a[20];
int n;

int main()
{
	while(getline(cin,s)){
		if((n=atoi(s.c_str()))==0)break;
		int i,j;
		int min = 25;
		for(i=0;i<n;i++){
			getline(cin,s);
			a[i]=0;
			for(j=0;j<s.size();j++)if(s[j]==' ')a[i]++;
			min = ((min>a[i])?a[i]:min);
		}
		int sum =0;
		for(i=0;i<n;i++) sum += (a[i]-min);
		cout << sum << endl;
	}
	return 0;
}

