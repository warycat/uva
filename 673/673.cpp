#include <cstdlib>
#include <cstdio>
int t;
char s[128];
int main()
{
	int c;
	scanf("%d\n", &c);
	while ((c = getchar()) != EOF) {
		switch (c) {
			case '(':
			case '[':
				s[t++] = c;
				break;
			case ')':
			case ']':
				if (!t || abs(s[--t] - c) > 2) {
					while (getchar() != '\n');
					puts("No"), t = 0;
				}
				break;
			case '\n':
				if (t) puts("No"); else puts("Yes");
				t = 0;
		}
	}
}

