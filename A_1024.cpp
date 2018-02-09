#include <cstdio>
#include <cstring>
typedef long long LL;
struct bign
{
	int d[1010];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign Change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;

}

bool is_palindromixNumber(bign a)
{
	if(a.len == 1)
		return true;
	int len = a.len / 2;
	for(int i = 0; i < len; i++)
	{
		if(a.d[i] != a.d[a.len -i - 1])
			return false;
	}
	return true;
}

bign reverse(bign a)
{
	bign c;
	c.len = a.len;
	for(int i = 0; i < a.len; i++)
		c.d[i] = a.d[a.len - 1 - i];
	return c;
}

bign add(bign a, bign b)
{
	bign c;
	int carry = 0, tmp = 0, k = 0 ;
	for(int i = 0, j = 0; i < a.len || j < b.len; i++, j++)
	{
		tmp = a.d[i] + b.d[j] + carry;
		c.d[k++] = tmp % 10;
		carry = tmp / 10;
		c.len++;
	}
	if(carry != 0)
	{
		c.d[k] = carry;
		c.len++;
	}
	return c;
}
int main()
{
	char str[15];
	int k, count = 0;
	scanf("%s %d", str, &k);
	if(strlen(str) == 1)
	{
		printf("%s\n0", str);
		return 0;
	}
	count = k;
	bign a = Change(str);
	bign b , sum;
	while(count != 0)
	{
		if(is_palindromixNumber(a) == true)
			break;
		else
		{
			b = reverse(a);
			sum = add(a, b);
			a = sum;
		}
		count--;
	} 
	for(int i = 0; i < a.len; i++)
		printf("%d", a.d[a.len - i - 1]);
	printf("\n%d", k - count);
	return 0;
}