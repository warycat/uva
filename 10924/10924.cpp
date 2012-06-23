#include<iostream>
#include<cctype>
using namespace std;

bool isPrime(int x)
{
	if(x==1)return true;
	for(int i=2;i<x;i++)
		if(x%i==0)return false;
	return true;
}

int hash(string x)
{
	int ss = x.size();
	int sum = 0;
	for (int i=0;i<ss;i++){
		char c = x[i];
		if(isalpha(c)){
			if(islower(c))sum+=c-'a'+1;
			if(isupper(c))sum+=c-'A'+27;
		}
	}
	return sum;
}

int main()
{
	string s;
	while(cin>>s){
		if(isPrime(hash(s)))
			cout<<"It is a prime word."<<endl;
		else
			cout<<"It is not a prime word."<<endl;
	}
	return 0;
}
