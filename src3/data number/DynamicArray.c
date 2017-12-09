#include "DynamicArray.h"

//初始化
void * Init_DynamicArray()
{
	DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
	array->capacity = 10;
	array->size = 0;
	array->data = malloc(sizeof(void *) * array->capacity);
	return array;
}

//按位置插入
void PushByPos_DynamicArray(void *_array, int pos, void *data)
{
	if (NULL == _array)
		return;
	if (NULL == data)
		return;
	DynamicArray *array = (DynamicArray *)_array;
	if (pos < 0 || pos > array->size)
		pos = array->size;
	if (array->size == array->capacity)
	{
		void **newspace = (void **)malloc(sizeof(void*) * array->capacity * 2);
		memcpy(newspace, array->data, sizeof(void*) * array->capacity);
		free(array->data);
		array->data = newspace;
		array->capacity *= 2;
	}

	for (int i = array->size; i > pos; --i)
	{
		array->data[i] = array->data[i - 1];
	}
	array->data[pos] = data;
	++array->size;
}
//头部插入
void PushFront_DynamicArray(void *_array, void *data)
{
	return PushByPos_DynamicArray(_array, 0, data);
}
//尾部插入
void PushBack_DynamicArray(void *_array, void *data)
{
	DynamicArray *array = (DynamicArray *)_array;
	return PushByPos_DynamicArray(array, array->size, data);
}
//按位置删除
void RemoveByPos_DynamicArray(void *_array, int pos)
{
	if (NULL == _array)
		return;
	DynamicArray *array = (DynamicArray *)_array;
	if (array->size == 0)
		return;
	if (pos < 0 || pos >= array->size)
		return;
	for (int i = pos; i < array->size - 1; ++i)
	{
		array->data[i] = array->data[i + 1];
	}
	--array->size;
}
//按值删除
void RemoveByVal_DynamicArray(void *_array, void *data, int(*compare)(void*, void*))
{
	if (NULL == _array)
		return;
	if (NULL == data)
		return; 
	if (NULL == compare)
		return;

	DynamicArray *array = (DynamicArray *)_array;
	for (int i = 0; i < array->size; ++i)
	{
		if (compare(array->data[i], data))
		{
			RemoveByPos_DynamicArray(array, i);
			break;
		}
	}
}
//头部删除
void RemoveFront_DynamicArray(void *_array)
{
	return RemoveByPos_DynamicArray(_array, 0);
}
//尾部删除
void RemoveBack_DynamicArray(void *_array)
{
	DynamicArray *array = (DynamicArray *)_array;
	return RemoveByPos_DynamicArray(array, array->size - 1);
}
//获取数据
void * GetByPos_DynamicArray(void *_array, int pos)
{
	if (NULL == _array)
		return;
	DynamicArray *array = (DynamicArray *)_array;
	if (pos < 0 || pos >= array->size)
		return NULL;
	return array->data[pos];
}
//遍历
void Foreach_DynamicArray(void *_array, void(*print)(void *))
{
	if (NULL == _array)
		return;
	if (NULL == print)
		return;
	DynamicArray *array = (DynamicArray *)_array;
	for (int i = 0; i < array->size; ++i)
	{
		print(array->data[i]);
	}
}
//销毁数组
void Destroy_DynamicArray(void *_array)
{
	if (NULL == _array)
		return;
	DynamicArray *array = (DynamicArray *)_array;
	free(array->data);
	array->data = NULL;
	free(array);
	array = NULL;
}
