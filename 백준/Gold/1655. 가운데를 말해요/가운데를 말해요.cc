#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int> > minq;

int main(void)
{
	int mid;
	int n;
	int all;
	
	scanf("%d %d", &n, &mid);
	
	printf("%d\n", mid);
	
	for(int i = 2 ; i <= n ; i++)
	{
		scanf("%d", &all);
		
		if(mid < all)
		{
			if(i % 2 == 0)
			{
				minq.push(all);
			}
			
			else if(i % 2 == 1)
			{
				minq.push(all);
				maxq.push(mid);
				mid = minq.top();
				minq.pop();
			}
		}
		
		else if(mid >= all)
		{
			if(i % 2 == 0)
			{
				minq.push(mid);
				maxq.push(all);
				mid = maxq.top();
				maxq.pop();
			}
			
			else if(i % 2 == 1)
			{
				maxq.push(all);
			}
		}
		
		printf("%d\n", mid);
	}
	
	return 0;
}