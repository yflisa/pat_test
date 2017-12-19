/*
	���������Ҫ���ݣ�1.���������뿼��������2.�ֱ�����ÿ��������������3.�ٽ�ÿ�������ı�źͳɼ�����
	���Ҫ������ÿ����ı�ţ���������������ţ������ڵ�����

	��������Ҫע��ĵ㣺
	1.��Ҫ�Լ�ʵ�����򣬿���ֱ�ӵ���sort()������ע�����algorithm��ͷ�ļ�������sort()������ô�ã����ﲻ��
	2.������ʱ����Ҫ�ȶԱ��༶�ڽ���һ���������ٽ����꼶�������ȶԱ��༶���������Եõ��༶�ڵĵȼ����꼶�������õ�������
	3.�����ɼ���ͬ������id��������
	4.ע�������������ļ��㷽������������Ϊ j+1-(num-k),������Ի�һ���߶�ͼ���м���
	5.�����Ǵ�С����ʹ�� <���Ӵ�Сʹ�� >�� �����������ǰһ�������бȽ�
	6.�����������±�1��ʼ��
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
	char id[15];
	int score;
	int location_number;  //������
	int local_rank; //�ڱ��������
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
	scanf("%d", &n); //����
	for(int i = 1; i <= n; i++)  //ѭ������ÿ�������Ϣ
	{
		scanf("%d", &k);  //ÿ�����ж�����
		for(int j = 0; j < k; j++)
		{
			scanf("%s %d", stu[num].id, &stu[num].score);  //����ÿ�˵�id�ͷ���
			stu[num].location_number = i;   //����ÿ��ѧ���Ŀ�����
			num++;							//�������ۼ�
		}
		sort(stu + num - k, stu + num, cmp);  //������ѧ������
		stu[num - k].local_rank = 1;		  //��¼����ĵ�һ���ǵȼ�1
		for(int j = num - k + 1; j < num; j++)  //�����ı߽�����, �����ų��ȼ�
		{
			if(stu[j].score == stu[j - 1].score)
			{
				stu[j].local_rank = stu[j - 1].local_rank;
			}	
			else
			{
				stu[j].local_rank = j + 1 - (num - k); //ע������ļ��㷽��
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
