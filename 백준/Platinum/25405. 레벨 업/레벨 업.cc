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
ll m, k;
priority_queue<ll> pqA, pqC;
ll gap, gaet, cou;
ll hap;
vector<ll> ans;

pair<ll, ll> query(ll X, ll Y, ll Z, ll M)
{
	//cout << X sp << Y sp << Z sp << M en;
	
	M *= (k - (ll)pqA.size());
	
	if(Z - Y > M)
	{
		//cout << X sp << Y + M en;
		return {X, Y + M};
	}
	
	X++;
	M -= (Z - Y);
	X += M / Z;
	M %= Z;
	
	//cout << X sp << M en;
	return {X, M};
}

int main(void)
{
	fastio
	
	cin >> n;
	
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	
	cin >> m >> k;
	
	sort(a + 1, a + 1 + n);
	
	gap = a[k];
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i] < a[k])
			pqA.push(a[i]);
		else if(a[i] == a[k])
			cou++;
		
		else if(a[i] == a[k] + 1)
		{
			cou++;
			gaet++;
		}
		
		else
			pqC.push(-a[i]);
	}
	
	while(1)
	{
		if(pqA.empty() && pqC.empty())
			break;
		
		if(!m)
			break;
		
		ll gapA = -1, gapC = -1;
		
		if(!pqA.empty())
		{
			ll tmp = pqA.top();
			ll l = 0, r = 1000000000001;
			
			while(l + 1 < r)
			{
				ll mid = (l + r) / 2;
				pair<ll, ll> qry = query(gap, gaet, cou, mid);
				//cout << "@" << gap sp << gaet sp << cou sp << mid sp << hap sp << qry.fi sp << tmp en;
				
				if(tmp + mid + hap < qry.fi)
					l = mid;
				else
					r = mid;
			}
			
			gapA = r;
			
			if(tmp + hap == gap || tmp + hap == gap + 1)
				gapA = 0;
		}
		
		if(!pqC.empty())
		{
			ll tmp = -pqC.top();
			ll l = 0, r = 1000000000001;
			
			while(l + 1 < r)
			{
				ll mid = (l + r) / 2;
				pair<ll, ll> qry = query(gap, gaet, cou, mid);
				//cout << "*" << gap sp << gaet sp << cou sp << mid sp << qry.fi sp << tmp en;
				if(qry.fi + 1 < tmp)
					l = mid;
				else
					r = mid;
			}
			
			gapC = r;
			
			if(tmp == gap || tmp == gap + 1)
				gapC = 0;
		}
		
		//cout << m en;
		//cout << gap sp << gaet sp << cou sp << hap en;
		//cout << gapA sp << gapC en;
		
		if(gapA != -1 && gapC != -1)
		{
			if(gapA < gapC)
			{
				pair<ll, ll> qry = query(gap, gaet, cou, gapA);
				ll tmp = pqA.top();
				
				if(m >= gapA)
				{
					gap = qry.fi;
					gaet = qry.se;
					
					if(tmp + hap + gapA == gap + 1)
						gaet++;
					
					hap += gapA;
					m -= gapA;
					cou++;
					
					pqA.pop();
				}
				
				else
					break;
			}
			
			else
			{
				pair<ll, ll> qry = query(gap, gaet, cou, gapC);
				ll tmp = -pqC.top();
				
				if(m >= gapC)
				{
					gap = qry.fi;
					gaet = qry.se;
					
					if(tmp == gap + 1)
						gaet++;
					
					hap += gapC;
					m -= gapC;
					cou++;
					pqC.pop();
				}
				
				else
					break;
			}
		}
		
		else if(gapA != -1)
		{
			pair<ll, ll> qry = query(gap, gaet, cou, gapA);
			ll tmp = pqA.top();
			
			if(m >= gapA)
			{
				gap = qry.fi;
				gaet = qry.se;
				
				if(tmp + hap + gapA == gap + 1)
					gaet++;
				
				hap += gapA;
				m -= gapA;
				cou++;
				
				pqA.pop();
			}
			
			else
				break;
		}
		
		else
		{
			pair<ll, ll> qry = query(gap, gaet, cou, gapC);
			ll tmp = -pqC.top();
			
			if(m >= gapC)
			{
				gap = qry.fi;
				gaet = qry.se;
				
				if(tmp == gap + 1)
					gaet++;
				
				hap += gapC;
				m -= gapC;
				cou++;
				pqC.pop();
			}
			
			else
				break;
		}
	}
	//cout << gap sp << gaet sp << cou sp << hap sp en;
	
	if(m)
	{
		pair<ll, ll> qry = query(gap, gaet, cou, m);
		hap += m;
		gap = qry.fi;
		gaet = qry.se;
	}
	
	//cout << gap sp << gaet sp << cou sp << hap sp en;
	
	while(!pqA.empty())
	{
		ans.push_back(pqA.top() + hap);
		pqA.pop();
	}
	
	while(!pqC.empty())
	{
		ans.push_back(-pqC.top());
		pqC.pop();
	}
	
	for(ll i = 1 ; i <= cou - gaet ; i++)
		ans.push_back(gap);
	
	for(ll i = 1 ; i <= gaet ; i++)
		ans.push_back(gap + 1);
	
	sort(ans.begin(), ans.end());
	
	for(auto &i : ans)
		cout << i sp;
	
	return 0;
}