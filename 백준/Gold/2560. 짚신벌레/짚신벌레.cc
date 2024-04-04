#include <stdio.h>

long long bu[1011111], s[1011111], a, b, d, n;

int main(void)
{
	scanf("%lld %lld %lld %lld", &a, &b, &d, &n);
	
	s[0] = 1;
	s[d] = -1;
	bu[a] = 1;
	bu[b] = -1;
	
	for(int i = 1 ; i <= n ; i++) {
		
		bu[i] = bu[i] + bu[i - 1];
		bu[i] += 1000;
		bu[i] %= 1000;
		
		bu[i + a] = bu[i + a] + bu[i];
		bu[i + a] += 1000;
		bu[i + a] %= 1000;
		
		bu[i + b] = bu[i + b] - bu[i];
		bu[i + b] += 1000;
		bu[i + b] %= 1000;
		
		s[i + d] = s[i + d] - bu[i];
		s[i + d] += 1000;
		s[i + d] %= 1000;
		
		s[i] = s[i] + s[i - 1] + bu[i];
		s[i] += 1000;
		s[i] %= 1000;
	}
	
	s[n] += 1000;
	printf("%lld", s[n] % 1000);
}