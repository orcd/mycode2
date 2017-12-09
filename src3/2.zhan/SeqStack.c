#include "SeqStack.h"

//��ʼ��
void * Init_SeqStack()
{
	struct SeqStack *stack = (struct SeqStack *)malloc(sizeof(struct SeqStack));
	for (int i = 0; i < MAX; ++i)
	{
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}
//��ջ
void Push_SeqStack(void *_stack, void *data)
{
	if (NULL == _stack)
		return;
	if (NULL == data)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	stack->data[stack->size++] = data;
}
//��ջ
void Pop_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	if (stack->size == 0)
		return;
	--stack->size;
}
//��ȡջ��Ԫ��
void * Top_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	if (stack->size == 0)
		return NULL;
	return stack->data[stack->size - 1];
}
//��ȡջ��С
int Size_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	return stack->size;
}
//�ж�ջ�Ƿ�Ϊ��
int IsEmpty_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	return !stack->size;
}
//����
void Destroy_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	free(stack);
}