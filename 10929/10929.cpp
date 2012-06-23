#include<iostream>
using namespace std;

bool isEleven(string s)
{
	int even = 0;
	int odd = 0;
	int ss = s.size();
	for(int i=0;i<ss;i++){
		if(i%2)even += s[i]-'0';
		else odd += s[i]-'0';
	}
	int diff = even - odd;
	if(diff<0)diff = -diff;
	if(diff%11==0)return true;
	return false;
}

int main()
{
	string s;
	while(cin>>s){
		if(s=="0")break;
		cout<<s;
		if(isEleven(s))cout<<" is a multiple of 11."<<endl;
		else cout<<" is not a multiple of 11."<<endl;
	}
	return 0;
}
