#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int n;
int p;

struct rfp{
	string name;
	double price;
	int list;
};

bool isBetter(struct rfp a, struct rfp b)
{
	if(a.list < b.list)return false;
	if(a.list > b.list)return true;
	if(a.price > b.price)return false;
	if(a.price < b.price)return true;
	return false;
}


int main()
{
	int tc = 0;
	while(cin>>n>>p&&n&&p){
		string s;
		getline(cin,s);
		for(int i=0;i<n;i++){
			getline(cin,s);
		}
		struct rfp best = {"",0,0};
		for(int i=0;i<p;i++){
			struct rfp t;
			getline(cin,t.name);
			cin>>t.price;
			cin>>t.list;
			getline(cin,s);
			for(int j=0;j<t.list;j++)getline(cin,s);
			if(isBetter(t,best))best=t;
		}
		if(tc)cout<<endl;
		printf("RFP #%d\n",++tc);
		cout<<best.name<<endl;

	}
	return 0;
}
