#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second

ll t;
ll n;
char s[10000010];
ll fail[10000010];

int main(void)
{
    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld", &n);
        scanf("%s", s);

        string s1, s2;
        ll chch = 0;

        for(ll i = 0 ; i < n ; i++)
        {
            if(s[i] == '1')
                chch = 1;

            if(s1.empty() && s[i] != '0')
                s1.push_back(s[i]);
            else if(!s1.empty())
                s1.push_back(s[i]);
        }

        if(!chch)
        {
            printf("0\n");
            continue;
        }

        ll len1 = (ll)s1.length();
        ll len2 = 0;
        ll W = 0;

        for(ll i = 0 ; i < len1 ; i++)
        {
            if(s1[i] == '0')
            {
                W = i;
                len2 = len1 - i;
                break;
            }
        }

        if(len2 == 0)
        {
            if(len1 == n)
            {
                for(ll i = 0 ; i < len1 - 1 ; i++)
                    printf("%c", s1[i]);

                printf("0\n");
            }

            else
            {
                for(ll i = 0 ; i < len1 ; i++)
                    printf("%c", s1[i]);
                
                printf("\n");
            }
            
            continue;
        }

        string s3;
        ll p = 0;

        for(ll i = W ; i < len1 ; i++)
        {
            if(s1[i] == '0')
                s3.push_back('1');
            else
                s3.push_back('0');
        }

        for(ll i = 0 ; i < len1 ; i++)
            fail[i] = 0;
        
        fail[0] = 0;

        for(ll i = 1 ; i < len2 ; i++)
        {
            while(p && s3[i] != s3[p])
                p = fail[p - 1];
            
            if(s3[i] == s3[p])
                p++;
            
            fail[i] = p;
        }

        ll maxx = 0;
        ll w = 0;
        p = 0;

        for(ll i = 0 ; i < n ; i++)
        {
            while(p && s3[p] != s[i])
                p = fail[p - 1];
            
            if(s3[p] == s[i])
            {
                if(n - i < len2 - p)
                    break;
                
                p++;
                maxx = max(maxx, p);
                w = i;
            }
        }

        for(ll i = w - maxx + 1 ; i <= w ; i++)
            s2.push_back(s[i]);
        
        for(ll i = maxx ; i < len2 ; i++)
            s2.push_back(s[w + i - maxx + 1]);

        for(ll i = 0 ; i < len1 ; i++)
        {
            if(i < W)
                printf("%c", s1[i]);
            else if(s1[i] != s2[i - W])
                printf("1");
            else
                printf("0");
        }

        printf("\n");
    }

    return 0;
}