#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second

ll t;
char a[7010];
ll ans;
ll cccc;
ll dp[7010][7010][2];
char p1[10], p2[10];

int main(void)
{
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%s", a + 1);
		
		ll len = strlen(a + 1);
		ans = 987654321;
		
		for(ll i = 0 ; i <= len ; i++)
		{
			for(ll j = 0 ; j <= len ; j++)
				dp[i][j][0] = dp[i][j][1] = 987654321;
		}
		
		dp[1][1][0] = 1;
		dp[1][1][1] = 1;
		
		if(a[1] == 'A')
		{
			strcpy(p1, "ABC");
			strcpy(p2, "ACB");
		}
		
		else if(a[1] == 'B')
		{
			strcpy(p1, "BCA");
			strcpy(p2, "BAC");
		}
		
		else
		{
			strcpy(p1, "CAB");
			strcpy(p2, "CBA");
		}
		
		for(ll i = 1 ; i < len ; i++)
		{
			for(ll j = 1 ; j <= i ; j++)
			{
				if(p1[j % 3] == a[i + 1])
					dp[i + 1][j + 1][0] = min(dp[i + 1][j + 1][0], dp[i][j][0] + 1);
				
				if(p2[j % 3] == a[i + 1])
					dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][1] + 1);
				
				ll ff1 = 0, ff2 = 0;
				ll siz = min(j, 3);
				
				for(ll k = 0 ; k < siz ; k++)
				{
					if(p1[k] == a[i + 1])
						ff1 = 1;
					
					if(p2[k] == a[i + 1])
						ff2 = 1;
				}
				
				if(ff1)
				{
					ll gap = j;
					
					while(1)
					{
						if(p1[(gap + 2) % 3] == a[i + 1])
							break;
						
						gap--;
					}
					
					dp[i + 1][gap][0] = min(dp[i + 1][gap][0], dp[i][j][0] + j - gap);
					
					if(gap == 1)
						dp[i + 1][gap][1] = min(dp[i + 1][gap][1], dp[i][j][0] + j - gap);
				}
				
				if(ff2)
				{
					ll gap = j;
					
					while(1)
					{
						if(p2[(gap + 2) % 3] == a[i + 1])
							break;
						
						gap--;
					}
					
					dp[i + 1][gap][1] = min(dp[i + 1][gap][1], dp[i][j][1] + j - gap);
					
					if(gap == 1)
						dp[i + 1][gap][0] = min(dp[i + 1][gap][0], dp[i][j][1] + j - gap);
				}
			}
		}
		
		for(ll i = 0 ; i <= len ; i++)
			ans = min(ans, min(dp[len][i][0], dp[len][i][1]) + i + len);
		
		printf("Case #%d: %d\n", ++cccc, ans);
	}
	
	return 0;
}