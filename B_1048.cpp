#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string A, B, ans;

	cin >> A >> B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	ans = (A.size()> B.size() ? A:B);
	int tmp;
	for(int i =0; i < ans.size(); i++)
	{
		int tmpA = i < A.size() ? A[i] - '0' : 0;
		int tmpB = i < B.size() ? B[i] - '0' : 0;
		if(i % 2 == 0)
		{
			tmp = (tmpA + tmpB) % 13;
			if(tmp == 10)
				ans[i] = 'J';
			else if(tmp == 11)
				ans[i] = 'Q';
			else if(tmp == 12)
				ans[i] = 'K';
			else
				ans[i] = '0' + tmp;
		}
		else
		{
			tmp = tmpB - tmpA;
			if(tmp < 0)
				tmp += 10;
			ans[i] = '0' + tmp;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}