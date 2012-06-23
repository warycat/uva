#include<iostream>
#include<sstream>
using namespace std;

int k;
int p[10001];
int q[10001];
int n;
int r;

int main()
{
	string s;
	stringstream ss;
	while(1){
		getline(cin,s);
		if(s=="")break;
		ss.clear();
		ss.str(s);
		ss>>k;
		getline(cin,s);
		ss.clear();
		ss.str(s);
		for(n=0;ss>>p[n];n++);
		for(int i=0;i+1<n;i++){
			q[i+1]=p[i];
			p[i+1]-=q[i+1]*(-k);
		}
		r=p[n-1];
		cout<<"q(x):";
		for(int i=1;i<n;i++)cout<<" "<<q[i];
		cout<<endl;
		cout<<"r = "<<r<<endl<<endl;
	}
	return 0;
}
