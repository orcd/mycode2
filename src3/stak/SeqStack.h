#include <stdlib.h>

#define MAX 1024

struct SeqStack
{
	void *data[MAX];
	int size;
};

//初始化
void * Init_SeqStack();
//入栈
void Push_SeqStack(void *_stack, void *data);
//出栈
void Pop_SeqStack(void *_stack);
//获取栈顶元素
void * Top_SeqStack(void *_stack);
//获取栈大小
int Size_SeqStack(void *_stack);
//判断栈是否为空
int IsEmpty_SeqStack(void *_stack);
//销毁
void Destroy_SeqStack(void *_stack);