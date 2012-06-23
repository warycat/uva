#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

bool try_sqrt(int v, int& n)
{
	n = round(sqrt(v));
	return n * n == v;
}

void put(int a, int b)
{
	static int c = 10;
	printf("%10d%10d\n", a, b);
	if (!--c) exit(0);
}

int main()
{
	int pb = 1;
	while (1) {
		pb += 2;
		int b = pb * pb;
		int t;
		if (try_sqrt(b - 1 >> 1, t)) put(t * pb, b - 1);
		if (try_sqrt(b + 1 >> 1, t)) put(t * pb, b);
	}
	return 0;
}
