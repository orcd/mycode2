#pragma once
#include <stdlib.h>

typedef struct _DynamicArray
{
	void **data; //数据存储空间
	int capacity; //数组的最大容量
	int size; //数组的使用大小
}DynamicArray;

//初始化
void * Init_DynamicArray();
//按位置插入
void PushByPos_DynamicArray(void *_array,int pos, void *data);
//头部插入
void PushFront_DynamicArray(void *_array, void *data);
//尾部插入
void PushBack_DynamicArray(void *_array, void *data);
//按位置删除
void RemoveByPos_DynamicArray(void *_array, int pos);
//按值删除
void RemoveByVal_DynamicArray(void *_array, void *data, int(*compare)(void*, void*)); //回调函数
//头部删除
void RemoveFront_DynamicArray(void *_array);
//尾部删除
void RemoveBack_DynamicArray(void *_array);
//获取数据
void * GetByPos_DynamicArray(void *_array, int pos);
//遍历
void Foreach_DynamicArray(void *_array, void(*print)(void *));
//销毁数组
void Destroy_DynamicArray(void *_array);


