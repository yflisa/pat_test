#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Student
{
	char chId[20];
	int nScore;
	int nExamSiteNum; //������
	int nRank; //�ȼ�
}Stu;
bool cmp(Stu a, Stu b)
{
	if(a.nScore != b.nScore)
		return a.nScore > b.nScore;
	else
		return strcmp(a.chId, b.chId) > 0;
}

int main()
{
	int nExamSiteSum =0, nExamStudentNum = 0, nStuSum = 0;
	Stu tStudent[200] = {0};
	cin >> nExamSiteSum;   //��������
	for(int i = 1; i <= nExamSiteSum; i++) //����������1��ʼ����
	{
		//����ÿ����������
		cin >> nExamStudentNum;

		for(int j = 0; j < nExamStudentNum; j++)
		{
			//��������ÿ�����������������Ҽ���������
			scanf("%s %d", tStudent[nStuSum].chId, &tStudent[nStuSum].nScore);
			tStudent[nStuSum].nExamSiteNum = i;
			nStuSum++;
		}

		//������������
		sort(tStudent + nStuSum - nExamStudentNum, tStudent + nStuSum, cmp);
		//��һ�����Ϊ�ȼ�1
		tStudent[nStuSum - nExamStudentNum + 1].nRank = 1;
		//���ڵ�һ��֮���ͬѧ�����ŵȼ�
		for(int j = 0; j < nExamStudentNum; j++)
		{
			if(tStudent[j].nScore != tStudent[j-1].nScore)
				tStudent[j].nRank = tStudent[j-1].nRank + 1;
			else
				tStudent[j].nRank = tStudent[j-1].nScore;
		}
	}

	printf("%d\n", nStuSum);
	sort(tStudent, tStudent + nStuSum, cmp);
	int tmpRank = 1;
	for(int i = 0; i < nStuSum; i++)
	{
		if(tStudent[i].nScore != tStudent[i -1].nScore)
			tmpRank +=  i + 1;
		printf("%s %d %s", tStudent[i].chId, tStudent[i].nScore ,tStudent[i].nExamSiteNum, tStudent[i].nRank);
	}
	return 0;
}