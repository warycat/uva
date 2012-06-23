#include<iostream>
#include<sstream>
using namespace std;

int a[1000000];
int tos;

stringstream ss;

int Matrioshka()
{
	int v;
	tos=0;
	while(ss>>v){
//		cout<< v<<endl;
		if(v<0)a[tos++]=v;
		else{
			int i=tos-1;
			int sum=0;
			while(1){
				if(i<0)return 0;
				if(a[i]>0){
					sum+=a[i];
					i--;
					continue;
				}
				if(a[i]<0){
					if(a[i]+v!=0)return 0;
					if(sum>=v)return 0;
					a[i]=v;
					tos=i+1;
					break;
				}
			}
		}
	}
	if(tos==1)return 1;
	return 0;
}

int main()
{
	string s;
	while(getline(cin,s)){
		if(s=="")break;
		ss.clear();
		ss.str(s);
		if(Matrioshka())cout<<":-) Matrioshka!\n";
		else cout<<":-( Try again.\n";
	}
	return 0;
}
		
