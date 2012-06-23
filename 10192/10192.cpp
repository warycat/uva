#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <algorithm>

using std::max;

char a[1001], b[1001];
int c[1001][1001];

#define lcs(i,j) ((i) < 0 || (j) < 0 ? 0 : c[i][j])

int main()
{
	int t = 0;
	while (true) {
		gets(a);
		if (a[0] == '#') break;
		gets(b);
		memset(c, 0, sizeof(c));
		int la = strlen(a), lb = strlen(b);
		for (int i = 0; i < la; ++i)
			for (int j = 0; j < lb; ++j) {
				if (a[i] == b[j]) c[i][j] = lcs(i - 1, j - 1) + 1;
				else c[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
			}
		printf("Case #%d: you can visit at most %d cities.\n", ++t, lcs(la - 1, lb - 1));
	}
	return 0;
}
