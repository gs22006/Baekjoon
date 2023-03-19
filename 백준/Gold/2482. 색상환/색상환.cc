#include <bits/stdc++.h>

using namespace std;

int n, k;
long long d[1010][1010];

int main(void)
{
	scanf("%d %d", &n, &k);
	
	if(n / 2 < k)
	{
		printf("0");
		return 0;
	}
	
	d[0][0] = 1;
	
	for(int i = 1 ; i <= n - k + 1 ; i++)
	{
		for(int j = 0 ; j <= i ; j++)
			d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % 1000000003;
	}
	
	long long ans = (d[n - k + 1][k] - d[n - k - 1][k - 2]) % 1000000003;
	
	printf("%lld", ans < 0 ? ans + 1000000003 : ans);
	return 0;
}