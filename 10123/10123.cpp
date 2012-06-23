#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int length;
int weight;
int n;
double p[20];
double w[20];
int a[1<<20];
int set[20];
int order[20];

void debug()
{
	for(int i=0;i<n;i++){
		cout<<p[i]<<" "<<w[i]<<endl;
	}
	for(int i=0;i<(1<<n);i++){
		cout<<a[i];
	}
}

void print()
{
	for(int i=0;i<n;i++){
		int j = order[i];
		cout<<p[j]<<" "<<w[j]<<endl;;
	}
}

bool check(int status)
{
	double sw = weight;
	double st = 0;
	for(int i=0;i<n;i++){
		if(status & (1<<i)){
			sw+=w[i];
			st+=w[i]*p[i];
		}
	}
	double x = st / sw;
	if( x<1.5 && x>-1.5 )return true;
	else return false;
}


bool isPossible(int status, int level)
{
	if(level==n){
		return true;
	}else{
		if(a[status])return false;
		a[status]++;
		for(int i=0;i<n;i++){
			if((status & (1<<i)) && check(status ^ (1<<i))){
				order[level]=i;
				if(isPossible(status^(1<<i),level+1))return true;
			}
		}
	}
	return false;
}


int main()
{
	int tc = 0;
	while(cin>>length>>weight>>n){
		if(length==0&&weight==0&&n==0)break;
		for(int i=0;i<n;i++){
			cin>>p[i]>>w[i];
		}		
		memset(a,0,sizeof(a));
		cout<<"Case "<<++tc<<":"<<endl;
		if(isPossible((1<<n)-1,0))
			print();
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}
