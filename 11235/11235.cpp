#include <stdio.h>
#include <string.h>
#include <utility>
#include <algorithm>

const int MAX_N = 200000;

int l[2 * MAX_N];
int r[2 * MAX_N];
//int v[2 * MAX_N];
int c[2 * MAX_N];
int p[2 * MAX_N];

//using std::pair;
//using std::make_pair;
using std::max;
using std::min;
/*
pair<int, int> freq(int a, int b, int x = 0)
{
	if (a <= l[x] && b >= r[x]) return make_pair(c[x], v[x]);
	if (a > r[x] || b < l[x]) return make_pair(-1, 0);
	if (p[x] < 0) return make_pair(min(b, r[x]) - max(a, l[x]) + 1, v[x]);
	return r[p[x]] == r[x] ? freq(a, b, p[x]) : max(freq(a, b, p[x]), freq(a, b, p[x] + 1));
}
*/

int freq(int a, int b, int x = 0)
{
	if (a > r[x] || b < l[x]) return 0;
	if (a <= l[x] && b >= r[x]) return c[x];
	if (p[x] < 0) return min(b, r[x]) + 1 - max(a, l[x]);
	return r[p[x]] == r[x] ? freq(a, b, p[x]) : max(freq(a, b, p[x]), freq(a, b, p[x] + 1));
}

int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2) {
		memset(r, -1, sizeof(r));
		memset(c, 0, sizeof(c));
		if (n == 0) return 0;
		int count = 0, now = 0;
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			if (t == now) ++count;
			else {
				if (count)
					c[tot] = count,
					r[tot++] = i;
				l[tot] = i + 1;
				//v[tot] = 
				now = t;
				p[tot] = -1;
				count = 1;
			}
		}
		if (count)
			c[tot] = count,
			r[tot++] = n;
		int start = 1;
		while (start < tot) start <<= 1;
		int end = start + tot;
		memcpy(l + start, l, tot * sizeof(int));
		memcpy(r + start, r, tot * sizeof(int));
		memcpy(c + start, c, tot * sizeof(int));
		//memcpy(v + tot, v, tot * sizeof(int));
		memcpy(p + start, p, tot * sizeof(int));
		while (start) {
			for (int i = start; i < end; i += 2) {
				int j = (i + 1 == end) ? i : i + 1;
				p[i >> 1] = i;
				l[i >> 1] = l[i];
				r[i >> 1] = r[j];
				c[i >> 1] = max(c[i], c[j]);
				/*
				if (c[i] > c[j]) {
					v[i >> 1] = v[i];
					c[i >> 1] = c[i];
				} else {
					v[i >> 1] = v[j];
					c[i >> 1] = c[j];
				}*/
			}
			start >>= 1, end = end + 1 >> 1;
		}
		for (int i = 0; i < q; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", freq(a, b));
		}
	}
	return 0;
}