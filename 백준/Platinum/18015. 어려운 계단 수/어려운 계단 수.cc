#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, b;
ll ss = 1000000000;
ll dp1[2010][2010], dp2[2010][2010], dp3[2010][2010], dp4[2010][2010];
ll on, tw, th, fo;

int main(void)
{
	scanf("%lld %lld", &n, &b);
	
	for(int i = 1 ; i <= b - 1 ; i++)
		dp1[i][1] = 1;
	
	for(int i = 2 ; i <= n ; i++)
	{
		dp1[0][i] = dp1[1][i - 1];
		dp1[b - 1][i] = dp1[b - 2][i - 1];
		
		for(int j = 1 ; j <= b - 2 ; j++)
			dp1[j][i] = (dp1[j - 1][i - 1] + dp1[j + 1][i - 1]) % ss;
	}
	
	for(int i = 1 ; i <= b - 1 ; i++)
		dp2[i][1] = 1;
	
	for(int i = 2 ; i <= n ; i++)
	{
		dp2[1][i] = dp2[2][i - 1];
		dp2[b - 1][i] = dp2[b - 2][i - 1];
		
		for(int j = 2 ; j <= b - 2 ; j++)
			dp2[j][i] = (dp2[j - 1][i - 1] + dp2[j + 1][i - 1]) % ss;
	}
	
	for(int i = 1 ; i <= b - 2 ; i++)
		dp3[i][1] = 1;
	
	for(int i = 2 ; i <= n ; i++)
	{
		dp3[0][i] = dp3[1][i - 1];
		
		if(b != 2)
			dp3[b - 2][i] = dp3[b - 3][i - 1];
		
		for(int j = 1 ; j <= ((b - 3) < 0 ? 0 : (b - 3)) ; j++)
			dp3[j][i] = (dp3[j - 1][i - 1] + dp3[j + 1][i - 1]) % ss;
	}
	
	for(int i = 1 ; i <= b - 2 ; i++)
		dp4[i][1] = 1;
	
	for(int i = 2 ; i <= n ; i++)
	{
		dp4[1][i] = dp4[2][i - 1];
		
		if(b != 2)
			dp4[b - 2][i] = dp4[b - 3][i - 1];
		
		for(int j = 2 ; j <= ((b - 3) < 0 ? 0 : (b - 3)) ; j++)
			dp4[j][i] = (dp4[j - 1][i - 1] + dp4[j + 1][i - 1]) % ss;
	}
	
	for(int i = 0 ; i <= b - 1 ; i++)
	{
		on = (on + dp1[i][n]) % ss;
		tw = (tw + dp2[i][n]) % ss;
		th = (th + dp3[i][n]) % ss;
		fo = (fo + dp4[i][n]) % ss;
	}
	
	ll ans = (on - tw - th + fo) % ss;
	
	printf("%lld", ans % ss < 0 ? ans % ss + ss : ans % ss);
	return 0;
}