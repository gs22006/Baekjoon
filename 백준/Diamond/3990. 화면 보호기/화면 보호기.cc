#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll n, m;
ll h[100010];
char all;
ll bll, cll;

struct fenwicktree
{
	ld bit[1010];

	void update(ll p, ld v)
	{
		if(p > 1000)
			return;

		bit[p] += v;
		p += p & (-p);
		update(p, v);
	}

	ld query(ll p)
	{
		if(p == 0)
			return 0;

		return query(p - (p & (-p))) + bit[p];
	}
}ABIT, BBIT, CBIT;

int main(void)
{
    scanf("%lld %lld", &n, &m);

    for(ll i = 0 ; i < n ; i++)
        scanf("%lld", &h[i]);

    for(ll i = 1 ; i < n ; i++)
    {
        //i - 1 ~ i

        ll h1 = min(h[i], h[i - 1]);
        ll h2 = max(h[i], h[i - 1]);
        ld A, B, C;

        if(h1 != h2)
        {
            A = (1.0 / (ld)(h2 - h1) / 2.0);
            B = ((ld)(-2.0 * h1) / (ld)(h2 - h1) / 2.0);
            C = ((ld)(h1 * h1) / (ld)(h2 - h1) / 2.0);

            ABIT.update(h1 + 1, A);
            BBIT.update(h1 + 1, B);
            CBIT.update(h1 + 1, C);
            ABIT.update(h2 + 2, -A);
            BBIT.update(h2 + 2, -B);
            CBIT.update(h2 + 2, -C);
            CBIT.update(h2 + 2, A * (ld)(h2 * h2) + B * (ld)h2 + C);
        }

        A = 0;
        B = 1;
        C = -(ld)h2;

        ABIT.update(h2 + 2, A);
        BBIT.update(h2 + 2, B);
        CBIT.update(h2 + 2, C);
    }

    while(m--)
    {
        scanf(" %c", &all);

        if(all == 'Q')
        {
            scanf("%lld", &bll);

            ld AA = ABIT.query(bll + 1);
            ld BB = BBIT.query(bll + 1);
            ld CC = CBIT.query(bll + 1);

            printf("%.3Lf\n", (ld)(bll * bll) * AA + (ld)bll * BB + CC);
        }

        else
        {
            scanf("%lld %lld", &bll, &cll);

            ll L = max(bll, 1LL);
            ll R = min(bll + 1, n);

            for(ll i = L ; i <= R ; i++)
            {
                ll h1 = min(h[i], h[i - 1]);
                ll h2 = max(h[i], h[i - 1]);
                ld A, B, C;

                if(h1 != h2)
                {
                    A = -(1.0 / (ld)(h2 - h1) / 2.0);
                    B = -((ld)(-2.0 * h1) / (ld)(h2 - h1) / 2.0);
                    C = -((ld)(h1 * h1) / (ld)(h2 - h1) / 2.0);

                    ABIT.update(h1 + 1, A);
                    BBIT.update(h1 + 1, B);
                    CBIT.update(h1 + 1, C);
                    ABIT.update(h2 + 2, -A);
                    BBIT.update(h2 + 2, -B);
                    CBIT.update(h2 + 2, -C);
                    CBIT.update(h2 + 2, A * (ld)(h2 * h2) + B * (ld)h2 + C);
                }

                A = 0;
                B = -1;
                C = (ld)h2;

                ABIT.update(h2 + 2, A);
                BBIT.update(h2 + 2, B);
                CBIT.update(h2 + 2, C);
            }

            h[bll] = cll;

            for(ll i = L ; i <= R ; i++)
            {
                ll h1 = min(h[i], h[i - 1]);
                ll h2 = max(h[i], h[i - 1]);
                ld A, B, C;

                if(h1 != h2)
                {
                    A = (1.0 / (ld)(h2 - h1) / 2.0);
                    B = ((ld)(-2.0 * h1) / (ld)(h2 - h1) / 2.0);
                    C = ((ld)(h1 * h1) / (ld)(h2 - h1) / 2.0);

                    ABIT.update(h1 + 1, A);
                    BBIT.update(h1 + 1, B);
                    CBIT.update(h1 + 1, C);
                    ABIT.update(h2 + 2, -A);
                    BBIT.update(h2 + 2, -B);
                    CBIT.update(h2 + 2, -C);
                    CBIT.update(h2 + 2, A * (ld)(h2 * h2) + B * (ld)h2 + C);
                }

                A = 0;
                B = 1;
                C = -(ld)h2;

                ABIT.update(h2 + 2, A);
                BBIT.update(h2 + 2, B);
                CBIT.update(h2 + 2, C);
            }
        }
    }

    /*
    h1 < h2 (아닌 경우에는 직선을 대칭시켜도 문제없음.)

    (0, h1), (1, h2)
    y = (h2 - h1)x + h1

    (h1 <= H <= h2)

    높이 : (H - h1)
    밑변 : (H - h1) / (h2 - h1)
    넓이 : (H - h1)^2 / (h2 - h1)

    (H^2 - 2 * h1 * H + h1^2) / (h2 - h1)

    aH^2 + bH + c = 넓이

    *************************
    a = (1 / (h2 - h1)) / 2
    b = (-2 * h1 / (h2 - h1)) / 2
    c = ((h1)^2 / (h2 - h1)) / 2
    *************************

    사각형 넓이의 경우
    y = h인 지점의 위부터 사각형이 시작된다고 하자.

    (h < H)

    (H - h)

    aH^2 + bH + c = 넓이

    *************************
    a = 0
    b = 1
    c = -h
    *************************
    */

    return 0;
}
