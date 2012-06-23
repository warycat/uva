#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct room
{
	int e;
	int n;
	int *l;
	int m;
	bool p;
} r[101];
int n;

#define INF INT_MAX
bool dfs(int p = 1, int l = 100)
{
	if (l != INF) l += r[p].e;
	if (r[p].m >= l) return false;
	if (p == n) return true;
	if (r[p].p) l = INF;
	r[p].p = true;
	r[p].m = l;
	for (int i = 0; i < r[p].n; i++)
		if (dfs(r[p].l[i], l)) return true;
	return false;
}

int main()
{
#ifdef DEBUG
	freopen("10557.in", "r", stdin);
#endif	
	while (scanf("%d", &n) && n != -1) {
		memset(r, 0, sizeof(r));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &r[i].e, &r[i].n);
			r[i].l = (int*)malloc(sizeof(*r[i].l) * r[i].n);
			for (int j = 0; j < r[i].n; j++)
				scanf("%d", r[i].l + j);
		}
		puts(dfs() ? "winnable" : "hopeless");
		for (int i = 1; i <= n; i++) free(r[i].l);
	}
	
}
