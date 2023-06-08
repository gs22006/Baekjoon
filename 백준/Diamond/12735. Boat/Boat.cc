#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
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
 
int n;
pair<int, int> a[1010];
int ss = 1000000007;
int inv[1010];
vector<int> zip;
ll dp[1010][1010];
ll LC[1010];
ll xjc[1010];
int num[1010];
 
ll fast_mod(ll X)
{
	return X >= ss ? X - X / ss * ss : X;
}
 
ll sqrmtp(ll X, ll Y)
{
	ll ret = 1;
	
	while(Y)
	{
		if(Y & 1)
			ret = fast_mod(ret * X);
		
		X = fast_mod(X * X);
		Y >>= 1;
	}
	
	return ret;
}
 
int main(void)
{
	fastio
	
	n = readInt();
	//cin >> n;
	
	for(int i = 1 ; i <= n ; ++i)
	{
		a[i].fi = readInt();
		a[i].se = readInt();
		
		//cin >> a[i].fi >> a[i].se;
		
		zip.push_back(a[i].fi);
		zip.push_back(a[i].se + 1);
	}
	
	for(int i = 1 ; i <= n ; ++i)
		inv[i] = sqrmtp(i, ss - 2);
	
	compress(zip);
	
	dp[0][0] = 1;
	
	for(int i = 1 ; i <= n ; ++i)
		dp[0][i] = 1;
	
	int siz = (ll)zip.size();
	
	for(int i = 1 ; i < siz ; ++i)
	{
		int siz2 = 0;
		
		for(int j = 1 ; j <= n ; ++j)
		{
			if(a[j].fi <= zip[i - 1] && zip[i] - 1 <= a[j].se)
				num[siz2++] = j;
		}
		
		int L = zip[i] - zip[i - 1];
		LC[0] = 1;
		
		for(int j = 1 ; j <= siz2 ; ++j)
		{
			if(L <= 0)
				break;
			
			LC[j] = fast_mod(fast_mod(LC[j - 1] * L) * inv[j]);
			L--;
		}
		
		L = zip[i] - zip[i - 1];
		
		for(int j = 0 ; j <= siz2 - 2 ; ++j)
		{
			ll gap = j;
			ll gap2 = 1;
			
			xjc[j] = 0;
			
			if(L <= 1)
				break;
			
			xjc[j] = LC[2];
			
			for(int k = 1 ; ; ++k)
			{
				if(k + 2 > L || k > j)
					break;
				
				gap2 = fast_mod(fast_mod(gap2 * gap) * inv[k]);
				--gap;
				xjc[j] = fast_mod(xjc[j] + gap2 * LC[k + 2]);
			}
		}
		
		for(int j = 0 ; j < siz2 ; ++j)
		{
			dp[i][num[j]] = fast_mod(dp[i][num[j]] + dp[i - 1][num[j] - 1] * LC[1]);
			
			if(L >= 2)
			{
				for(int k = 0 ; k < j ; ++k)
					dp[i][num[j]] = fast_mod(dp[i][num[j]] + dp[i - 1][num[k] - 1] * xjc[j - k - 1]);
			}
		}
		
		for(int j = 0 ; j <= n ; ++j)
		{
			dp[i][j] = fast_mod(dp[i][j] + dp[i - 1][j] + dp[i][j - 1]);
			
			if(j)
				dp[i][j] = fast_mod(dp[i][j] - dp[i - 1][j - 1] + ss);
		}
	}
	
	dp[siz - 1][n]--;
	dp[siz - 1][n] = (dp[siz - 1][n] % ss + ss) % ss;
	
	cout << dp[siz - 1][n];
	return 0;
}