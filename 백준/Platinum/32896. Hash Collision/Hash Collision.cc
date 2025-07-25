#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout << fixed; cout.precision(10);
#define sp << " "
#define en << "\n"
#define compress(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())

ll n;
ll chk[200010];

ll query(ll X, ll Y)
{
	printf("? %lld %lld\n", Y, X);
	fflush(stdout);
	
	ll ret = 0;
	
	scanf("%lld", &ret);
	
	return ret;
}

int main(void)
{
	scanf("%lld", &n);
	
	ll A = query(1, n);
	ll B = query(A, 1);
	
	if(A == B)
	{
		printf("! %lld %lld", A, A);
		fflush(stdout);
		
		return 0;
	}
	
	ll AA = A;
	ll cc = 0;
	ll cyc = -1;
	
	A = AA;
	chk[A] = ++cc;
	
	for(ll i = 1 ; i <= 449 ; i++)
	{
		A = query(A, 1);
		chk[A] = ++cc;
		
		if(A == AA)
		{
			cyc = i;
			break;
		}
	}
	
	if(cyc == -1)
	{
		A = AA;
		
		for(ll i = 1 ; i <= 450 ; i++)
		{
			A = query(A, 450);
			
			if(chk[A])
			{
				cyc = 450 * i - chk[A] + 1;
				break;
			}
		}
	}
	
	ll tm = AA % cyc;
	tm = cyc - tm;
	
	B = query(AA, tm);
	
	printf("! %lld %lld", AA, B);
	fflush(stdout);
	
	return 0;
}