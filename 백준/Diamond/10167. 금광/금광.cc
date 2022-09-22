#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct xy
{
	ll x;
	ll y;
	ll c;
	
	bool operator < (const xy &xx) const
	{
		if(x == xx.x)
			return y < xx.y;
		
		return x < xx.x;
	}
};

ll n;
xy all[3010], a[3010];
vector<ll> xidx, yidx;
ll ans;

ll xgdx(ll xx)
{
	return lower_bound(xidx.begin(), xidx.end(), xx) - xidx.begin();
}

ll ygdx(ll yy)
{
	return lower_bound(yidx.begin(), yidx.end(), yy) - yidx.begin();
}

struct nod
{
	ll left;
	ll right;
	ll maxx;
	ll summ;
};

struct haptree
{
	nod seg[20010];
	
	nod update(ll no, ll s, ll e, ll w, ll v)
	{
		if(e < w || w < s)
			return seg[no];
		
		if(s == e && s == w)
		{
			seg[no].summ += v;
			seg[no].left += v;
			seg[no].right += v;
			seg[no].maxx += v;
			return seg[no];
		}
		
		ll mid = (s + e) / 2;
		nod lef = update(no * 2, s, mid, w, v);
		nod rig = update(no * 2 + 1, mid + 1, e, w, v);
		
		seg[no].summ = lef.summ + rig.summ;
		seg[no].left = max(lef.left, lef.summ + rig.left);
		seg[no].right = max(rig.right, rig.summ + lef.right);
		seg[no].maxx = max(lef.maxx, max(rig.maxx, lef.right + rig.left));
		return seg[no];
	}
	
	nod query(ll no, ll s, ll e, ll l, ll r)
	{
		if(e < l || r < s)
		{
			nod tmp;
			tmp.maxx = -987654321;
			tmp.left = -987654321;
			tmp.right = -987654321;
			tmp.summ = 0;
			return tmp;
		}
		
		if(l <= s && e <= r)
			return seg[no];
		
		ll mid = (s + e) / 2;
		nod lef = query(no * 2, s, mid, l, r);
		nod rig = query(no * 2 + 1, mid + 1, e, l, r);
		nod ret;
		
		ret.left = max(rig.left + lef.summ, lef.left);
		ret.right = max(rig.right, rig.summ + lef.right);
		ret.maxx = max(lef.maxx, max(rig.maxx, lef.right + rig.left));
		ret.summ = lef.summ + rig.summ;
		return ret;
	}
} ht;

int main(void)
{
	scanf("%lld", &n);
	
	for(ll i = 0 ; i < n ; i++)
	{
		scanf("%lld %lld %lld", &all[i].x, &all[i].y, &all[i].c);
		xidx.push_back(all[i].x);
		yidx.push_back(all[i].y);
	}
	
	sort(all, all + n);
	sort(xidx.begin(), xidx.end());
	sort(yidx.begin(), yidx.end());
	
	xidx.erase(unique(xidx.begin(), xidx.end()), xidx.end());
	yidx.erase(unique(yidx.begin(), yidx.end()), yidx.end());
	
	for(ll i = 0 ; i < n ; i++)
	{
		a[i].x = xgdx(all[i].x);
		a[i].y = ygdx(all[i].y);
		a[i].c = all[i].c;
	}
	
	sort(a, a + n);
	
	for(ll i = 0 ; i < n ; i++)
	{	
		for(ll j = 0 ; j < 20010 ; j++)
		{
			nod tmp;
			tmp.left = 0;
			tmp.maxx = 0;
			tmp.right = 0;
			tmp.summ = 0;
			ht.seg[j] = tmp;
		}
		
		ll here = i;
		
		for(ll j = i ; j < n ; j++)
		{
			if(j >= 1 && a[j].x == a[j - 1].x)
				continue;
			
			while(here < n && a[here].x == a[j].x)
			{
				ht.update(1, 0, 3010, a[here].y, a[here].c);
				here++;
			}
			
			ans = max(ans, ht.seg[1].maxx);
		}
	}
	
	printf("%lld", ans);
	return 0;
}