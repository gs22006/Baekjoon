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

ll H;
ll n, q;
ll all;
priority_queue<ll> pq1, pq2;
ll sum;

void print(void)
{
	if(sum < H)
		cout << -1 en;
	else
		cout << (ll)pq1.size() en;
}

int main(void)
{
	fastio
	
	cin >> H;
	cin >> n >> q;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		cin >> all;
		pq2.push(all);
	}
	
	while(!pq2.empty() && sum < H)
	{
		sum += pq2.top();
		pq1.push(-pq2.top());
		pq2.pop();
	}
	
	print();
	
	while(q--)
	{
		cin >> all;
		
		sum += all;
		pq1.push(-all);
		
		while(!pq1.empty() && sum + pq1.top() >= H)
		{
			sum += pq1.top();
			pq2.push(-pq1.top());
			pq1.pop();
		}
		
		while(!pq2.empty() && sum < H)
		{
			sum += pq2.top();
			pq1.push(-pq2.top());
			pq2.pop();
		}
		
		print();
	}
	
	return 0;
}