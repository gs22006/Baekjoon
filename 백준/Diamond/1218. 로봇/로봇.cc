#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef double ld;
#define MAX 5000000000000000000LL
#define MIN -5000000000000000000LL

ll maxx;

struct maxlazysegtree
{
	ll seg[8000050];
	ll lazy[8000050];

	void init(void)
	{
		for(ll i = 0 ; i < 160050 ; i++)
		{
			seg[i] = MIN;
			lazy[i] = MIN;
		}
	}

	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		if(lazy[no] != MIN)
		{
			seg[no] = max(seg[no], lazy[no]);

			if(s != e)
			{
				lazy[no * 2] = max(lazy[no * 2], lazy[no]);
				lazy[no * 2 + 1] = max(lazy[no * 2 + 1], lazy[no]);
			}

			lazy[no] = MIN;
		}

		if(l > e || r < s)
			return;

		if(l <= s && e <= r)
		{
			seg[no] = max(seg[no], v);

			if(s != e)
			{
				lazy[no * 2] = max(lazy[no * 2], v);
				lazy[no * 2 + 1] = max(lazy[no * 2 + 1], v);
			}

			return;
		}

		update(no * 2, s, (s + e) / 2, l, r, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);

		seg[no] = max(seg[no * 2], seg[no * 2 + 1]);
	}

	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(lazy[no] != MIN)
		{
			seg[no] = max(seg[no], lazy[no]);

			if(s != e)
			{
				lazy[no * 2] = max(lazy[no * 2], lazy[no]);
				lazy[no * 2 + 1] = max(lazy[no * 2 + 1], lazy[no]);
			}

			lazy[no] = MIN;
		}

		if(l > e || r < s)
			return MIN;

		if(l <= s && e <= r)
			return seg[no];

		ll mid = (s + e) / 2;
		ll lef = query(no * 2, s, mid, l, r);
		ll rig = query(no * 2 + 1, mid + 1, e, l, r);

		return max(lef, rig);
	}

	void rec_init(void)
	{
		for(ll i = 0 ; i < 8000050 ; i++)
		{
			seg[i] = 0;
			lazy[i] = 0;
		}
	}

	void rec_update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		if(l > e || r < s)
			return;

		if(l <= s && e <= r)
			lazy[no] += v;

		else
		{
			rec_update(no * 2, s, (s + e) / 2, l, r, v);
			rec_update(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		}

		if(!lazy[no])
		{
			if(s != e)
				seg[no] = seg[no * 2] + seg[no * 2 + 1];
			else
				seg[no] = 0;
		}

		else
			seg[no] = e - s + 1;
	}
}maxlst;

struct minlazysegtree
{
	ll seg[160050];
	ll lazy[160050];

	void init(void)
	{
		for(ll i = 0 ; i < 160050 ; i++)
		{
			seg[i] = MAX;
			lazy[i] = MAX;
		}
	}

	void update(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		if(lazy[no] != MAX)
		{
			seg[no] = min(seg[no], lazy[no]);

			if(s != e)
			{
				lazy[no * 2] = min(lazy[no * 2], lazy[no]);
				lazy[no * 2 + 1] = min(lazy[no * 2 + 1], lazy[no]);
			}

			lazy[no] = MAX;
		}

		if(l > e || r < s)
			return;

		if(l <= s && e <= r)
		{
			seg[no] = min(seg[no], v);

			if(s != e)
			{
				lazy[no * 2] = min(lazy[no * 2], v);
				lazy[no * 2 + 1] = min(lazy[no * 2 + 1], v);
			}

			return;
		}

		update(no * 2, s, (s + e) / 2, l, r, v);
		update(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);

		seg[no] = min(seg[no * 2], seg[no * 2 + 1]);
	}

	ll query(ll no, ll s, ll e, ll l, ll r)
	{
		if(lazy[no] != MAX)
		{
			seg[no] = min(seg[no], lazy[no]);

			if(s != e)
			{
				lazy[no * 2] = min(lazy[no * 2], lazy[no]);
				lazy[no * 2 + 1] = min(lazy[no * 2 + 1], lazy[no]);
			}

			lazy[no] = MAX;
		}

		if(l > e || r < s)
			return MAX;

		if(l <= s && e <= r)
			return seg[no];

		ll mid = (s + e) / 2;
		ll lef = query(no * 2, s, mid, l, r);
		ll rig = query(no * 2 + 1, mid + 1, e, l, r);

		return min(lef, rig);
	}
}minlst;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct rect
{
	ll x0, y0, x1, y1;
};

