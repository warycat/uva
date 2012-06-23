#include<iostream>
#include<cstdio>
#include<cctype>

using namespace std;

int main()
{
	char c;
	int p=0;
	while((c=getchar())!=EOF){
		if(c=='!'||c=='\n'){ 
			cout << endl;
		}else if(isdigit(c)){ 
			p += (c-'0');
		}else{
			if(c=='b') c = ' ';
			while(p){
				printf("%c",c);
				p--;
			}
		}
	}
	return 0;
}
