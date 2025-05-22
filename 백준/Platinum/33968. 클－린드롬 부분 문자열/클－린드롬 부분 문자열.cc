#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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
char a[10010];
char b[10010];
ll P[10010];

int main(void)
{
fastio

cin >> n;

for(ll i = 1 ; i <= n ; i++)
	cin >> a[i];

for(ll L = 1 ; L <= n ; L++)
{
	vector< pair<pll, ll> > vec1, vec2;

	for(ll S = 1 ; S <= L ; S++)
	{
		ll cc = 0;

		for(ll i = S ; i <= n ; i += L)
		{
			P[cc] = 0;
			b[cc++] = a[i];
			P[cc] = 0;
			b[cc++] = '*';
		}

		b[cc - 1] = 0;
		cc--;

		ll R = 0, C = 0;

		for(ll i = 0 ; i < cc ; i++)
		{
			if(R < i)
				P[i] = 0;
			else
				P[i] = min(P[2 * C - i], R - i);

			while(i - P[i] - 1 >= 0 && i + P[i] + 1 < cc && b[i - P[i] - 1] == b[i + P[i] + 1])
				P[i]++;

			if(R < i + P[i])
			{
				R = i + P[i];
				C = i;
			}
		}

		for(ll i = 0 ; i < cc ; i++)
		{
			if(b[i] != '*')
				vec1.push_back({{i, S}, P[i] / 2});
			else
				vec2.push_back({{i, S}, (P[i] + 1) / 2});
		}
	}

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	ll sum = 0;

	if(L <= (ll)vec1.size())
	{
		priority_queue<ll> pq, epq;

		for(ll i = 0 ; i < L ; i++)
			pq.push(-vec1[i].se);

		sum += (-pq.top() + 1);

		for(ll i = L ; i < (ll)vec1.size() ; i++)
		{
			epq.push(-vec1[i - L].se);
			pq.push(-vec1[i].se);

			while(!pq.empty() && !epq.empty() && pq.top() == epq.top())
			{
				pq.pop();
				epq.pop();
			}

			sum += (-pq.top() + 1);
		}
	}

	if(L <= (ll)vec2.size())
	{
		priority_queue<ll> pq, epq;

		for(ll i = 0 ; i < L ; i++)
			pq.push(-vec2[i].se);

		sum += (-pq.top());

		for(ll i = L ; i < (ll)vec2.size() ; i++)
		{
			epq.push(-vec2[i - L].se);
			pq.push(-vec2[i].se);

			while(!pq.empty() && !epq.empty() && pq.top() == epq.top())
			{
				pq.pop();
				epq.pop();
			}

			sum += (-pq.top());
		}
	}

	cout << sum en;
}
return 0;
}