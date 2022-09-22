#include "stub.h"
#include <bits/stdc++.h>

using namespace std;
typedef int ll;

void swapCards(int cards[], int S, int T)
{
    ll chk[110] = {0, };
    
    queue< vector<ll> > cyc;
	
	for(ll i = 0 ; i < 52 ; i++)
	{
		queue<ll> q;
		vector<ll> vec;
		
		if(chk[i])
			continue;
		
		q.push(i);
		chk[i] = 1;
		
		while(!q.empty())
		{
			ll qq = q.front();
			q.pop();
			
			vec.push_back(qq);
			qq = cards[qq];
			
			if(chk[qq])
				continue;
			
			chk[qq] = 1;
			q.push(qq);
		}
		
		cyc.push(vec);
	}
	
	while(!cyc.empty())
	{
		vector<ll> qq = cyc.front();
		cyc.pop();
		
		if((ll)qq.size() <= T)
			continue;
		
		swap(cards[qq[0]], cards[qq[T]]);
		swap(qq[0], qq[T]);
		doSwap(qq[0], qq[T]);
		
		for(ll i = 0 ; i < 52 ; i++)
			chk[i] = 0;
		
		for(auto &i : qq)
		{
			if(chk[i])
				continue;
			
			ll w = i;
			queue<ll> Q;
			vector<ll> tmp;
			
			Q.push(w);
			chk[w] = 1;
			
			while(!Q.empty())
			{
				ll QQ = Q.front();
				Q.pop();
				
				tmp.push_back(QQ);
				QQ = cards[QQ];
				
				if(chk[QQ])
					continue;
				
				chk[QQ] = 1;
				Q.push(QQ);
			}
			
			cyc.push(tmp);
		}
	}
}

void guessCard(int S, int T, int target)
{
    ll gap = target;
	
	while(T--)
		gap = guess(gap);
}

