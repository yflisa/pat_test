#include <iostream>
#include <string>
using namespace std;

int main()
{
	int nLen = 0 , nFlag = 0;
	string sCent;

	getline(cin, sCent);
	nLen = sCent.length();
	nFlag = nLen;
	for(int i = nLen - 1 ; i >= 0; i--)
	{
		if(sCent[i] == ' ')
		{
			for(int j = i + 1; j < nFlag; j++)
			{
				cout << sCent[j];
			}
			nFlag = i;
			cout << ' ';
		}
	}

	for(int i = 0; i < nFlag; i++)
		cout << sCent[i];
	return 0;
}