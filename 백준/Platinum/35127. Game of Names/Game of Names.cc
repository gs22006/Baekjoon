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

ll t;
ll n;
string a;

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		cin >> a;
		
		if(n == 1)
		{
			if(a[0] == '.')
				cout << "alice\n";
			else
				cout << "bob\n";
			
			continue;
		}
		
		string b;
		
		b = "d";
		b += a;
		b += 'd';
		a = b;
		
		ll A = 0, B = 0;
		ll TA = 0, TB = 0;
		ll S = 0, E = 0;
		ll last = 0;
		
		for(ll i = 1 ; i <= n + 1 ; i++)
		{
			if(a[i] == '.' && a[i - 1] != '.')
			{
				if(a[i - 1] == 'd')
					S = -1;
				else if(a[i - 1] == 'a')
					S = 1;
				else if(a[i - 1] == 'b')
					S = 2;
				
				last = i;
			}
			
			else if(a[i] != '.' && a[i - 1] == '.')
			{
				if(a[i] == 'd')
					E = -1;
				else if(a[i] == 'a')
					E = 1;
				else if(a[i] == 'b')
					E = 2;
				
				if(S == -1)
				{
					if(E == 1)
					{
						if(i - last != 1)
							TB++;
						else
							B++;
					}
					
					else if(E == 2)
					{
						if(i - last != 1)
							TA++;
						else
							A++;
					}
				}
				
				else if(S == 1)
				{
					if(E == -1)
					{
						if(i - last != 1)
							TB++;
						else
							B++;
					}
					
					else if(E == 1)
						B++;
				}
				
				else if(S == 2)
				{
					if(E == -1)
					{
						if(i - last != 1)
							TA++;
						else
							A++;
					}
					
					else if(E == 2)
						A++;
				}
			}
		}
		
		if(TA >= 2)
		{
			A++;
			TA = 0;
		}
		
		if(TB >= 2)
		{
			B++;
			TB = 0;
		}
		
		if(A < B)
			cout << "bob\n";
		else if(A > B)
			cout << "alice\n";
		
		else
		{
			if(TA > TB)
				cout << "alice\n";
			else
				cout << "bob\n";
		}
	}
	
	return 0;
}