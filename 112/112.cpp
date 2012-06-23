#include<iostream>
using namespace std;

int flag;

int tree(int v)
{
	char c;
	cin>>c;
	int x;
	if(cin>>x){
//		cout<<x<<endl;
		int l = tree(v-x);
		int r = tree(v-x);
		if(l==0&&r==0&&x==v)flag++;
		cin>>c;
		return 1;
	}else{
		cin.clear();
		cin>>c;
		return 0;
	}
}


int main()
{
	int I;
	while(cin>>I){
		flag=0;
		tree(I);
		if(flag)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
