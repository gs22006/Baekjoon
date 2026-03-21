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

ll t;
ll n, m;
string a[1010];
char tmp[1010][1010];
ll ff;

ll check_row(ll X)
{
	for(ll i = 0 ; i < m ; i++)
	{
		if(a[X][i] == 'I' && tmp[X][i] != 'I')
			return 0;
		
		if(a[X][i] == 'P' && tmp[X][i] != 'P')
			return 0;
		
		if(a[X][i] == 'C' && tmp[X][i] != 'C')
			return 0;
	}
	
	return 1;
}

void fill_row(ll X, ll typ)
{
	char A, B;
	
	if(typ == 1)
	{
		A = 'I';
		B = 'P';
	}
	
	else if(typ == 2)
		A = B = 'C';
	
	else if(typ == 3)
	{
		A = 'I';
		B = 'C';
	}
	
	else
	{
		A = 'C';
		B = 'P';
	}
	
	for(ll i = 0 ; i < m ; i++)
		tmp[X][i] = (i % 2 == 0 ? A : B);
	
	if(check_row(X))
		return;
	
	for(ll i = 0 ; i < m ; i++)
		tmp[X][i] = (i % 2 == 0 ? B : A);
	
	if(check_row(X))
		return;
	
	ff = 1;
	return;
}

ll check_col(ll X)
{
	for(ll i = 0 ; i < n ; i++)
	{
		if(a[i][X] == 'I' && tmp[i][X] != 'I')
			return 0;
		
		if(a[i][X] == 'P' && tmp[i][X] != 'P')
			return 0;
		
		if(a[i][X] == 'C' && tmp[i][X] != 'C')
			return 0;
	}
	
	return 1;
}

void fill_col(ll X, ll typ)
{
	char A, B;
	
	if(typ == 1)
	{
		A = 'I';
		B = 'P';
	}
	
	else if(typ == 2)
		A = B = 'C';
	
	else if(typ == 3)
	{
		A = 'I';
		B = 'C';
	}
	
	else
	{
		A = 'C';
		B = 'P';
	}
	
	for(ll i = 0 ; i < n ; i++)
		tmp[i][X] = (i % 2 == 0 ? A : B);
	
	if(check_col(X))
		return;
	
	for(ll i = 0 ; i < n ; i++)
		tmp[i][X] = (i % 2 == 0 ? B : A);
	
	if(check_col(X))
		return;
	
	ff = 1;
	return;
}

void print(void)
{
	cout << "yes\n";
	
	for(ll i = 0 ; i < n ; i++)
	{
		for(ll j = 0 ; j < m ; j++)
			cout << tmp[i][j];
		
		cout en;
	}
}

int main(void)
{
	fastio
	
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		for(ll i = 0 ; i < n ; i++)
			cin >> a[i];
		
		//case 1
		ff = 0;
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(i & 1)
				fill_row(i, 1);
			else
				fill_row(i, 2);
		}
		
		if(!ff)
		{
			print();
			continue;
		}
		
		//case 2
		ff = 0;
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(i & 1)
				fill_row(i, 2);
			else
				fill_row(i, 1);
		}
		
		if(!ff)
		{
			print();
			continue;
		}
		
		//case 5
		ff = 0;
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(i & 1)
				fill_row(i, 3);
			else
				fill_row(i, 4);
		}
		
		if(!ff)
		{
			print();
			continue;
		}
		
		//case 6
		ff = 0;
		
		for(ll i = 0 ; i < n ; i++)
		{
			if(i & 1)
				fill_row(i, 4);
			else
				fill_row(i, 3);
		}
		
		if(!ff)
		{
			print();
			continue;
		}
		
		//case 3
		ff = 0;
		
		for(ll i = 0 ; i < m ; i++)
		{
			if(i & 1)
				fill_col(i, 1);
			else
				fill_col(i, 2);
		}
		
		if(!ff)
		{
			print();
			continue;
		}
		
		//case 4
		ff = 0;
		
		for(ll i = 0 ; i < m ; i++)
		{
			if(i & 1)
				fill_col(i, 2);
			else
				fill_col(i, 1);
		}
		
		if(!ff)
		{
			print();
			continue;
		}
		
		//case 7
		ff = 0;
		
		for(ll i = 0 ; i < m ; i++)
		{
			if(i & 1)
				fill_col(i, 3);
			else
				fill_col(i, 4);
		}
		
		if(!ff)
		{
			print();
			continue;
		}
		
		//case 8
		ff = 0;
		
		for(ll i = 0 ; i < m ; i++)
		{
			if(i & 1)
				fill_col(i, 4);
			else
				fill_col(i, 3);
		}
		
		if(!ff)
		{
			print();
			continue;
		}
		
		cout << "no\n";
	}
	
	return 0;
}