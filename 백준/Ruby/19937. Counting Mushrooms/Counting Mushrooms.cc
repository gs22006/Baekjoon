//mushrooms.cpp
#include "mushrooms.h"
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
typedef double ld;
#define MAX 9223372036854775807LL
#define MIN -9223372036854775808LL

int count_mushrooms(int n)
{
	if(n <= 200)
	{
		ll ans = 1;
		vector<ll> tmp;
		
		for(ll i = 1 ; i < n - 1 ; i += 2)
		{
			tmp.clear();
			tmp.push_back(i + 1);
			tmp.push_back(0);
			tmp.push_back(i);
			ans += 2 - use_machine(tmp);
		}
		
		if(n % 2 == 0)
		{
			tmp.clear();
			tmp.push_back(0);
			tmp.push_back(n - 1);
			ans += 1 - use_machine(tmp);
		}
		
		return ans;
	}
	
	//0 ~ 4
	
	vector<ll> A, B;
	vector<ll> tmp;
	
	tmp.push_back(0);
	tmp.push_back(1);
	
	A.push_back(0);
	
	if(use_machine(tmp) == 1)
		B.push_back(1);
	else
		A.push_back(1);
	
	tmp.clear();
	tmp.push_back(0);
	tmp.push_back(2);
	
	if(use_machine(tmp) == 1)
		B.push_back(2);
	else
		A.push_back(2);
	
	if(A.size() >= 2)
	{
		tmp.clear();
		tmp.push_back(A[0]);
		tmp.push_back(3);
		tmp.push_back(A[1]);
		tmp.push_back(4);
		
		ll gap = use_machine(tmp);
		
		if(gap % 2 == 0)
			A.push_back(4);
		else
			B.push_back(4);
		
		if(gap / 2 == 0)
			A.push_back(3);
		else
			B.push_back(3);
	}
	
	else
	{
		tmp.clear();
		tmp.push_back(B[0]);
		tmp.push_back(3);
		tmp.push_back(B[1]);
		tmp.push_back(4);
		
		ll gap = use_machine(tmp);
		
		if(gap % 2 == 0)
			B.push_back(4);
		else
			A.push_back(4);
		
		if(gap / 2 == 0)
			B.push_back(3);
		else
			A.push_back(3);
	}
	
	ll buck = 45;
	
	for(ll i = 1 ; i < buck ; i++)
	{
		ll bun1 = 5 * i;
		ll bun2 = 5 * i + 1;
		ll bun3 = 5 * i + 2;
		ll bun4 = 5 * i + 3;
		ll bun5 = 5 * i + 4;
		
		if(A.size() >= 3)
		{
			tmp.clear();
			tmp.push_back(A[0]);
			tmp.push_back(bun1);
			tmp.push_back(A[1]);
			tmp.push_back(bun2);
			tmp.push_back(A[2]);
			tmp.push_back(bun3);
			
			ll gap = use_machine(tmp);
			
			if(gap < 2)
			{
				//bun1 = 0, bun2 = 0
				A.push_back(bun1);
				A.push_back(bun2);
				
				if(gap % 2 == 0)
					A.push_back(bun3);
				else
					B.push_back(bun3);
				
				tmp.clear();
				tmp.push_back(A[0]);
				tmp.push_back(bun4);
				tmp.push_back(A[1]);
				tmp.push_back(bun5);
				
				gap = use_machine(tmp);
				
				if(gap % 2 == 0)
					A.push_back(bun5);
				else
					B.push_back(bun5);
				
				if(gap / 2 == 0)
					A.push_back(bun4);
				else
					B.push_back(bun4);
			}
			
			else if(gap >= 4)
			{
				//bun1 = 1, bun2 = 1
				B.push_back(bun1);
				B.push_back(bun2);
				
				if(gap % 2 == 0)
					A.push_back(bun3);
				else
					B.push_back(bun3);
				
				tmp.clear();
				tmp.push_back(A[0]);
				tmp.push_back(bun4);
				tmp.push_back(A[1]);
				tmp.push_back(bun5);
				
				gap = use_machine(tmp);
				
				if(gap % 2 == 0)
					A.push_back(bun5);
				else
					B.push_back(bun5);
				
				if(gap / 2 == 0)
					A.push_back(bun4);
				else
					B.push_back(bun4);
			}
			
			else
			{
				//bun1 != bun2, bun3 OK
				
				if(gap % 2 == 0)
					A.push_back(bun3);
				else
					B.push_back(bun3);
				
				if(B.size() < 2)
				{
					tmp.clear();
					tmp.push_back(A[0]);
					tmp.push_back(bun1);
					tmp.push_back(A[1]);
					tmp.push_back(bun2);
					
					ll gapp = use_machine(tmp);
					
					if(gapp % 2 == 0)
						A.push_back(bun2);
					else
						B.push_back(bun2);
					
					if(gapp / 2 == 0)
						A.push_back(bun1);
					else
						B.push_back(bun1);
					
					tmp.clear();
					tmp.push_back(A[0]);
					tmp.push_back(bun4);
					tmp.push_back(A[1]);
					tmp.push_back(bun5);
					
					gapp = use_machine(tmp);
					
					if(gapp % 2 == 0)
						A.push_back(bun5);
					else
						B.push_back(bun5);
					
					if(gapp / 2 == 0)
						A.push_back(bun4);
					else
						B.push_back(bun4);
				}
				
				else
				{
					tmp.clear();
					tmp.push_back(B[0]);
					tmp.push_back(bun1);
					tmp.push_back(B[1]);
					tmp.push_back(A[0]);
					tmp.push_back(bun2);
					tmp.push_back(A[1]);
					tmp.push_back(bun4);
					tmp.push_back(A[2]);
					tmp.push_back(bun5);
					
					ll gapp = use_machine(tmp) - 1;
					
					if(gapp % 2 == 0)
						A.push_back(bun5);
					else
						B.push_back(bun5), gapp--;
					
					if(gapp == 0)
					{
						B.push_back(bun1);
						A.push_back(bun2);
						A.push_back(bun4);
					}
					
					else if(gapp == 2)
					{
						B.push_back(bun1);
						A.push_back(bun2);
						B.push_back(bun4);
					}
					
					else if(gapp == 4)
					{
						A.push_back(bun1);
						B.push_back(bun2);
						A.push_back(bun4);
					}
					
					else if(gapp == 6)
					{
						A.push_back(bun1);
						B.push_back(bun2);
						B.push_back(bun4);
					}
				}
			}
		}
		
		else if(B.size() >= 3)
		{
			tmp.clear();
			tmp.push_back(B[0]);
			tmp.push_back(bun1);
			tmp.push_back(B[1]);
			tmp.push_back(bun2);
			tmp.push_back(B[2]);
			tmp.push_back(bun3);
			
			ll gap = use_machine(tmp);
			
			if(gap < 2)
			{
				//bun1 = 1, bun2 = 1
				B.push_back(bun1);
				B.push_back(bun2);
				
				if(gap % 2 == 0)
					B.push_back(bun3);
				else
					A.push_back(bun3);
				
				tmp.clear();
				tmp.push_back(B[0]);
				tmp.push_back(bun4);
				tmp.push_back(B[1]);
				tmp.push_back(bun5);
				
				gap = use_machine(tmp);
				
				if(gap % 2 == 0)
					B.push_back(bun5);
				else
					A.push_back(bun5);
				
				if(gap / 2 == 0)
					B.push_back(bun4);
				else
					A.push_back(bun4);
			}
			
			else if(gap >= 4)
			{
				//bun1 = 0, bun2 = 0
				A.push_back(bun1);
				A.push_back(bun2);
				
				if(gap % 2 == 0)
					B.push_back(bun3);
				else
					A.push_back(bun3);
				
				tmp.clear();
				tmp.push_back(B[0]);
				tmp.push_back(bun4);
				tmp.push_back(B[1]);
				tmp.push_back(bun5);
				
				gap = use_machine(tmp);
				
				if(gap % 2 == 0)
					B.push_back(bun5);
				else
					A.push_back(bun5);
				
				if(gap / 2 == 0)
					B.push_back(bun4);
				else
					A.push_back(bun4);
			}
			
			else
			{
				//bun1 != bun2, bun3 OK
				
				if(gap % 2 == 0)
					B.push_back(bun3);
				else
					A.push_back(bun3);
				
				if(A.size() < 2)
				{
					tmp.clear();
					tmp.push_back(B[0]);
					tmp.push_back(bun1);
					tmp.push_back(B[1]);
					tmp.push_back(bun2);
					
					ll gapp = use_machine(tmp);
					
					if(gapp % 2 == 0)
						B.push_back(bun2);
					else
						A.push_back(bun2);
					
					if(gapp / 2 == 0)
						B.push_back(bun1);
					else
						A.push_back(bun1);
					
					tmp.clear();
					tmp.push_back(B[0]);
					tmp.push_back(bun4);
					tmp.push_back(B[1]);
					tmp.push_back(bun5);
					
					gapp = use_machine(tmp);
					
					if(gapp % 2 == 0)
						B.push_back(bun5);
					else
						A.push_back(bun5);
					
					if(gapp / 2 == 0)
						B.push_back(bun4);
					else
						A.push_back(bun4);
				}
				
				else
				{
					tmp.clear();
					tmp.push_back(A[0]);
					tmp.push_back(bun1);
					tmp.push_back(A[1]);
					tmp.push_back(B[0]);
					tmp.push_back(bun2);
					tmp.push_back(B[1]);
					tmp.push_back(bun4);
					tmp.push_back(B[2]);
					tmp.push_back(bun5);
					
					ll gapp = use_machine(tmp) - 1;
					
					if(gapp % 2 == 0)
						B.push_back(bun5);
					else
						A.push_back(bun5), gapp--;
					
					if(gapp == 0)
					{
						A.push_back(bun1);
						B.push_back(bun2);
						B.push_back(bun4);
					}
					
					else if(gapp == 2)
					{
						A.push_back(bun1);
						B.push_back(bun2);
						A.push_back(bun4);
					}
					
					else if(gapp == 4)
					{
						B.push_back(bun1);
						A.push_back(bun2);
						B.push_back(bun4);
					}
					
					else if(gapp == 6)
					{
						B.push_back(bun1);
						A.push_back(bun2);
						A.push_back(bun4);
					}
				}
			}
		}
	}
	
	ll gaet = 0;
	ll num = 0;
	ll ans = A.size();
	
	for(ll i = 5 * buck ; i < n ; i += gaet)
	{
		if(A.size() >= B.size())
		{
			gaet = A.size();
			num = 0;
		}
		
		else
		{
			gaet = B.size();
			num = 1;
		}
		
		tmp.clear();
		ll siz = gaet;
		ll cc = 0;
		
		if(i + siz > n)
			siz = n - i;
		
		for(ll j = i ; j < i + siz ; j++)
		{
			if(num == 0)
				tmp.push_back(A[cc++]);
			else
				tmp.push_back(B[cc++]);
			
			tmp.push_back(j);
		}
		
		ll gappp = use_machine(tmp);
		
		if(num == 0)
			ans += siz - (gappp + 1) / 2;
		else
			ans += (gappp + 1) / 2;
		
		if(num == 0)
		{
			if(gappp % 2 == 0)
				A.push_back(i + siz - 1);
			else
				B.push_back(i + siz - 1);
		}
		
		else
		{
			if(gappp % 2 == 0)
				B.push_back(i + siz - 1);
			else
				A.push_back(i + siz - 1);
		}
	}
	
	return ans;
}