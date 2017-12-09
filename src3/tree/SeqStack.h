#include <stdlib.h>

#define MAX 1024

struct SeqStack
{
	void *data[MAX];
	int size;
};

//��ʼ��
void * Init_SeqStack();
//��ջ
void Push_SeqStack(void *_stack, void *data);
//��ջ
void Pop_SeqStack(void *_stack);
//��ȡջ��Ԫ��
void * Top_SeqStack(void *_stack);
//��ȡջ��С
int Size_SeqStack(void *_stack);
//�ж�ջ�Ƿ�Ϊ��
int IsEmpty_SeqStack(void *_stack);
//����
void Destroy_SeqStack(void *_stack);