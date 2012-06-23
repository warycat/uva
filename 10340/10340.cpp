#include<iostream>
using namespace std;

bool subsequence(string s, string t)
{
	int i;
	int j;
	int ss = s.size();
	int st = t.size();
	for(i=0,j=0;i<ss;i++){
		while(s[i]!=t[j]){
			j++;
			if(j>=st)return false;
		}
		j++;
	}
	return true;
}

int main()
{
	string s,t;
	while(cin>>s>>t){
		cout<<(subsequence(s,t)?"Yes":"No")<<endl;
	}
	return 0;
}
