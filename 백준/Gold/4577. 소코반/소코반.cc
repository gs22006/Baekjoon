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

ll n, m;
char a[20][20];
char b[20][20];
char S[110];
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll cc;

int main(void)
{
	fastio
	
	while(1)
	{
		cin >> n >> m;
		
		if(!n && !m)
			break;
		
		cout << "Game " << ++cc << ": ";
		
		for(ll i = 0 ; i < n ; i++)
			cin >> a[i];
		
		cin >> S;
		
		ll len = strlen(S);
		ll X = 0, Y = 0;
		
		for(ll i = 0 ; i < n ; i++)
		{
			for(ll j = 0 ; j < m ; j++)
			{
				if(a[i][j] == '+')
					b[i][j] = '.';
				else if('A' <= a[i][j] && a[i][j] <= 'Z')
					b[i][j] = a[i][j] - 'A' + 'a';
				else
					b[i][j] = a[i][j];
			}
		}
		
		for(ll i = 0 ; i < n ; i++)
		{
			for(ll j = 0 ; j < m ; j++)
			{
				if(a[i][j] == 'W' || a[i][j] == 'w')
				{
					X = i;
					Y = j;
				}
			}
		}
		
		ll ff = 0;
		
		for(ll i = 0 ; i < len ; i++)
		{
			ll gg = 0;
			
			for(ll i = 0 ; i < n ; i++)
			{
				for(ll j = 0 ; j < m ; j++)
				{
					if(b[i][j] == 'b' && a[i][j] != '+' && !('A' <= a[i][j] && a[i][j] <= 'Z'))
						gg = 1;
				}
			}
			
			if(!gg)
			{
				ff = 1;
				break;
			}
			
			ll d = 0;
			
			if(S[i] == 'U')
				d = 0;
			else if(S[i] == 'D')
				d = 1;
			else if(S[i] == 'L')
				d = 2;
			else if(S[i] == 'R')
				d = 3;
			
			ll nx = X + dx[d];
			ll ny = Y + dy[d];
			
			if(b[nx][ny] != 'b' && b[nx][ny] != '#')
			{
				b[X][Y] = '.';
				b[nx][ny] = 'w';
				X = nx;
				Y = ny;
			}
			
			else if(b[nx][ny] == '#')
				continue;
			
			else if(b[nx][ny] == 'b')
			{
				if(b[nx + dx[d]][ny + dy[d]] != 'b' && b[nx + dx[d]][ny + dy[d]] != '#')
				{
					b[nx + dx[d]][ny + dy[d]] = 'b';
					b[nx][ny] = 'w';
					b[X][Y] = '.';
					X = nx;
					Y = ny;
				}
			}
		}
		
		ll gg = 0;
		
		for(ll i = 0 ; i < n ; i++)
		{
			for(ll j = 0 ; j < m ; j++)
			{
				if(b[i][j] == 'b' && a[i][j] != '+' && !('A' <= a[i][j] && a[i][j] <= 'Z'))
					gg = 1;
			}
		}
		
		if(!gg)
			ff = 1;
		
		if(!ff)
			cout << "incomplete\n";
		else
			cout << "complete\n";
		
		for(ll i = 0 ; i < n ; i++)
		{
			for(ll j = 0 ; j < m ; j++)
			{
				if(b[i][j] == 'b')
				{
					if(a[i][j] == '+' || ('A' <= a[i][j] && a[i][j] <= 'Z'))
						cout << "B";
					else
						cout << "b";
				}
				
				else if(b[i][j] == 'w')
				{
					if(a[i][j] == '+' || ('A' <= a[i][j] && a[i][j] <= 'Z'))
						cout << "W";
					else
						cout << "w";
				}
				
				else if(b[i][j] == '.')
				{
					if(a[i][j] == '+' || ('A' <= a[i][j] && a[i][j] <= 'Z'))
						cout << "+";
					else
						cout << ".";
				}
				
				else
					cout << b[i][j];
			}
			
			cout en;
		}
	}
	
	return 0;
}