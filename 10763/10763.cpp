#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

map<pair<int, int>, int> count;

void zero_count(int& a, int b, int &c)
{
	if (!a) ++c;
	if (!(a += b)) --c;
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n) {
		int c = 0;
		count.clear();
		while (n--) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (a > b) zero_count(count[make_pair(b, a)], -1, c);
			else zero_count(count[make_pair(a, b)], 1, c);
		}
		
		puts(c ? "NO" : "YES");
	}
	return 0;
}
