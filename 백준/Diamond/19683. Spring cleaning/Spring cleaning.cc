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

ll n, q;
ll all, bll;
vector<ll> vec[100010];
ll gaet[100010], leaf[100010];
ll cou, cc;
ll cou3;
ll dep[100010], siz[100010], p[100010], tp[100010], IN[100010];

struct lazysegtree
{
	ll seg[400010];
	ll lazy[400010];
	
	void prop(ll no, ll s, ll e)
	{
		if(!lazy[no])
			return;
		
		seg[no] = (e - s + 1) - seg[no];
		
		if(s != e)
		{
			lazy[no * 2] ^= lazy[no];
			lazy[no * 2 + 1] ^= lazy[no];
		}
		
		lazy[no] = 0;
	}
	
	void update(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			seg[no] = (e - s + 1) - seg[no];
			
			if(s != e)
			{
				lazy[no * 2] ^= 1;
				lazy[no * 2 + 1] ^= 1;
			}
			
			return;
		}
		
		update(no * 2, s, (s + e) / 2, l, r);
		update(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
		
		seg[no] = seg[no * 2] + seg[no * 2 + 1];
	}
	
	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no];
		
		return query(no * 2, s, (s + e) / 2, l, r) + query(no * 2 + 1, (s + e) / 2 + 1, e, l, r);
	}
}segt;

void dfs(ll here, ll pa)
{
	ll coco = 0;
	
	dep[here] = dep[pa] + 1;
	siz[here] = 1;
	p[here] = pa;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		coco++;
		dfs(i, here);
		
		siz[here] += siz[i];
		gaet[here] += gaet[i];
	}
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		if(siz[i] > siz[vec[here][0]])
			swap(i, vec[here][0]);
	}
	
	if(!coco)
	{
		gaet[here] = 1;
		leaf[here] = 1;
	}
}

void dfs2(ll here, ll pa)
{
	IN[here] = ++cc;
	
	for(auto &i : vec[here])
	{
		if(i == pa)
			continue;
		
		if(i == vec[here][0])
			tp[i] = tp[here];
		else
			tp[i] = i;
		
		dfs2(i, here);
	}
}

void update(ll X)
{
	while(tp[1] != tp[X])
	{
		ll TP = tp[X];
		
		segt.update(1, 1, cc, IN[TP], IN[X]);
		X = p[TP];
	}
	
	segt.update(1, 1, cc, IN[1], IN[X]);
}

int main(void)
{
	fastio
	
	cin >> n >> q;
	
	for(ll i = 1 ; i < n ; i++)
	{
		cin >> all >> bll;
		
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	dfs(1, 0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		gaet[i] = (gaet[i] + 1) & 1;
		cou += leaf[i];
	}
	
	cou3 = cou;
	
	if((ll)vec[1].size() == 1)
		cou3++;
	
	dfs2(1, 0);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(gaet[i])
			segt.update(1, 1, cc, IN[i], IN[i]);
	}
	
	while(q--)
	{
		vector<ll> tmp, tmp2;
		ll cou2 = cou, cou4 = cou3;
		ll ans = 0;
		
		cin >> all;
		
		cou4 += all;
		
		for(ll i = 0 ; i < all ; i++)
		{
			cin >> bll;
			tmp.push_back(bll);
		}
		
		sort(tmp.begin(), tmp.end());
		
		for(ll i = 0 ; i < all ; i++)
		{
			update(tmp[i]);
			
			if(i && tmp[i] == tmp[i - 1])
				continue;
			
			tmp2.push_back(tmp[i]);
		}
		
		for(auto &i : tmp2)
		{
			if(i == 1 && (ll)vec[1].size() == 1)
				cou4--;
			
			if(leaf[i])
			{
				update(i);
				cou2--;
				cou4--;
			}
		}
		
		if(!(cou4 & 1))
		{
			ans += all;
			ans += segt.query(1, 1, cc, 2, cc);
			ans += n - 1;
			
			cout << ans en;
		}
		
		else
			cout << -1 en;
		
		for(auto &i : tmp)
			update(i);
		
		for(auto &i : tmp2)
		{
			if(leaf[i])
				update(i);
		}
	}
	
	return 0;
}