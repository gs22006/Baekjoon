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
 
inline int readChar();
template<class T = int> inline T readInt();
template<class T> inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);
static const int buf_size = 1 << 18;
inline int getChar(){
    #ifndef LOCAL
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if(pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
    if(pos == len) return -1;
    return buf[pos++];
    #endif
}
inline int readChar(){
    #ifndef LOCAL
    int c = getChar();
    while(c <= 32) c = getChar();
    return c;
    #else
    char c; cin >> c; return c;
    #endif
}
template <class T>
inline T readInt(){
    #ifndef LOCAL
    int s = 1, c = readChar();
    T x = 0;
    if(c == '-') s = -1, c = getChar();
    while('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
    #else
    T x; cin >> x; return x;
    #endif
}
static int write_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x){
    if(write_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
template <class T>
inline void writeInt(T x, char end){
    if(x < 0) writeChar('-'), x = -x;
    char s[24]; int n = 0;
    while(x || !n) s[n++] = '0' + x % 10, x /= 10;
    while(n--) writeChar(s[n]);
    if(end) writeChar(end);
}
inline void writeWord(const char *s){
    while(*s) writeChar(*s++);
}
struct Flusher{
    ~Flusher(){ if(write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0; }
}flusher;
 
struct edge
{
	ll u, v, cost;
	
	bool operator < (const edge &xx) const
	{
		return cost < xx.cost;
	}
};
 
ll n, m, K;
ll all, bll, cll;
vector<edge> edg;
vector< pair<pll, ll> > mst[3];
set< pair<pll, ll> > st;
pll ne[100010];
ll a[100010];
ll p[100010], ra[100010];
vector<ll> V;
vector<pll> vec[30];
ll sum[100010];
ll siz;
ll grp[100010];
ll chk[30], last[30], len[30];
ll dp[30];
ll ans;
ll dep[30];
ll dist[30][30];
ll cc;
 
ll ffind(ll here)
{
	if(here == p[here])
		return here;
	
	return p[here] = ffind(p[here]);
}
 
void uunion(ll X, ll Y)
{
	X = ffind(X);
	Y = ffind(Y);
	
	if(X == Y)
		return;
	
	if(ra[X] < ra[Y])
		p[X] = Y;
	else if(ra[X] > ra[Y])
		p[Y] = X;
	
	else
	{
		p[X] = Y;
		ra[Y]++;
	}
}
 
void MST(ll num)
{
	for(ll i = 1 ; i <= n ; i++)
		p[i] = i, ra[i] = 0;
	
	sort(edg.begin(), edg.end());
	
	for(auto &i : edg)
	{
		if(ffind(i.u) == ffind(i.v))
			continue;
		
		uunion(i.u, i.v);
		mst[num].push_back({{min(i.u, i.v), max(i.u, i.v)}, i.cost});
	}
}
 
ll bi;
 
void dfs(ll here, ll pa)
{
	last[here] = pa;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		if(i.se == 0)
			len[i.fi] = dist[here][i.fi];
		else
			len[i.fi] = -INF;
		
		dfs(i.fi, here);
	}
}
 
vector< pair<pll, pll> > chng;
pll ER, AD;
 
void add_edge(ll I)
{
	ll uu = ne[I].fi;
	ll vv = ne[I].se;
	
	bi = -INF;
	
	len[uu] = -INF;
	dfs(uu, 0);
	
	cc++;
	
	ll UU = -1, VV = -1;
	
	for(ll i = vv ; i != 0 ; i = last[i])
	{
		chk[i] = cc;
		
		if(bi < len[i])
		{
			UU = i;
			VV = last[i];
			bi = len[i];
		}
	}
	
	if(bi == -INF)
		return;
	
	for(ll i = vv ; i != uu ; i = last[i])
	{
		if(dist[i][last[i]] > bi && len[i] == -INF)
			chng.push_back({{i, last[i]}, {dist[i][last[i]], bi}});
	}
	
	for(ll i = 0 ; i < (ll)vec[UU].size() - 1 ; i++)
	{
		if(vec[UU][i].fi == VV)
			swap(vec[UU][i], vec[UU][i + 1]);
	}
	
	vec[UU].pop_back();
	
	for(ll i = 0 ; i < (ll)vec[VV].size() - 1 ; i++)
	{
		if(vec[VV][i].fi == UU)
			swap(vec[VV][i], vec[VV][i + 1]);
	}
	
	vec[VV].pop_back();
	ER = {UU, VV};
	
	for(auto &i : chng)
		dist[i.fi.fi][i.fi.se] = dist[i.fi.se][i.fi.fi] = i.se.se;
	
	vec[uu].push_back({vv, 1});
	vec[vv].push_back({uu, 1});
	chng.push_back({{uu, vv}, {dist[uu][vv], bi}});
	dist[uu][vv] = dist[vv][uu] = bi;
	AD = {uu, vv};
}
 
ll gap;
 
void dfs2(ll here, ll pa)
{
	dp[here] = sum[here];
	dep[here] = dep[pa] + 1;
	
	for(auto &i : vec[here])
	{
		if(i.fi == pa)
			continue;
		
		dfs2(i.fi, here);
		dp[here] += dp[i.fi];
		
		if(i.se == 1)
			gap += dp[i.fi] * dist[here][i.fi];
	}
}
 
void f(ll here)
{
	if(here > K)
	{
		gap = 0;
		
		dfs2(grp[1], 0);
		
		ans = max(ans, gap);
		return;
	}
	
	f(here + 1);
	
	vector< pair<pll, pll> > hehehe;
	pll EE, AA;
	
	ER = AD = make_pair(-1, -1);
	chng.clear();
	add_edge(here);
	hehehe = chng;
	EE = ER;
	AA = AD;
	f(here + 1);
	
	if(EE.fi != -1)
	{
		vec[EE.fi].push_back({EE.se, 0});
		vec[EE.se].push_back({EE.fi, 0});
	}
	
	if(AA.fi != -1)
	{
		for(ll i = 0 ; i < (ll)vec[AA.fi].size() - 1 ; i++)
		{
			if(vec[AA.fi][i].fi == AA.se)
				swap(vec[AA.fi][i], vec[AA.fi][i + 1]);
		}
		
		vec[AA.fi].pop_back();
		
		for(ll i = 0 ; i < (ll)vec[AA.se].size() - 1 ; i++)
		{
			if(vec[AA.se][i].fi == AA.fi)
				swap(vec[AA.se][i], vec[AA.se][i + 1]);
		}
		
		vec[AA.se].pop_back();
	}
	
	for(auto &i : hehehe)
		dist[i.fi.fi][i.fi.se] = dist[i.fi.se][i.fi.fi] = i.se.fi;
}
 
int main(void)
{
	fastio
	
	cin >> n >> m >> K;
	//n = readInt();
	//m = readInt();
	//K = readInt();
	
	for(ll i = 1 ; i <= m ; i++)
	{
		cin >> all >> bll >> cll;
		
		//all = readInt();
		//bll = readInt();
		//cll = readInt();
		edg.push_back({all, bll, cll});
	}
	
	for(ll i = 1 ; i <= K ; i++)
	{
		//ne[i].fi = readInt();
		//ne[i].se = readInt();
		cin >> ne[i].fi >> ne[i].se;
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		//a[i] = readInt();
		cin >> a[i];
	}
	
	MST(0);
	
	for(ll i = 1 ; i <= K ; i++)
		edg.push_back({ne[i].fi, ne[i].se, 0});
	
	MST(1);
	
	for(auto &i : mst[1])
		st.insert(i);
	
	for(ll i = 1 ; i <= n ; i++)
		p[i] = i, ra[i] = 0;
	
	for(auto &i : mst[0])
	{
		if(st.find(i) == st.end())
			mst[2].push_back(i);
		else
			uunion(i.fi.fi, i.fi.se);
	}
	
	for(ll i = 1 ; i <= n ; i++)
		V.push_back(ffind(i));
	
	compress(V);
	siz = (ll)V.size();
	
	for(ll i = 1 ; i <= n ; i++)
	{
		ll w = ffind(i);
		
		w = lower_bound(V.begin(), V.end(), w) - V.begin() + 1;
		grp[i] = w;
		sum[w] += a[i];
	}
	
	for(auto &i : mst[2])
	{
		ll v1 = ffind(i.fi.fi);
		ll v2 = ffind(i.fi.se);
		
		v1 = lower_bound(V.begin(), V.end(), v1) - V.begin() + 1;
		v2 = lower_bound(V.begin(), V.end(), v2) - V.begin() + 1;
		
		vec[v1].push_back({v2, 0});
		vec[v2].push_back({v1, 0});
		dist[v1][v2] = dist[v2][v1] = i.se;
	}
	
	for(ll i = 1 ; i <= K ; i++)
	{
		ne[i].fi = lower_bound(V.begin(), V.end(), ffind(ne[i].fi)) - V.begin() + 1;
		ne[i].se = lower_bound(V.begin(), V.end(), ffind(ne[i].se)) - V.begin() + 1;
	}
	
	f(1);
	
	writeInt(ans);
	Flusher();
	return 0;
}