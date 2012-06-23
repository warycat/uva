#include <stdio.h>

void check(double &d)
{
	int c = getchar();
	if (c == 'm') d /= 1000;
	else if (c == 'M') d *= 1000000;
	else if (c == 'k') d *= 1000;
	else return;
	getchar();
}

int main()
{
	int n;
	scanf("%d\n", &n);
	int k = 0;
	while (n--) {
		printf("Problem #%d\n", ++k);
		int x = 0;
		int cp, c;
		double p, i, u;
		for (; (c = getchar()) != '\n'; cp = c) {
			if (c == '=') {
				switch (cp) {
					case 'P':
						scanf("%lf", &p);
						x |= 1;
						check(p);
						break;
					case 'I':
						scanf("%lf", &i);
						x |= 2;
						check(i);
						break;
					case 'U':
						scanf("%lf", &u);
						x |= 4;
						check(u);
						break;
				}
			}
		}
		switch (~x & 7) {
			case 1:
				printf("P=%.2lfW\n\n", u * i);
				break;
			case 2:
				printf("I=%.2lfA\n\n", p / u);
				break;
			case 4:
				printf("U=%.2lfV\n\n", p / i);
				break;
		}
	}
	return 0;
}
