#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool judge(string str)
{
	int len = str.size();
	for(int i = 0; i < len / 2; i++)
	{
		if(str[i] < '0' || str[i] > '9')
			return false;
		if(str[i] != str[len - i - 1])
			return false;
	}
	return true;
}

string add(string str1, string str2)
{
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int len = str1.size();
	int carry = 0;
	string ans;
	int i;
	for(i = 0; i < len; i++)
	{
		int a = str1[i] - '0';
		int b = str2[i] - '0';
		int sum = a + b + carry;
		ans += sum % 10 + '0';
		carry = sum / 10;
	}
	if(carry != 0)
		ans += carry + '0';
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string str1;
	cin >> str1;

	for(int i = 0; i <= 10; i++)
	{
		string str2 = str1;
		reverse(str2.begin(), str2.end());
		bool bRet = judge(str1);
		if(bRet)
		{
			cout << str1 << " is a palindromic number." << endl;
			return 0;
		}
		else if(i != 0)
		{
			string sum = add(str1, str2);
			cout << str1 << " + " << str2 << " = " << sum << endl;
			str1 = sum;
		}
	}

	printf("Not found in 10 iterations.\n");
	return 0;
}