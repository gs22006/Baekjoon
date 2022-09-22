#include <bits/stdc++.h>

using namespace std;

struct snail
{
	long long x1, x2;
	long long y1, y2;
	long long A, B, C;
	long long dx, dy;
};

struct point
{
	double x;
	double y;
	long long p;
};

struct meet
{
	long long A;
	long long B;
	long long Type;
	double Time;
	double Time2;
	double mx, my;
	
	bool operator < (const meet &abc) const
	{
		if(Time == abc.Time)
		{
			if(mx == abc.mx)
				return my < abc.my;
			
			return mx < abc.mx;
		}
		
		return Time < abc.Time;
	}
};

long long n, L;
snail a[1010];
long long cnt;
meet m[1000010];
long long cc;
long long ddx[10];
long long ddy[10];
double sto[1010];
long long chk[1010];
double maxx;

long long isSameSlope(snail l, snail r)
{
	return l.A * r.B == l.B * r.A;
}

long long isSameLine(snail l, snail r)
{
	if(!isSameSlope(l, r))
		return 0;
	
	return l.A * r.C == r.A * l.C && l.B * r.C == r.B * l.C;
}

long long isVertical(snail l)
{
	return l.B == 0;
}

point LineIntersection(snail l, snail r)
{
	if(isSameSlope(l, r))
	{
		if(!isSameLine(l, r))
		{
			point tmp;
			tmp.p = 0;
			tmp.x = 0;
			tmp.y = 0;
			return tmp;
		}
		
		if(isVertical(l))
		{
			if(l.dy * r.dy < 0)
			{
				if((l.y1 - r.y1) * l.dy < 0)
				{
					point tmp;
					tmp.p = 1;
					tmp.x = (double)l.x1;
					tmp.y = (double)(l.y1 + r.y1) / 2.0;
					return tmp;
				}
				
				else
				{
					point tmp;
					tmp.p = 0;
					tmp.x = 0;
					tmp.y = 0;
					return tmp;
				}
			}
			
			else
			{
				if((l.y1 - r.y1) * l.dy < 0)
				{
					point tmp;
					tmp.p = 1;
					tmp.x = (double)r.x1;
					tmp.y = (double)r.y1;
					return tmp;
				}
				
				else
				{
					point tmp;
					tmp.p = 1;
					tmp.x = (double)l.x1;
					tmp.y = (double)l.y1;
					return tmp;
				}
			}
		}
		
		else
		{
			if(l.dx * r.dx < 0)
			{
				if((l.x1 - r.x1) * l.dx < 0)
				{
					point tmp;
					tmp.p = 1;
					tmp.x = (double)(l.x1 + r.x1) / 2.0;
					tmp.y = (double)(l.y1 + r.y1) / 2.0;
					return tmp;
				}
				
				else
				{
					point tmp;
					tmp.p = 0;
					tmp.x = 0;
					tmp.y = 0;
					return tmp;
				}
			}
			
			else
			{
				if((l.x1 - r.x1) * l.dx < 0)
				{
					point tmp;
					tmp.p = 1;
					tmp.x = (double)r.x1;
					tmp.y = (double)r.y1;
					return tmp;
				}
				
				else
				{
					point tmp;
					tmp.p = 1;
					tmp.x = (double)l.x1;
					tmp.y = (double)l.y1;
					return tmp;
				}
			}
		}
	}
	
	double xx = ((double)(l.C * r.B) - (double)(r.C * l.B)) / ((double)(r.A * l.B) - (double)(l.A * r.B));
	double yy = ((double)(l.C * r.A) - (double)(r.C * l.A)) / ((double)(r.B * l.A) - (double)(l.B * r.A));
	
	if(xx < 0 || yy < 0 || xx > L || yy > L)
	{
		point tmp;
		tmp.p = 0;
		tmp.x = 0;
		tmp.y = 0;
		return tmp;
	}
	
	if(isVertical(l) && ((yy - l.y1) * l.dy < 0))
	{
		point tmp;
		tmp.p = 0;
		tmp.x = 0;
		tmp.y = 0;
		return tmp;
	}
	
	if(isVertical(r) && ((yy - r.y1) * r.dy < 0))
	{
		point tmp;
		tmp.p = 0;
		tmp.x = 0;
		tmp.y = 0;
		return tmp;
	}
	
	if(!isVertical(l) && ((xx - l.x1) * l.dx < 0))
	{
		point tmp;
		tmp.p = 0;
		tmp.x = 0;
		tmp.y = 0;
		return tmp;
	}
	
	if(!isVertical(r) && ((xx - r.x1) * r.dx < 0))
	{
		point tmp;
		tmp.p = 0;
		tmp.x = 0;
		tmp.y = 0;
		return tmp;
	}
	
	point tmp;
	tmp.p = 1;
	tmp.x = xx;
	tmp.y = yy;
	return tmp;
}

