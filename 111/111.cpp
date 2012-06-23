#include <stdio.h>

int t[21];
int a[20];
int b[20];
int g[20];

int main()
{
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x), t[i] = x;
	while (true) {
		for (int i = 0; i < n; i++)
			if (scanf("%d", a + i) != 1) return 0;
		for (int i = 0; i < n; i++) b[a[i] - 1] = t[i];
		for (int i = 0; i < n; i++) {
			int m = 0;
			for (int j = 0; j < i; j++)
				if (b[j] < b[i] && m < g[j]) m = g[j];
			g[i] = m + 1;
		}
		int m = 0;
		for (int j = 0; j < n; j++)
			if (m < g[j]) m = g[j];
		printf("%d\n", m);
	}
	return 0;
}
