#include <bits/stdc++.h>

using namespace std;

int v, e;
int all, bll;
vector<int> vec[10010];
int chk[10010], num;
int dan[10010];
int cou;

int dfs(int here, int r)
{
	chk[here] = ++num;
	
	int ch = 0;
	int ret = chk[here];
	
	for(int i = 0 ; i < vec[here].size() ; i++)
	{
		if(chk[vec[here][i]])
		{
			ret = min(ret, chk[vec[here][i]]);
			continue;
		}
		
		ch++;
		int pp = dfs(vec[here][i], 0);
		
		if(r == 0 && pp >= chk[here])
			dan[here] = 1;
		
		ret = min(ret, pp);
	}
	
	if(r == 1 && ch >= 2)
		dan[here] = 1;
	
	return ret;
}

int main(void)
{
	scanf("%d %d", &v, &e);
	
	for(int i = 0 ; i < e ; i++)
	{
		scanf("%d %d", &all, &bll);
		vec[all].push_back(bll);
		vec[bll].push_back(all);
	}
	
	for(int i = 1 ; i <= v ; i++)
	{
		if(chk[i] == 0)
			dfs(i, 1);
	}
	
	for(int i = 1 ; i <= v ; i++)
		cou += dan[i];
	
	printf("%d\n", cou);
	
	for(int i = 1 ; i <= v ; i++)
	{
		if(dan[i])
			printf("%d ", i);
	}
	
	return 0;
}