#include "SeqStack.h"

//初始化
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
//入栈
void Push_SeqStack(void *_stack, void *data)
{
	if (NULL == _stack)
		return;
	if (NULL == data)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	stack->data[stack->size++] = data;
}
//出栈
void Pop_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	if (stack->size == 0)
		return;
	--stack->size;
}
//获取栈顶元素
void * Top_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	if (stack->size == 0)
		return NULL;
	return stack->data[stack->size - 1];
}
//获取栈大小
int Size_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	return stack->size;
}
//判断栈是否为空
int IsEmpty_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	return !stack->size;
}
//销毁
void Destroy_SeqStack(void *_stack)
{
	if (NULL == _stack)
		return;
	struct SeqStack *stack = (struct SeqStack *)_stack;
	free(stack);
}