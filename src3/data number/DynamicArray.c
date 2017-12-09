#include "DynamicArray.h"

//��ʼ��
void * Init_DynamicArray()
{
	DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
	array->capacity = 10;
	array->size = 0;
	array->data = malloc(sizeof(void *) * array->capacity);
	return array;
}

//��λ�ò���
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
//ͷ������
void PushFront_DynamicArray(void *_array, void *data)
{
	return PushByPos_DynamicArray(_array, 0, data);
}
//β������
void PushBack_DynamicArray(void *_array, void *data)
{
	DynamicArray *array = (DynamicArray *)_array;
	return PushByPos_DynamicArray(array, array->size, data);
}
//��λ��ɾ��
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
//��ֵɾ��
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
//ͷ��ɾ��
void RemoveFront_DynamicArray(void *_array)
{
	return RemoveByPos_DynamicArray(_array, 0);
}
//β��ɾ��
void RemoveBack_DynamicArray(void *_array)
{
	DynamicArray *array = (DynamicArray *)_array;
	return RemoveByPos_DynamicArray(array, array->size - 1);
}
//��ȡ����
void * GetByPos_DynamicArray(void *_array, int pos)
{
	if (NULL == _array)
		return;
	DynamicArray *array = (DynamicArray *)_array;
	if (pos < 0 || pos >= array->size)
		return NULL;
	return array->data[pos];
}
//����
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
//��������
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
