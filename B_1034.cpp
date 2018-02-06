#include <cstdio>
#include <algorithm>
typedef long long LL;
struct Fraction
{
	LL up, down;
};

Fraction f1, f2, ans;

LL gcd(LL a, LL b)
{
	return !b ? a : gcd(b, a % b);
}

Fraction reduction(Fraction res)
{
	if(res.down < 0)
	{
		res.up = -res.up;
		res.down = -res.down;
	}

	if(res.up == 0)
		res.down = 1;
	else
	{
		int d = gcd(abs(res.up), abs(res.down));
		res.down /= d;
		res.up /= d;
	}
	return res;
}

Fraction add(Fraction f1, Fraction f2)
{
	Fraction res;
	res.up = f1.up * f2.down + f1.down * f2.up;
	res.down = f1.down * f2.down;
	res = reduction(res);
	return res;
}

Fraction sub(Fraction f1, Fraction f2)
{
	Fraction res;
	res.up = f1.up * f2.down - f1.down * f2.up;
	res.down = f1.down * f2.down;
	return reduction(res);
}

Fraction multi(Fraction f1, Fraction f2)
{
	Fraction res;
	res.up = f1.up * f2.up;
	res.down = f1.down * f2.down;
	return reduction(res);
}

Fraction div(Fraction f1, Fraction f2)
{
	Fraction res;
	res.up = f1.up * f2.down;
	res.down = f1.down * f2.up;
	return reduction(res);
}

void showResult(Fraction f1, Fraction f2, char c, Fraction ans)
{
	f1 = reduction(f1);
	f2 = reduction(f2);
	ans = reduction(ans);

	bool flag = false;
	if(f1.up * f1.down < 0)
	{
		printf("(");
		flag = true;
	}
	LL x = f1.up / f1.down;
	LL y = f1.up % f1.down;
	LL z = f1.down;
	if(f1.down == 1)
		printf("%lld", f1.up);
	else if(abs(f1.up) > f1.down)
		printf("%lld %lld/%lld", f1.up / f1.down, abs(f1.up) % f1.down, f1.down);
	else 
		printf("%lld/%lld", f1.up, f1.down);
	if(flag)
		printf(")");

	printf(" %c ", c);
	flag = false;

	if(f2.up * f2.down < 0)
	{
		printf("(");
		flag = true;
	}
	if(f2.down == 1)
		printf("%lld", f2.up);
	else if(abs(f2.up) > f2.down)
		printf("%lld %lld/%lld", f2.up / f2.down, abs(f2.up) % f2.down, f2.down);
	else 
		printf("%lld/%lld", f2.up, f2.down);
	if(flag)
		printf(")");

	printf(" = ");
	flag = false;
	if(ans.up * ans.down < 0)
	{
		printf("(");
		flag = true;
	}
	if(ans.down == 1)
		printf("%lld", ans.up);
	else if(abs(ans.up) > ans.down)
		printf("%lld %lld/%lld", ans.up / ans.down, abs(ans.up) % ans.down, ans.down);
	else 
		printf("%lld/%lld", ans.up, ans.down);
	if(flag)
		printf(")");
	printf("\n");
}
int main()
{
	
	scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);

	ans = add(f1, f2);
	showResult(f1, f2, '+', ans);

	ans = sub(f1, f2);
	showResult(f1, f2, '-', ans);

	ans = multi(f1, f2);
	showResult(f1, f2, '*', ans);
	if(f2.up != 0)
	{
		ans = div(f1, f2);
		showResult(f1, f2, '/', ans);
	}
	else
	{
		bool flag = false;
		if(f1.up * f1.down < 0)
		{
			printf("(");
			flag = true;
		}
		if(f1.down == 1)
			printf("%lld", f1.up);
		else if(f1.up > f1.down)
			printf("%lld %lld/%lld", f1.up / f1.down, abs(f1.up) % f1.down, f1.down);
		else 
			printf("%lld/%lld", f1.up, f1.down);
		if(flag)
			printf(")");
		printf(" / 0 = Inf\n");
	}

	return 0;
}