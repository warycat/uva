#include <iostream>
#include <bitset>
#include <cstdio>

using namespace std;

bitset<32> m[32];

void set(int x, int y, int s)
{
	char c;
	cin >> c;
	switch (c) {
		case 'p':
			set(x + s, y, s >>= 1);
			set(x, y, s);
			set(x, y + s, s);
			set(x + s, y + s, s);
			break;
		case 'f':
			for (int i = 0; i < s; i++)
				for (int j = 0; j < s; j++)
					m[x + i].set(y + j);
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--) {
		for (int i = 0; i < 32; i++) m[i].reset();
		set(0, 0, 32);
		set(0, 0, 32);
		int ans = 0;
		for (int i = 0; i < 32; i++) ans += m[i].count();
		printf("There are %d black pixels.\n", ans);
	}
}
