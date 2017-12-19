/*
	这个案例主要内容：1.考试中输入考场个数，2.分别输入每个考场的人数，3.再将每个考生的编号和成绩输入
	输出要求：输出该考生的编号，年纪排名，考场号，考场内的排名

	有以下需要注意的点：
	1.不要自己实现排序，可以直接调用sort()函数，注意包含algorithm的头文件，具体sort()函数怎么用，这里不讲
	2.排名的时候，需要先对本班级内进行一次排名，再进行年级排名。先对本班级排名，可以得到班级内的等级；年级排名，得到总排名
	3.排名成绩相同，按照id进行派名
	4.注意计算班内排名的计算方法，这里的语句为 j+1-(num-k),这个可以画一个线段图进行计算
	5.排序是从小到大使用 <，从大到小使用 >， 都是这个数跟前一个数进行比较
	6.考场计数从下标1开始。
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
	char id[15];
	int score;
	int location_number;  //考场号
	int local_rank; //在本班的排名
}stu[30010];

bool cmp(Student a, Student b)
{
	if(a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id, b.id) < 0; 
}

int main()
{
	int n, k, num = 0;
	scanf("%d", &n); //班数
	for(int i = 1; i <= n; i++)  //循环输入每个班的信息
	{
		scanf("%d", &k);  //每个班有多少人
		for(int j = 0; j < k; j++)
		{
			scanf("%s %d", stu[num].id, &stu[num].score);  //输入每人的id和分数
			stu[num].location_number = i;   //输入每个学生的考场号
			num++;							//总人数累加
		}
		sort(stu + num - k, stu + num, cmp);  //将本班学生排名
		stu[num - k].local_rank = 1;		  //记录本班的第一名是等级1
		for(int j = num - k + 1; j < num; j++)  //这个班的边界条件, 班里排出等级
		{
			if(stu[j].score == stu[j - 1].score)
			{
				stu[j].local_rank = stu[j - 1].local_rank;
			}	
			else
			{
				stu[j].local_rank = j + 1 - (num - k); //注意这里的计算方法
			}
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	int r = 1;
	for(int i = 0; i < num; i++)
	{
		if(i > 0 && stu[i].score != stu[i -1].score)
		{
			r = i + 1;
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
}
