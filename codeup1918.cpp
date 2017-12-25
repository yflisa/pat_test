#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
using namespace std;

typedef struct tagNode
{
	double num;
	char op;
	bool flag;
}Node;

string str;
stack<Node> s;
queue<Node> q;
map<char, int> op;

void Change()
{
	double num;
	Node tmpNode;
	for(int i = 0; i < str.length();)
	{
		if((str[i] >= '0' && str[i] <= '9'))
		{
			tmpNode.flag = true;
			tmpNode.num = str[i] - '0';
			i++;
			while(i < str.length() && (str[i] >= '0' && str[i] <= '9'))
			{
				tmpNode.num = tmpNode.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(tmpNode);
		}
		else
		{
			tmpNode.flag = false;
			while((!s.empty()) && (op[str[i]] <= op[s.top().op]))
			{
				q.push(s.top());
				s.pop();
			}
			tmpNode.op = str[i];
			s.push(tmpNode);
			i++;
		}
	}

	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}

double Cal()
{
	double tmp1, tmp2;
	Node cur = {0}, tmp = {0};

	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(cur.flag == true)
			s.push(cur);
		else
		{
			tmp2 = s.top().num;
			s.pop();
			tmp1 = s.top().num;
			s.pop();
			tmp.flag = true;
			if(cur.op == '+')
				tmp.num = tmp2 + tmp1;
			else if(cur.op == '-')
				tmp.num = tmp2 - tmp1;
			else if(cur.op == '*')
				tmp.num = tmp2 * tmp1;
			else
				tmp.num = tmp1 / tmp2;
			s.push(tmp);
		}
	}

	return tmp.num;
}

int main()
{
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	while(getline(cin, str), str != "0")
	{
		for(string::iterator it = str.end() - 1; it != str.begin(); it--)
		{
			if(*it == ' ')
				str.erase(it);
		}

		if(!s.empty())
			s.pop();

		Change();
		printf("%.2f\n", Cal());
	}

	return 0;
}