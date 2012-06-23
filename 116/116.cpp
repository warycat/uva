#include <cstdio>
#include <iostream>

int a[10][100], b[10][100], c[10][100];

using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		for (int i = 0; i < n; i++) b[i][m - 1] = a[i][m - 1];
		for (int i = m - 2; i >= 0 ; i--) {
			for (int j = 0; j < n; j++) {
				int y = 0x7FFFFFFF, z = 0;
				for (int x = j - 1 + n; x <= j + 1 + n; x++) {
					if (b[x % n][i + 1] < y) y = b[x % n][i + 1], z = x % n;
					else if (b[x % n][i + 1] == y && x % n < z) z = x % n;
				}
				b[j][i] = y + a[j][i];
				c[j][i] = z;
			}
		}
		int y = 0x7FFFFFFF, z = 0;
		for (int i = 0; i < n; i++) if (b[i][0] < y) y = b[i][0], z = i;
		for (int i = 0; i < m; i++) {
			if (i) putchar(' ');
			printf("%d", z + 1);
			z = c[z][i];
		}
		printf("\n%d\n", y);
	}
}
