#include <stdio.h>

const int c[6] = {0, 1, 5, 10, 25, 50};
int a[6][7500];

int main()
{
	a[0][0] = 1;
	for (int i = 1; i < 6; i++)
		for (int j = 0; j < 7500; j++)
			for (int k = 0; k <= j; k += c[i])
				a[i][j] += a[i - 1][j - k];
	while (scanf("%d", *a) == 1) printf("%d\n", a[5][**a]);
	return 0;
}
