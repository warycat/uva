#include<cstdio>
#include<cctype>

int main()
{
	int c;
	int count = 0;
	int status = 0;
	while((c=getchar())!=EOF){
		if(c=='\n'){
			printf("%d\n",count+status);
			status = 0;
			count = 0;
		}else if(isalpha(c)){
			status = 1;
		}else{
			count += status;
			status = 0;
		}
	}
	return 0;
}

