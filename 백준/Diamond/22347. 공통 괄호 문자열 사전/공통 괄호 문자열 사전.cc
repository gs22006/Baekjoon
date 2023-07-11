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
char a[4000010], b[4000010];
char s[4000010];
ll rnk[4000010], SA[4000010];
ll tmp[4000010], LCP[4000010], LCP2[4000010];
ll K;
ll lena, lenb, lens;
ll twoo;
ll mlen[4000010], L[4000010];
ll h[4000010];
vector<ll> vec[4000010];
ll L2[4000010];

bool comp(ll X, ll Y)
{
	if(rnk[X] != rnk[Y])
		return rnk[X] < rnk[Y];
	
	if(X + twoo >= lens && Y + twoo >= lens)
		return X > Y;
	
	return rnk[X + twoo] < rnk[Y + twoo];
}

void SuffixArray(void)
{
	for(ll i = 0 ; i < lens ; i++)
	{
		rnk[i] = s[i] - '$';
		SA[i] = i;
	}
	
	for(twoo = 1 ; ; twoo <<= 1)
	{
		sort(SA, SA + lens, comp);
		
		ll cc = 0;
		
		tmp[SA[0]] = 0;
		
		for(ll i = 1 ; i < lens ; i++)
		{
			if(comp(SA[i - 1], SA[i]))
				cc++;
			
			tmp[SA[i]] = cc;
		}
		
		for(ll i = 0 ; i < lens ; i++)
			rnk[i] = tmp[i];
		
		if(cc == lens - 1)
			break;
	}
}

void LCPArray(void)
{
	for(ll i = 0 ; i < lens ; i++)
		tmp[SA[i]] = i;
	
	ll last = 0;
	
	for(ll i = 0 ; i < lens ; i++, last = max(0LL, last - 1))
	{
		if(tmp[i] == lens - 1)
		{
			LCP[i] = -1;
			continue;
		}
		
		ll w1 = i;
		ll w2 = SA[tmp[i] + 1];
		
		for(ll j = last ; ; j++)
		{
			if(w1 + j >= lens || w2 + j >= lens)
				break;
			
			if(s[w1 + j] == s[w2 + j])
				last++;
			else
				break;
		}
		
		LCP[i] = last;
	}
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b >> K;
		
		lena = strlen(a);
		lenb = strlen(b);
		lens = 0;
		
		for(ll i = 0 ; i < lena ; i++)
			s[lens++] = a[i];
		
		s[lens++] = '$';
		
		for(ll i = 0 ; i < lenb ; i++)
			s[lens++] = b[i];
		
		for(ll i = 0 ; i <= lens ; i++)
			vec[i].clear();
		
		for(ll i = 0 ; i <= lens ; i++)
			rnk[i] = tmp[i] = SA[i] = LCP[i] = LCP2[i] = L[i] = h[i] = mlen[i] = L2[i] = 0;
		
		SuffixArray(); // N log^2 N
		LCPArray();
		ll gap = -INF;
		ll las = -1;
		
		for(ll i = 0 ; i < lens ; i++)
		{
			if(SA[i] < lena)
				gap = LCP[SA[i]];
			
			else if(lens - SA[i] <= lenb)
			{
				mlen[SA[i]] = gap;
				gap = min(gap, LCP[SA[i]]);
			}
		}
		
		gap = -INF;
		
		for(ll i = lens - 1 ; i >= 0 ; i--)
		{
			if(SA[i] < lena && i)
				gap = LCP[SA[i - 1]];
			
			else if(lens - SA[i] <= lenb)
			{
				mlen[SA[i]] = max(mlen[SA[i]], gap);
				
				if(i)
					gap = min(gap, LCP[SA[i - 1]]);
			}
		}
		
		ll ls = -1;
		
		for(ll i = 0 ; i < lens ; i++)
		{
			if(lens - SA[i] <= lenb)
			{
				LCP2[lenb - lens + SA[i] + 1] = ls;
				ls = LCP[SA[i]];
			}
			
			else
				ls = min(ls, LCP[SA[i]]);
		}
		
		for(ll i = 0 ; i < lens ; i++)
		{
			if(lens - SA[i] <= lenb)
				L[lenb - lens + SA[i] + 1] = mlen[SA[i]];
		}
		
		for(ll i = 1 ; i <= lenb ; i++)
		{
			if(b[i - 1] == '(')
				h[i] = h[i - 1] + 1;
			else
				h[i] = h[i - 1] - 1;
		}
		
		ll minn = 0;
		
		for(ll i = 0 ; i <= lenb ; i++)
			minn = min(minn, h[i]);
		
		stack<ll> stk;
		
		for(ll i = lenb ; i >= 0 ; i--)
		{
			while(!stk.empty() && h[stk.top()] >= h[i])
				stk.pop();
			
			if(stk.empty())
				L2[i] = INF;
			else
				L2[i] = stk.top() - 1;
			
			stk.push(i);
		}
		
		for(ll i = 0 ; i <= lenb ; i++)
			h[i] -= minn;
		
		for(ll i = 0 ; i <= lenb ; i++)
			vec[h[i]].push_back(i - 1);
		
		for(ll i = 0 ; i < lens ; i++)
		{
			if(lens - SA[i] <= lenb)
			{
				ll w = lenb - lens + SA[i] + 1;
				ll H = h[w - 1];
				ll R = min(w + L[w] - 2, L2[w - 1]);
				ll R2 = min(w + LCP2[w] - 2, L2[w - 1]);
				
				ll idx1 = upper_bound(vec[H].begin(), vec[H].end(), w - 1) - vec[H].begin();
				ll idx2 = upper_bound(vec[H].begin(), vec[H].end(), R) - vec[H].begin();
				
				if(!idx2)
					continue;
				
				ll idx3 = upper_bound(vec[H].begin(), vec[H].end(), R2) - vec[H].begin();
				
				if(!max(idx1, idx3))
					continue;
				
				idx1--;
				idx2--;
				idx3--;
				
				if(max(idx1, idx3) > idx2)
					continue;
				
				if(K > idx2 - max(idx1, idx3))
				{
					K -= (idx2 - max(idx1, idx3));
					continue;
				}
				
				for(ll i = max(idx1, idx3) + 1 ; i <= idx2 ; i++)
				{
					K--;
					
					if(!K)
					{
						for(ll j = vec[H][idx1] + 1 ; j <= vec[H][i] ; j++)
							cout << b[j];
						
						cout en;		
						break;
					}
				}
				
				if(!K)
					break;
			}
		}
		
		if(K)
			cout << -1 en;
	}
	
	return 0;
}