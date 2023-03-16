#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,sse")

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
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if(pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
	if(pos == len) return -1;
	return buf[pos++];
}
inline int readChar(){
	int c = getChar();
	while(c <= 32) c = getChar();
	return c;
}
template <class T>
inline T readInt(){
	int s = 1, c = readChar();
	T x = 0;
	if(c == '-') s = -1, c = getChar();
	while('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
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

int n;
ll X1, Y1, X2, Y2;
pll tmp[200010];
pll tmp2[200010];
pair< pair<int, int>, int> a[200010];
int ans[200010];
int K[200010];
int chk[200010], yu[200010];
ll Px, Py;
vector<ll> zipX, zipY;
vector<ll> tmpp;
int cc;
int seg[200010];
int weird;

void update(ll w, ll v)
{
	for(int i = w ; i <= n ; i += (i & (-i)))
		seg[i] += v;
	
	return;
}

ll query(ll X)
{
	ll ret = 0;
	
	for(int i = X ; i >= 1 ; i -= (i & (-i)))
		ret += seg[i];
	
	return ret;
}

ll ccw(pll X, pll Y, pll Z)
{
	return (X.fi * Y.se + Y.fi * Z.se + Z.fi * X.se) - (X.se * Y.fi + Y.se * Z.fi + Z.se * X.fi);
}

vector<int> V[1600010];

void f(int no, int s, int e)
{
	int siz = (ll)V[no].size();
	
	if(s > e || !siz)
		return;
	
	if(s == e)
	{
		for(auto &i : V[no])
			ans[a[i].se] = s;
		
		return;
	}
	
	if(siz == 1)
	{
		ans[a[V[no][0]].se] = a[V[no][0]].se;
		return;
	}
	
	cc++;
	int mid = (s + e) >> 1;
	
	//cout << "MID" << mid en;
	for(int i = 0 ; i < siz ; ++i)
	{
		int ww = V[no][i];
		
		if(!weird)
			yu[i] = query(a[ww].fi.se);
		else
			yu[i] = query(a[ww].fi.se) - query(a[ww].fi.se - 1);
		
		//cout << a[V[no][i]].se sp << yu[i] en;
		
		if(a[ww].se <= mid || yu[i] >= K[a[ww].se])
		{
			//cout << "update : " << a[V[no][i]].fi.se en;
			V[no << 1].push_back(ww);
			chk[i] = cc;
			update(a[ww].fi.se, 1);
		}
		
		else
		{
			K[a[ww].se] -= yu[i];
			V[no << 1 | 1].push_back(ww);
		}
	}
	
	for(int i = 0 ; i < siz ; i++)
	{
		if(chk[i] == cc)
			update(a[V[no][i]].fi.se, -1);
	}
	
	//cout en;
	
	f(no << 1, s, mid);
	f(no << 1 | 1, mid + 1, e);
}

int main(void)
{
	fastio
	
	//cin >> n;
	//cin >> X1 >> Y1 >> X2 >> Y2;
	n = readInt();
	X1 = readInt();
	Y1 = readInt();
	X2 = readInt();
	Y2 = readInt();
	
	for(int i = 1 ; i <= n ; ++i)
	{
		tmp[i].fi = readInt();
		tmp[i].se = readInt();
		//cin >> tmp[i].fi >> tmp[i].se;
	}
	
	for(int i = 1 ; i <= n ; ++i)
	{
		//cin >> K[i];
		K[i] = readInt();
	}
	
	if(X1 * Y2 == X2 * Y1)
	{
		X2 = -Y1;
		Y2 = X1;
		weird = 1;
	}
	
	if(!weird && ccw({X1 + tmp[1].fi, Y1 + tmp[1].se}, tmp[1], {X2 + tmp[1].fi, Y2 + tmp[1].se}) < 0)
	{
		swap(X1, X2);
		swap(Y1, Y2);
	}
	
	for(ll i = 1 ; i <= n ; i++)
	{
		tmp2[i].fi = tmp[i].fi * Y2 - tmp[i].se * X2;
		tmp2[i].se = tmp[i].fi * Y1 - tmp[i].se * X1;
		
		if(weird)
			tmp2[i].fi *= -1;
		
		zipX.push_back(tmp2[i].fi);
		zipY.push_back(tmp2[i].se);
	}
	
	compress(zipX);
	compress(zipY);
	
	for(int i = 1 ; i <= n ; ++i)
	{
		a[i].fi.fi = lower_bound(zipX.begin(), zipX.end(), tmp2[i].fi) - zipX.begin() + 1;
		a[i].fi.fi *= -1;
		a[i].fi.se = lower_bound(zipY.begin(), zipY.end(), tmp2[i].se) - zipY.begin() + 1;
		a[i].se = i;
		//cout << a[i].fi.fi sp << a[i].fi.se en;
	}
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1 ; i <= n ; ++i)
		V[1].push_back(i);
	
	f(1, 1, n);
	
	for(int i = 1 ; i <= n ; ++i)
	{
		writeInt(ans[i], ' ');
		////cout << ans[i] sp;
	}
	
	Flusher();
	return 0;
}