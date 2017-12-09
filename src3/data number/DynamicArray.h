#pragma once
#include <stdlib.h>

typedef struct _DynamicArray
{
	void **data; //���ݴ洢�ռ�
	int capacity; //������������
	int size; //�����ʹ�ô�С
}DynamicArray;

//��ʼ��
void * Init_DynamicArray();
//��λ�ò���
void PushByPos_DynamicArray(void *_array,int pos, void *data);
//ͷ������
void PushFront_DynamicArray(void *_array, void *data);
//β������
void PushBack_DynamicArray(void *_array, void *data);
//��λ��ɾ��
void RemoveByPos_DynamicArray(void *_array, int pos);
//��ֵɾ��
void RemoveByVal_DynamicArray(void *_array, void *data, int(*compare)(void*, void*)); //�ص�����
//ͷ��ɾ��
void RemoveFront_DynamicArray(void *_array);
//β��ɾ��
void RemoveBack_DynamicArray(void *_array);
//��ȡ����
void * GetByPos_DynamicArray(void *_array, int pos);
//����
void Foreach_DynamicArray(void *_array, void(*print)(void *));
//��������
void Destroy_DynamicArray(void *_array);


