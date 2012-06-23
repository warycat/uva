#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int a[30];
int t[30];
int n;

void flip(int j)
{
	int i;
	for(i=0;i<n-j;i++)t[j+i]=a[j+i];
	for(i=0;i<n-j;i++)a[j+i]=t[n-1-i];
	cout << j+1 << " ";
}
int main()
{
	string line;
	stringstream ss;
	while(getline(cin,line)){
		cout<<line<<endl;
		ss.clear();
		ss.str(line);
		int i,j,k;
		for(i=0;ss>>t[i];i++);
		n=i;
		for(i=0;i<n;i++)a[i]=t[n-1-i];
		for(i=0;i<n;i++){
			for(j=k=i;j<n;j++)if(a[j]>a[k])k=j;
			flip(k);
			flip(i);
		}
		cout<<'0'<<endl;
	}
	return 0;
}

