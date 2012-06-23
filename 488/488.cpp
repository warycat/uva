#include <cstdio>
#include <iostream>

using namespace std;

void printWave(int h)
{
	int i;
	int j;
	for(i=1;i<=h;i++){
		for(j=0;j<i;j++)
			printf("%d",i);
		printf("\n");
	}
	for(i=h-1;i>=1;i--){
		for(j=0;j<i;j++)
			printf("%d",i);
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		int h;
		int f;
		scanf("%d%d",&h,&f);
		int j;
		if(i)printf("\n");
		for(j=0;j<f;j++) {
			if(j) printf("\n");
			printWave(h);
		}
	}
	return 0;
}


