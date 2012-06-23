#include<iostream>
#include<cstdio>
using namespace std;
char vowels[]="AUEOI";
char consonant[]="JSBKTCLDMVNWFXGPYHQZR";
char a0[200];
char a1[200];
int n0,n1;
int n;
char name[256];
int cmp(const void *p, const void *q)
{
	return *(char *)p - *(char *)q;
}
int main()
{
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		int j;
		cin>>n;
		n0=n1=0;
		for(j=0;j<n;j++){
			if(j%2==0){
				a0[n0++]=vowels[n0/21];
			}else{
				a1[n1++]=consonant[n1/5];
			}
		}
		qsort(a0,n0,sizeof(char),cmp);
		qsort(a1,n1,sizeof(char),cmp);
		n0=n1=0;
		for(j=0;j<n;j++){
			if(j%2==0){
				name[j]=a0[n0++];
			}else{
				name[j]=a1[n1++];
			}
		}
		name[j]=0;
		printf("Case %d: %s\n",i+1,name);
	}
	return 0;
}
