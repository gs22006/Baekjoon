#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct sq1
{
    ll x, y;
    ll num;

    bool operator < (const sq1 &xx) const
    {
        return x < xx.x;
    }
};

struct sq2
{
    ll x, y;
    ll num;

    bool operator < (const sq2 &xx) const
    {
        return y < xx.y;
    }
};

ll n, r;
ll d;
ll all, bll;
pair<ll, ll> inp[200010];
sq1 a[200010];
sq2 b[200010];
ll gap[200010];
vector<ll> zip1, zip2;
unordered_map<ll, ll> zipx, zipy;
ll ccx, ccy;
vector<ll> vec[200010];
ll chk[200010];
queue<ll> q;
ll ans;
ll w;

struct segtree
{
    ll seg[2000010];

    void update(ll no, ll s, ll e, ll w, ll v)
    {
        if(w < s || e < w)
            return;

        if(s == e)
        {
            if(gap[seg[no]] < gap[v])
                seg[no] = v;

            return;
        }

        update(no * 2, s, (s + e) / 2, w, v);
        update(no * 2 + 1, (s + e) / 2 + 1, e, w, v);

        if(gap[seg[no * 2]] < gap[seg[no * 2 + 1]])
            seg[no] = seg[no * 2 + 1];
        else
            seg[no] = seg[no * 2];
    }

    ll query(ll no, ll s, ll e, ll l, ll r)
    {
        if(e < l || r < s)
            return 0;

        if(l <= s && e <= r)
            return seg[no];

        ll L = query(no * 2, s, (s + e) / 2, l, r);
        ll R = query(no * 2 + 1, (s + e) / 2 + 1, e, l, r);

        if(gap[L] < gap[R])
            return R;
        else
            return L;
    }
}segtx, segty;

int main(void)
{
    scanf("%lld %lld", &n, &r);

    for(ll i = 1 ; i <= n ; i++)
    {
        scanf("%lld %lld", &all, &bll);
        
        if(!all && !bll)
        	w = i;
        
        inp[i] = make_pair(all, bll);
        a[i].num = b[i].num = i;
        a[i].x = b[i].x = all;
        a[i].y = b[i].y = bll;
        zip1.push_back(all);
        zip1.push_back(all - r);
        zip1.push_back(all + r);
        zip2.push_back(bll);
        zip2.push_back(bll - r);
        zip2.push_back(bll + r);
    }

    scanf("%lld", &d);

    sort(zip1.begin(), zip1.end());
    sort(zip2.begin(), zip2.end());

    zipx[zip1[0]] = ++ccx;
    zipy[zip2[0]] = ++ccy;

    for(ll i = 1 ; i < zip1.size() ; i++)
    {
        if(zip1[i] != zip1[i - 1])
            zipx[zip1[i]] = ++ccx;
    }
    
    for(ll i = 1 ; i < zip2.size() ; i++)
    {
        if(zip2[i] != zip2[i - 1])
            zipy[zip2[i]] = ++ccy;
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);

    //ysort
    for(ll i = 1 ; i <= n ; i++)
        gap[i] = b[i].y + 1;

    for(ll i = 1 ; i <= n ; i++)
    {
        ll q1 = segtx.query(1, 0, ccx, zipx[b[i].x - r], zipx[b[i].x]);
        ll q2 = segtx.query(1, 0, ccx, zipx[b[i].x], zipx[b[i].x + r]);

        if(gap[i] - gap[q1] - r <= d && q1 != 0)
        {
            vec[b[i].num].push_back(b[q1].num);
            vec[b[q1].num].push_back(b[i].num);
        }

        if(gap[i] - gap[q2] - r <= d && q2 != 0)
        {
            vec[b[i].num].push_back(b[q2].num);
            vec[b[q2].num].push_back(b[i].num);
        }
        
        segtx.update(1, 0, ccx, zipx[b[i].x], i);
    }
    
    //xsort
    for(ll i = 1 ; i <= n ; i++)
        gap[i] = a[i].x + 1;

    for(ll i = 1 ; i <= n ; i++)
    {
        ll q1 = segty.query(1, 0, ccy, zipy[a[i].y - r], zipy[a[i].y]);
        ll q2 = segty.query(1, 0, ccy, zipy[a[i].y], zipy[a[i].y + r]);

        if(gap[i] - gap[q1] - r <= d && q1 != 0)
        {
            vec[a[i].num].push_back(a[q1].num);
            vec[a[q1].num].push_back(a[i].num);
        }

        if(gap[i] - gap[q2] - r <= d && q2 != 0)
        {
            vec[a[i].num].push_back(a[q2].num);
            vec[a[q2].num].push_back(a[i].num);
        }

        segty.update(1, 0, ccy, zipy[a[i].y], i);
    }
    
    q.push(w);
    chk[w] = 1;
    
    while(!q.empty())
    {
    	ll qq = q.front();
    	q.pop();
    	
    	ans = max(ans, inp[qq].first + inp[qq].second + 2 * r);
    	
    	for(ll i : vec[qq])
    	{
    		if(chk[i])
    			continue;
    		
    		q.push(i);
    		chk[i] = 1;
    	}
    }
    
    printf("%lld", ans);
    return 0;
}
