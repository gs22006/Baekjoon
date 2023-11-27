#include <bits/stdc++.h>

using namespace std;

int n;
int all[110][10];
int d[110][110];
int maxx;

int main(void)
{
    scanf("%d", &n);
    
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d %d", &all[i][0], &all[i][1]);
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = all[i][0] ; j < all[i][0] + 10 ; j++)
        {
            for(int k = all[i][1] ; k < all[i][1] + 10 ; k++)
            {
                d[j][k] = 1;
            }
        }
    }
    
    for(int i = 1 ; i < 110 ; i++)
    {
        for(int j = 1 ; j < 110 ; j++)
        {
            if(d[i][j] != 0)
            {
                d[i][j] += d[i - 1][j];
            }
        }
    }
    
    for(int i = 1 ; i < 110 ; i++)
    {
        for(int j = 1 ; j < 110 ; j++)
        {
            int l = 110;
            int w = 1;
            
            for(int k = j ; k > 0 ; k--, w++)
            {
                if(d[i][k] <= 0)
                    break;
                if(l > d[i][k])
                {
                    l = d[i][k];
                }
                
                maxx = max(maxx, l * w);
            }
        }
    }
    
    printf("%d", maxx);
    return 0;
}