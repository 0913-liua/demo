/*************************************************
** 源文件   : score.c
** 功能说明 : Function Definitions
** 创建版本 : v1.0
/**************************************************/

/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"

/*----------------函数定义-------------*/

//1.1手动输入学生基本数据
void readData(SS stu[], int N)
{

	printf("请按照如下格式输入学生信息：学号,姓名,平时成绩,期末成绩\n");

	for (int i = 0; i < N; i++)
	{
		printf("第%d个学生:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------成绩录入完毕!--------\n");

}

//1.2从文件里读取学生基本数据
SS* readDataFromFile(int* N)
{

	printf("\n\n------the first:read data from a file--------\n\n");

	SS* stu;// 开辟新空间,存取文件中的每个学生信息

	FILE* fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("C:\\Users\\dell\\Desktop\\data.txt", "r");

	//1.获取学生数目
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("the number of student is:%d\n", count);


	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count * sizeof(SS));


	//3.读取每条学生的信息
	while ((!feof(fp)))
	{
		for (index = 0; index < count; index++)
		{
			fscanf(fp, "%s %s %f %f %f", &stu[index].number, &stu[index].name, &stu[index].dailyScore, &stu[index].experiment, &stu[index].finalScore);
			printf("%s %s %f %f %f\n", stu[index].number, stu[index].name, stu[index].dailyScore, stu[index].experiment, stu[index].finalScore);
		}
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.计算N个学生各自的总评成绩
void calcuScore(SS stu[], int N)
{
	int i;
	for (i = 0; i < N; i++)
		stu[i].generalScore = 0.2 * stu[i].dailyScore + 0.2 * stu[i].experiment+ 0.6 * stu[i].finalScore;
	getchar();
}


//3.根据总评成绩排名
int cmpBigtoSmall(const void* a, const void* b)
{

	SS* aa = (SS*)(a);
	SS* bb = (SS*)(b);



	if ((*aa).generalScore < (*bb).generalScore)  return 1;

	else if ((*aa).generalScore > (*bb).generalScore)  return -1;

	else
		return 0;

}

void sortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}

//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[], int N)
{

	printf("\n------the second:output data in formal------\n\n");






	for (int i = 0; i < N; i++)
		printf("%s %s %f %f %f %f\n", stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiment, stu[i].finalScore, stu[i].generalScore);





	getchar();

}