int main(void)
{
	scanf("%lld %lld", &n, &L);
	
	for(long long i = 0 ; i < n ; i++)
	{
		scanf("%lld %lld %lld %lld", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
		a[i].A = a[i].y2 - a[i].y1;
		a[i].B = a[i].x1 - a[i].x2;
		a[i].C = -1 * (a[i].A * a[i].x1 + a[i].B * a[i].y1);	
		a[i].dx = (a[i].x2 - a[i].x1);
		a[i].dy = (a[i].y2 - a[i].y1);
	}
	
	a[n].x1 = 0;
	a[n].y1 = 0;
	a[n].x2 = 0;
	a[n].y2 = L;
	a[n].A = a[n].y2 - a[n].y1;
	a[n].B = a[n].x1 - a[n].x2;
	a[n].C = -1 * (a[n].A * a[n].x1 + a[n].B * a[n].y1);	
	a[n].dx = (a[n].x2 - a[n].x1);
	a[n].dy = (a[n].y2 - a[n].y1);
	
	a[n + 1].x1 = 0;
	a[n + 1].y1 = 0;
	a[n + 1].x2 = L;
	a[n + 1].y2 = 0;
	a[n + 1].A = a[n + 1].y2 - a[n + 1].y1;
	a[n + 1].B = a[n + 1].x1 - a[n + 1].x2;
	a[n + 1].C = -1 * (a[n + 1].A * a[n + 1].x1 + a[n + 1].B * a[n + 1].y1);	
	a[n + 1].dx = (a[n + 1].x2 - a[n + 1].x1);
	a[n + 1].dy = (a[n + 1].y2 - a[n + 1].y1);
	
	a[n + 2].x1 = L;
	a[n + 2].y1 = 0;
	a[n + 2].x2 = L;
	a[n + 2].y2 = L;
	a[n + 2].A = a[n + 2].y2 - a[n + 2].y1;
	a[n + 2].B = a[n + 2].x1 - a[n + 2].x2;
	a[n + 2].C = -1 * (a[n + 2].A * a[n + 2].x1 + a[n + 2].B * a[n + 2].y1);	
	a[n + 2].dx = (a[n + 2].x2 - a[n + 2].x1);
	a[n + 2].dy = (a[n + 2].y2 - a[n + 2].y1);
	
	a[n + 3].x1 = 0;
	a[n + 3].y1 = L;
	a[n + 3].x2 = L;
	a[n + 3].y2 = L;
	a[n + 3].A = a[n + 3].y2 - a[n + 3].y1;
	a[n + 3].B = a[n + 3].x1 - a[n + 3].x2;
	a[n + 3].C = -1 * (a[n + 3].A * a[n + 3].x1 + a[n + 3].B * a[n + 3].y1);	
	a[n + 3].dx = (a[n + 3].x2 - a[n + 3].x1);
	a[n + 3].dy = (a[n + 3].y2 - a[n + 3].y1);
	
	for(long long i = 0 ; i < n ; i++)
	{
		for(long long j = i + 1 ; j < n + 4 ; j++)
		{
			point tmp;
			tmp = LineIntersection(a[i], a[j]);
			
			if(tmp.p == 1)
			{
				if(j >= n)
				{
					m[cc].A = i;
					m[cc].B = j;
					m[cc].Type = 3;
					m[cc].mx = tmp.x;
					m[cc].my = tmp.y;
					m[cc++].Time = sqrt((tmp.x - (double)a[i].x1) * (tmp.x - (double)a[i].x1) + (tmp.y - (double)a[i].y1) * (tmp.y - (double)a[i].y1));
				}
				
				else
				{
					if((tmp.x - (double)a[i].x1) * (tmp.x - (double)a[i].x1) + (tmp.y - (double)a[i].y1) * (tmp.y - (double)a[i].y1) == (tmp.x - (double)a[j].x1) * (tmp.x - (double)a[j].x1) + (tmp.y - (double)a[j].y1) * (tmp.y - (double)a[j].y1))
					{
						m[cc].A = i;
						m[cc].B = j;
						m[cc].Type = 1;
						m[cc].mx = tmp.x;
						m[cc].my = tmp.y;
						m[cc++].Time = sqrt((tmp.x - (double)a[i].x1) * (tmp.x - (double)a[i].x1) + (tmp.y - (double)a[i].y1) * (tmp.y - (double)a[i].y1));
					}
					
					else if((tmp.x - (double)a[i].x1) * (tmp.x - (double)a[i].x1) + (tmp.y - (double)a[i].y1) * (tmp.y - (double)a[i].y1) > (tmp.x - (double)a[j].x1) * (tmp.x - (double)a[j].x1) + (tmp.y - (double)a[j].y1) * (tmp.y - (double)a[j].y1))
					{
						m[cc].A = i;
						m[cc].B = j;
						m[cc].Type = 2;
						m[cc].mx = tmp.x;
						m[cc].my = tmp.y;
						m[cc].Time = sqrt((tmp.x - (double)a[i].x1) * (tmp.x - (double)a[i].x1) + (tmp.y - (double)a[i].y1) * (tmp.y - (double)a[i].y1));
						m[cc++].Time2 = sqrt((tmp.x - (double)a[j].x1) * (tmp.x - (double)a[j].x1) + (tmp.y - (double)a[j].y1) * (tmp.y - (double)a[j].y1));
					}
					
					else if((tmp.x - (double)a[i].x1) * (tmp.x - (double)a[i].x1) + (tmp.y - (double)a[i].y1) * (tmp.y - (double)a[i].y1) < (tmp.x - (double)a[j].x1) * (tmp.x - (double)a[j].x1) + (tmp.y - (double)a[j].y1) * (tmp.y - (double)a[j].y1))
					{
						m[cc].A = j;
						m[cc].B = i;
						m[cc].Type = 2;
						m[cc].mx = tmp.x;
						m[cc].my = tmp.y;
						m[cc].Time = sqrt((tmp.x - (double)a[j].x1) * (tmp.x - (double)a[j].x1) + (tmp.y - (double)a[j].y1) * (tmp.y - (double)a[j].y1));
						m[cc++].Time2 = sqrt((tmp.x - (double)a[i].x1) * (tmp.x - (double)a[i].x1) + (tmp.y - (double)a[i].y1) * (tmp.y - (double)a[i].y1));
					}
				}
			}
		}
	}
	
	sort(m, m + cc);
	
	for(long long i = 0 ; i < 1010 ; i++)
		sto[i] = 987654321;
	
	for(long long i = 0 ; i < cc ; i++)
	{
		if(m[i].Type == 1)
		{
			if(sto[m[i].A] >= m[i].Time && sto[m[i].B] >= m[i].Time)
			{
				chk[m[i].A] = 1;
				chk[m[i].B] = 1;
				sto[m[i].A] = m[i].Time;
				sto[m[i].B] = m[i].Time;
			}
		}
		
		else if(m[i].Type == 2)
		{
			if(sto[m[i].A] >= m[i].Time)
			{
				if(sto[m[i].B] >= m[i].Time2)
				{
					chk[m[i].A] = 1;
					sto[m[i].A] = m[i].Time;
				}
			}
		}
		
		else if(m[i].Type == 3)
		{
			if(sto[m[i].A] >= m[i].Time)
			{
				chk[m[i].A] = 1;
				sto[m[i].A] = m[i].Time;
			}
		}
	}
	
	for(long long i = 0 ; i < n ; i++)
		maxx = max(maxx, sto[i]);
	
	printf("%.2lf", maxx);
	return 0;
}