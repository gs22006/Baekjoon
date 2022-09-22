#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775807LL
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sp << " "
#define en << "\n"

ll n;
ll a[100010];
vector<ll> zip, vec[200010], su;
unordered_map<ll, ll> ZIP;
ll cc;
ll dp1[100010], dp2[100010], dp3[100010];
ll ans = MAX;

ll dist(ll X, ll Y)
{
	if(X > Y)
		Y += n;
	
	return Y - X;
}

ll L(ll X, ll Y)
{
	if(!Y)
		return vec[X][(ll)vec[X].size() - 1];
	
	return vec[X][Y - 1];
}

ll R(ll X, ll Y)
{
	if(Y == (ll)vec[X].size() - 1)
		return vec[X][0];
	
	return vec[X][Y + 1];
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		zip.push_back(a[i]);
	}
	
	sort(zip.begin(), zip.end());
	
	for(ll i = 0 ; i < (ll)zip.size() ; i++)
	{
		if(i && zip[i] == zip[i - 1])
			continue;
		
		ZIP[zip[i]] = ++cc;
		su.push_back(cc);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		a[i] = ZIP[a[i]];
		vec[a[i]].push_back(i);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		dp1[i] = dp2[i] = dp3[i] = INF;
	
	for(auto &i : vec[su[0]])
		dp1[i] = min(dist(1, i), dist(i, 1));
	
	for(ll i = 0 ; i < (ll)su.size() ; i++)
	{
		ll gap = su[i];
		ll minn = INF;
		
		for(ll j = 0 ; j < (ll)vec[gap].size() ; j++)
		{
			ll l = L(gap, j);
			ll r = R(gap, j);
			
			dp3[l] = min(dp3[l], dp1[vec[gap][j]] + dist(vec[gap][j], l));
			dp3[r] = min(dp3[r], dp1[vec[gap][j]] + dist(r, vec[gap][j]));
			dp2[l] = min(dp2[l], dp3[l]);
			dp2[r] = min(dp2[r], dp3[r]);
		}
		
		if(vec[gap].size() == 1)
			dp2[vec[gap][0]] = dp1[vec[gap][0]];
		
		for(ll j = 0 ; j < (ll)vec[gap].size() ; j++)
		{
			dp2[vec[gap][j]] = min(dp2[vec[gap][j]], minn + vec[gap][j]);
			minn = min(minn, dp3[vec[gap][j]] - vec[gap][j]);
		}
		
		for(ll j = 0 ; j < (ll)vec[gap].size() ; j++)
			dp2[vec[gap][j]] = min(dp2[vec[gap][j]], minn + vec[gap][j] + n);
		
		minn = INF;
		
		for(ll j = (ll)vec[gap].size() - 1 ; j >= 0 ; j--)
		{
			dp2[vec[gap][j]] = min(dp2[vec[gap][j]], minn - vec[gap][j]);
			minn = min(minn, dp3[vec[gap][j]] + vec[gap][j]);
		}
		
		for(ll j = (ll)vec[gap].size() - 1 ; j >= 0 ; j--)
			dp2[vec[gap][j]] = min(dp2[vec[gap][j]], minn - vec[gap][j] + n);
		
		if(i < (ll)su.size() - 1)
		{
			vector<ll> tmp;
			
			for(auto &j : vec[gap])
				tmp.push_back(j);
			
			for(auto &j : vec[su[i + 1]])
				tmp.push_back(j);
			
			sort(tmp.begin(), tmp.end());
			
			minn = INF;
			
			for(ll j = 0 ; j < (ll)tmp.size() ; j++)
			{
				if(a[tmp[j]] == su[i + 1])
					dp1[tmp[j]] = min(dp1[tmp[j]], minn + tmp[j]);
				else
					minn = min(minn, dp2[tmp[j]] - tmp[j]);
			}
			
			for(ll j = 0 ; j < (ll)tmp.size() ; j++)
			{
				if(a[tmp[j]] == su[i + 1])
					dp1[tmp[j]] = min(dp1[tmp[j]], minn + tmp[j] + n);
			}
			
			minn = INF;
			
			for(ll j = (ll)tmp.size() - 1 ; j >= 0 ; j--)
			{
				if(a[tmp[j]] == su[i + 1])
					dp1[tmp[j]] = min(dp1[tmp[j]], minn - tmp[j]);
				else
					minn = min(minn, dp2[tmp[j]] + tmp[j]);
			}
			
			for(ll j = (ll)tmp.size() - 1 ; j >= 0 ; j--)
			{
				if(a[tmp[j]] == su[i + 1])
					dp1[tmp[j]] = min(dp1[tmp[j]], minn - tmp[j] + n);
			}
		}
	}
	
	for(auto &i : vec[su.back()])
		ans = min(ans, dp2[i]);
	
	cout << ans;
	return 0;
}