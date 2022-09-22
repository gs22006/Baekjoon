#include <bits/stdc++.h>

using namespace std;
typedef int ll;
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
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2,sse")

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

ll t;
ll n, q;
ll a[100010];
ll all, bll, cll;

struct segtree_beats
{
	//max, min, sum
	long long seg[400010][3];
	long long lazy[400010][2];
	
	void init(ll no, ll s, ll e)
	{
		lazy[no][0] = lazy[no][1] = 0;
		
		if(s == e)
		{
			seg[no][0] = seg[no][1] = seg[no][2] = a[s];
			return;
		}
		
		init(no << 1, s, (s + e) >> 1);
		init((no << 1) | 1, ((s + e) >> 1) + 1, e);
		
		seg[no][0] = max(seg[no << 1][0], seg[(no << 1) | 1][0]);
		seg[no][1] = min(seg[no << 1][1], seg[(no << 1) | 1][1]);
		seg[no][2] = seg[no << 1][2] + seg[(no << 1) | 1][2];
	}
	
	void prop(ll no, ll s, ll e)
	{
		if(!lazy[no][0] && !lazy[no][1])
			return;
		
		if(!lazy[no][1])
		{
			seg[no][0] += lazy[no][0];
			seg[no][1] += lazy[no][0];
			seg[no][2] += (e - s + 1) * lazy[no][0];
			
			if(s != e)
			{
				lazy[no << 1][0] += lazy[no][0];
				lazy[(no << 1) | 1][0] += lazy[no][0];
			}
		}
		
		else
		{
			seg[no][0] = seg[no][1] = lazy[no][1] + lazy[no][0];
			seg[no][2] = (e - s + 1) * (lazy[no][1] + lazy[no][0]);
			
			if(s != e)
			{
				lazy[no << 1][1] = lazy[(no << 1) | 1][1] = lazy[no][1];
				lazy[no << 1][0] = lazy[(no << 1) | 1][0] = lazy[no][0];
			}
		}
		
		lazy[no][0] = lazy[no][1] = 0;
	}
	
	void update1(ll no, ll s, ll e, ll l, ll r, ll v)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			lazy[no][0] = v;
			prop(no, s, e);
			
			return;
		}
		
		if(s <= r)
			update1(no << 1, s, ((s + e) >> 1), l, r, v);
		
		if(l <= e)
			update1((no << 1) | 1, ((s + e) >> 1) + 1, e, l, r, v);
		
		seg[no][0] = max(seg[no << 1][0], seg[(no << 1) | 1][0]);
		seg[no][1] = min(seg[no << 1][1], seg[(no << 1) | 1][1]);
		seg[no][2] = seg[no << 1][2] + seg[(no << 1) | 1][2];
	}
	
	void update2(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return;
		
		if(l <= s && e <= r)
		{
			if(floor(sqrt(seg[no][0])) == floor(sqrt(seg[no][1])))
			{
				lazy[no][1] = floor(sqrt(seg[no][0]));
				prop(no, s, e);
				
				return;
			}
			
			if(seg[no][1] + 1 == seg[no][0])
			{
				lazy[no][0] = floor(sqrt(seg[no][1])) - seg[no][1];
				prop(no, s, e);
				
				return;
			}
		}
		
		if(s <= r)
			update2(no << 1, s, ((s + e) >> 1), l, r);
		
		if(l <= e)
			update2((no << 1) | 1, ((s + e) >> 1) + 1, e, l, r);
		
		seg[no][0] = max(seg[no << 1][0], seg[(no << 1) | 1][0]);
		seg[no][1] = min(seg[no << 1][1], seg[(no << 1) | 1][1]);
		seg[no][2] = seg[no << 1][2] + seg[(no << 1) | 1][2];
	}
	
	long long query(ll no, ll s, ll e, ll l, ll r)
	{
		prop(no, s, e);
		
		if(e < l || r < s)
			return 0;
		
		if(l <= s && e <= r)
			return seg[no][2];
		
		long long ret = 0;
		ll mid = (s + e) >> 1;
		
		if(l <= s && mid <= r)
		{
			prop(no << 1, s, mid);
			ret += seg[no << 1][2];
		}
		
		else if(l <= mid && s <= r)
			ret += query(no << 1, s, ((s + e) >> 1), l, r);
		
		if(l <= mid + 1 && e <= r)
		{
			prop(no << 1 | 1, mid + 1, e);
			ret += seg[(no << 1) | 1][2];
		}
		
		else if(l <= e && mid + 1 <= r)
			ret += query((no << 1) | 1, ((s + e) >> 1) + 1, e, l, r);
		
		return ret;
	}
}segt;

int main(void)
{
	//cin >> t;
	t = readInt();
	
	while(t--)
	{
		//cin >> n>>q;
		n = readInt();
		q = readInt();
		
		for(ll i = 1 ; i <= n ; ++i)
		{
			a[i] = readInt();
			//cin >> a[i];
		}
		
		segt.init(1, 1, n);
		
		while(q--)
		{
			//cin >> all;
			all = readInt();
			
			if(all == 1)
			{
				//cin >> all >> bll;
				all = readInt();
				bll = readInt();
				segt.update2(1, 1, n, all, bll);
			}
			
			else if(all == 2)
			{
				//cin >> all >> bll;
				all = readInt();
				bll = readInt();
				writeInt(segt.query(1, 1, n, all, bll), '\n');
			}
			
			else if(all == 3)
			{
				//cin >> all >> bll >> cll;
				all = readInt();
				bll = readInt();
				cll = readInt();
				segt.update1(1, 1, n, all, bll, cll);
			}
		}
	}
	
	Flusher();
	return 0;
}