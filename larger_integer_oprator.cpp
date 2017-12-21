#include <cstdio>
#include <cstring>
using namespace std;

typedef struct tagbign
{
	int d[1000];
	int len;
	tagbign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
}bign;

bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}
//高精度加法
bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		int tmp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	if(carry != 0)
	{
		c.d[c.len++] = carry;
	}
	return c;
}
//高精度减法
bign sub(bign a, bign b)
{
	bign c;
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		if(a.d[i] < b.d[i])
		{
			a.d[i+1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] = b.d[i];
	}
	
	while((c.len-1 >= 1) && (c.d[c.len - 1] == 0))
		c.len--;

	return c;
}

//高精度与低精度的乘法
bign multi(bign a, int b)
{
	bign c;
	int tmp = 0;
	int carry = 0;
	for(int i = 0; i < a.len; i++)
	{
		int tmp = a.d[i] * b + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}

	while(carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}

	return c;
}

//高精度与低精度的除法
bign divide(bign a, int b, int &r)
{
	bign c;
	int tmp = 0;
	c.len = a.len;
	for(int i = 0; i < a.len; i++)
	{
		tmp = r * 10 + a.d[i];
		if(r < b)
			c.d[i] = 0;
		else
		{
			c.d[i] = tmp / b;
			r = tmp % b;
		}
	}
	while((c.d[c.len - 1] == 0)&&(c.d[c.len] - 1 > 1))
	{
		c.len--;
	}
	return c;
}

void print(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.d[i]);
	}
}

int main()
{
	char str1[1000] = {0};
	char str2[1000] = {0};
	bign a, b;
	scanf("%s%s", str1, str2);
	a = change(str1);
	b = change(str2);
	print(add(a, b));

	return 0;
}