ll n;
pair<ll, ll> a[20010], b[20010];
long long S;
pair<ll, ll> QUERY[10];
vector<rect> vec;
vector< pair<ll, ll> > ver;
vector<ll> zip;
unordered_map<ll, ll> zipres, zipwon;

long long get_area(void)
{
	long long ret = 0;
	ll las = 0;

	maxlst.rec_init();

	for(ll i = 0 ; i < vec.size() ; i++)
	{
		ver.push_back(make_pair(vec[i].x0, (i + 1)));
		ver.push_back(make_pair(vec[i].x1, -(i + 1)));
	}

	sort(ver.begin(), ver.end());

	for(ll i = 0 ; i < ver.size() ; i++)
	{
		if(i)
			ret += (long long)(ver[i].first - ver[i - 1].first) * maxlst.seg[1];

		if(ver[i].second > 0)
		{
			ll w = ver[i].second - 1;
			maxlst.rec_update(1, 0, 2000010, vec[w].y0, vec[w].y1 - 1, 1);
		}

		else
		{
			ll w = -ver[i].second - 1;
			maxlst.rec_update(1, 0, 2000010, vec[w].y0, vec[w].y1 - 1, -1);
		}
	}

	return ret;
}

ll f(ll x, ll y)
{
	ll U = MAX, D = MIN;
	//printf("wow\n");

	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].second == a[i + 1].second)
		{
			ll L = min(a[i].first, a[i + 1].first);
			ll R = max(a[i].first, a[i + 1].first);

			if(L < x && x < R)
			{
				if(a[i].second >= y)
					U = min(U, a[i].second);
				if(a[i].second <= y)
					D = max(D, a[i].second);
			}
		}
	}
	//printf("wow\n");

	maxlst.init();
	minlst.init();

	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].first == a[i + 1].first)
		{
			ll L = min(a[i].second, a[i + 1].second);
			ll R = max(a[i].second, a[i + 1].second);

			if(a[i].first <= x)
				maxlst.update(1, 0, 40011, L, R - 1, a[i].first);
			if(a[i].first >= x)
				minlst.update(1, 0, 40011, L, R - 1, a[i].first);
		}
	}
	//printf("wow\n");
	//printf("%lld %lld\n", U, D);
	rect tmp = {maxlst.query(1, 0, 40011, U - 1, U - 1), U - 1, minlst.query(1, 0, 40011, U - 1, U - 1), U};

	for(ll i = U - 1 ; i >= D ; i--)
	{
		if(tmp.x0 != maxlst.query(1, 0, 40011, i, i) || tmp.x1 != minlst.query(1, 0, 40011, i, i))
		{
			tmp.y0 = i + 1;
			vec.push_back({zipwon[tmp.x0], zipwon[tmp.y0], zipwon[tmp.x1], zipwon[tmp.y1]});
			tmp = {maxlst.query(1, 0, 40011, i, i), i, minlst.query(1, 0, 40011, i, i), i + 1};
		}
	}
	//printf("wow\n");

	tmp.y0 = D;
	vec.push_back({zipwon[tmp.x0], zipwon[tmp.y0], zipwon[tmp.x1], zipwon[tmp.y1]});

	ll LL = MIN, RR = MAX;

	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].first == a[i + 1].first)
		{
			ll UU = min(a[i].second, a[i + 1].second);
			ll DD = max(a[i].second, a[i + 1].second);

			//printf("%lld %lld\n%lld\n", UU, DD, a[i].first);

			if(UU < y && y < DD)
			{
				if(a[i].first <= x)
					LL = max(LL, a[i].first);
				if(a[i].first >= x)
					RR = min(RR, a[i].first);
			}
		}
	}
	//printf("wow\n");
	//printf("%lld %lld %lld %lld\n", LL, RR, zipwon[LL], zipwon[RR]);
	maxlst.init();
	minlst.init();

	for(ll i = 1 ; i <= n ; i++)
	{
		if(a[i].second == a[i + 1].second)
		{
			ll UU = min(a[i].first, a[i + 1].first);
			ll DD = max(a[i].first, a[i + 1].first);

			if(a[i].second >= y)
				minlst.update(1, 0, 40011, UU, DD - 1, a[i].second);
			if(a[i].second <= y)
				maxlst.update(1, 0, 40011, UU, DD - 1, a[i].second);
		}
	}
	//printf("wow\n");

	tmp = {LL, maxlst.query(1, 0, 40011, LL, LL), LL + 1, minlst.query(1, 0, 40011, LL, LL)};

	for(ll i = LL ; i < RR ; i++)
	{
	    //printf("%lld %lld\n", maxlst.query(1, 0, 40001, i, i), minlst.query(1, 0, 40001, i, i));
		if(tmp.y0 != maxlst.query(1, 0, 40011, i, i) || tmp.y1 != minlst.query(1, 0, 40011, i, i))
		{
			tmp.x1 = i;
			vec.push_back({zipwon[tmp.x0], zipwon[tmp.y0], zipwon[tmp.x1], zipwon[tmp.y1]});
			tmp = {i, maxlst.query(1, 0, 40011, i, i), i + 1, minlst.query(1, 0, 40011, i, i)};
		}
	}
	//printf("wow\n");

	//printf("alive");
	tmp.x1 = RR;
	vec.push_back({zipwon[tmp.x0], zipwon[tmp.y0], zipwon[tmp.x1], zipwon[tmp.y1]});
	//printf("wow\n");

	//printf("alive");
	//for(auto i : vec)
    //    printf("%lld %lld %lld %lld\n", i.x0, i.y0, i.x1, i.y1);

	if(get_area() != S)
		return 0;
	else
		return 1;
}

