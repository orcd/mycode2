#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define N 20

//给数组赋值
void init_array(int *array, int len)
{
	int i;
	
	//设置随机种子
	srand( (unsigned int)time(NULL) );
	
	for(i = 0; i < len; ++i)
	{
		array[i] = rand()%100+1; //范围为 1~100
	}
}

//遍历数组
void print_array(int *array, int len)
{
	int i;
	for (i = 0; i < len; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[N];	//定义数组
	int len = sizeof(array) / sizeof(*array); //元素个数
	
	//给数组赋值
	init_array(array, len);

	//遍历数组
	printf("排序前：");
	print_array(array, len);
	
	//选择法排序
	select_sort(array, len);
	
	//遍历数组
	printf("排序后：");
	print_array(array, len);
	
	return 0;
}
