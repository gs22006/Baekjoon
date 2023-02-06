#include <bits/stdc++.h>

using namespace std;

char s[500010];
int len, x, sa[500010], pos[500010];
int lcp[500010];

bool cmp(int xx, int yy)
{
	if(pos[xx] != pos[yy])
		return pos[xx] < pos[yy];
	
	xx += x;
	yy += x;
	
	return (xx < len && yy < len) ? (pos[xx] < pos[yy]) : (xx > yy);
}

void suffixarray()
{
	len = strlen(s);
	
	for(int i = 0 ; i < len ; i++)
	{
		sa[i] = i;
		pos[i] = s[i];
	}
	
	for(x = 1 ; ; x *= 2)
	{
		sort(sa, sa + len, cmp);
		
		int tmp[500010] = {0, };
		
		for(int i = 0 ; i < len - 1 ; i++)
			tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
		
		for(int i = 0 ; i < len ; i++)
			pos[sa[i]] = tmp[i];
		
		if(tmp[len - 1] == len - 1)
			break;
	}
}

void LCP()
{
	for(int i = 0, y = 0 ; i < len ; i++, y = max(y - 1, 0))
	{
		if(pos[i] == len - 1)
			continue;
		
		for(int j = sa[pos[i] + 1] ; s[i + y] == s[j + y] ; y++);
		lcp[pos[i]] = y;
	}
}

int main(void)
{
	scanf("%s", s);
	
	suffixarray();
	LCP();
	
	for(int i = 0 ; i < len ; i++)
		printf("%d ", sa[i] + 1);
	
	printf("\n");
	
	printf("x ");
	
	for(int i = 0 ; i < len - 1 ; i++)
		printf("%d ", lcp[i]);
		
	return 0;
}