int main(void)
{
	scanf("%d", &n);

	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%d %d", &b[i].first, &b[i].second);

		b[i].first++;
		b[i].second++;
		b[i].first *= 2;
		b[i].second *= 2;

		maxx = max(maxx, max(b[i].first, b[i].second));
	}

	for(ll i = 1 ; i <= 5 ; i++)
    {
        scanf("%d %d", &QUERY[i].first, &QUERY[i].second);

        QUERY[i].first++;
        QUERY[i].second++;
        QUERY[i].first *= 2;
        QUERY[i].second *= 2;

        zip.push_back(QUERY[i].first);
        zip.push_back(QUERY[i].second);
    }

	b[n + 1] = b[1];

	for(ll i = 1 ; i <= n ; i++)
    {
        if(b[i].first == b[i + 1].first)
        {
            if(b[i].second < b[i + 1].second)
            {
                //UP
                b[i].first++;

                if(i < n)
                    b[i + 1].first++;
                else
                    b[1].first++;
            }

            else
            {
                //DOWN
                b[i].first--;

                if(i < n)
                    b[i + 1].first--;
                else
                    b[1].first--;
            }
        }

        else
        {
            if(b[i].first < b[i + 1].first)
            {
                b[i].second--;

                if(i < n)
                    b[i + 1].second--;
                else
                    b[1].second--;
            }

            else
            {
                b[i].second++;

                if(i < n)
                    b[i + 1].second++;
                else
                    b[1].second++;
            }
        }
    }

    b[n + 1] = b[1];

	for(ll i = 1 ; i <= n ; i++)
	{
	    //printf("*%lld %lld\n", b[i].first, b[i].second);
		S += (long long)b[i].first * b[i + 1].second;
		S -= (long long)b[i].second * b[i + 1].first;
	}

	S = abs(S) / 2LL;

	for(ll i = 1 ; i <= n ; i++)
    {
        zip.push_back(b[i].first);
        zip.push_back(b[i].second);
    }

	sort(zip.begin(), zip.end());

	ll cocou = 0;

	zip.push_back(MAX);

	for(ll i = 1 ; i < zip.size() ; i++)
    {
        if(zip[i] != zip[i - 1])
        {
            zipres[zip[i - 1]] = ++cocou;
            zipwon[cocou] = zip[i - 1];
        }
    }

	for(ll i = 1 ; i <= n ; i++)
    {
        a[i] = make_pair(zipres[b[i].first], zipres[b[i].second]);
        //printf("%lld %lld %lld %lld\n", a[i].first, a[i].second, b[i].first, b[i].second);
    }

    a[n + 1] = a[1];

	for(ll i = 1 ; i <= 5 ; i++)
	{
		vec.clear();
		ver.clear();
		//printf("%lld %lld\n", zipres[QUERY[i].first], zipres[QUERY[i].second]);
		printf("%s\n", f(zipres[QUERY[i].first], zipres[QUERY[i].second]) ? "YES" : "NO");
	}

	return 0;
}
