#include <stdio.h>

int cycle_length(int n)
{
	int length=1;
	while (n!=1)
	{
		if (n%2==1) n=3*n+1;
		else n=n/2;
		length++;
	}
	return length;
}

int main()
{
	int n,i,j,k,max,oi,oj;

	while (scanf("%d %d",&i,&j)==2)
	{
		oi=i;oj=j;
		max=0;
		if (i>j) { k=i;i=j;j=k; } /* to make sure i<=j */
		for (n=i;n<=j;n++)
		{
			k=cycle_length(n);
			if (k>max) max=k;
		}
		printf("%d %d %d\n",oi,oj,max);
	}
	return 0;
}

