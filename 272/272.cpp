#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;


int main()
{
	int c;
	int count=0;
	while((c=getchar())!=EOF){
		if(c=='"'){
			if(count%2==0)printf("``");
			else printf("''");
			count++;
		}else{
			printf("%c",c);
		}
	}
	return 0;
}
