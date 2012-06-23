#include<iostream>
#include<string>

using namespace std;
string f[10];
string r[10];
string text;
int n;

int main()
{
	while(cin>>n&&n){
		cin.get();
		int i;
		for(i=0;i<n;i++){
			getline(cin,f[i]);
			getline(cin,r[i]);
		}
		getline(cin,text);
		for(i=0;i<n;i++){
			int p;
			while((p=text.find(f[i]))!=-1)
				text.replace(p,f[i].size(),r[i]);
		}
		cout<<text<<endl;
	}
	return 0;
}
