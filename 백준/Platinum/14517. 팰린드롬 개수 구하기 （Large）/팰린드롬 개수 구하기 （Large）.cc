#include <bits/stdc++.h>

using namespace std;

char s[1010];
int dp[1010][1010];
int len;
int ss = 10007;
int ans;

int main(void)
{
	scanf("%s", s + 1);
	
	len = strlen(s + 1);
	
	for(int i = 1 ; i <= len ; i++)
	{
		for(int j = 1 ; j < i ; j++)
			dp[i][j] = dp[i - 1][j];
		
		for(int j = i ; j <= len ; j++)
		{
			dp[i][j] = dp[i - 1][j];
			
			if(s[i] == s[j])
			{
				dp[i][j]++;
				
				for(int k = j ; k < len ; k++)
					dp[i][j] = (dp[i][j] + dp[i - 1][k + 1]) % ss;
			}
		}
	}
	
	for(int i = 1 ; i <= len ; i++)
		ans += dp[len][i];
	
	printf("%d", ans % ss < 0 ? ans % ss + ss : ans % ss);
	return 0;
}