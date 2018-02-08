#include <cstdio>
#include <cstring>

struct bign
{
	int d[1010];
	int len;
	int every_len[20];
	bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
		memset(every_len, 0, sizeof(every_len));
	}
};

bign Change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
		a.every_len[a.d[i]]++;
	}
	return a;
}

bign multi(bign a)
{
	bign b;
	b.len = a.len;
	int carry = 0, tmp = 0, i = 0;
	for(; i < a.len; i++)
	{
		tmp = carry + a.d[i] * 2;
		b.d[i] = tmp % 10;
		carry = tmp / 10;
		b.every_len[b.d[i]]++;
	}
	if(carry != 0)
	{
		b.d[i] = carry;
		b.len++;
		b.every_len[b.d[i]]++;
	}
	return b;
}

bool judge(bign a, bign b)
{
	if(a.len != b.len)
		return false;
	for(int i = a.len-1, j = b.len - 1; i >= 0 &&j >= 0; i--, j--)
	{
		if(a.every_len[i] != b.every_len[i])
			return false;
	}
	return true;
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
	char str[1010] ;//= {"1234567899"};
	scanf("%s", str);
	bign a = Change(str);
	bign b = multi(a);
	bool ret = judge(a, b);
	if(ret)
		printf("Yes\n");
	else
		printf("No\n");
	print(b);
	return 0;
}