#include <stdio.h>
#include <string.h>

char s[101];
char p[101];
char *c[5];

int main()
{
	int n;
	scanf("%d\n", &n);
	while (n--) {
		int a = 0;
		gets(s);
		c[a] = s;
		int l = strlen(s);
		for (int i = 0; i < l; i++) if (strchr("<>", s[i])) {
			c[++a] = s + i + 1;
			s[i] = 0;
		}
		printf("%s%s%s%s%s\n", c[0], c[1], c[2], c[3], c[4]);
		gets(p);
		p[strlen(p) - 3] = 0;
		printf("%s%s%s%s%s\n", p, c[3], c[2], c[1], c[4]);
	}
	return 0;
}
