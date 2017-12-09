#include <stdio.h>
#include "SeqStack.h"

int IsLeft(char ch)
{
	return ch == '(';
}

int IsRight(char ch)
{
	return ch == ')';
}

void PrintError(const char *str, const char *errstr, char *p)
{
	printf("%s\n", errstr);
	printf("%s\n", str);
	int len = p - str;
	for (int i = 0; i < len; ++i)
	{
		printf(" ");
	}
	printf("A\n");
}

void test()
{
	void *stack = Init_SeqStack();

	const char *str = "5+5*(6)+9/3*1)-(1+3(";
	char *p = (char *)str;
	while (*p != '\0')
	{
		//如果是左括号，直接压栈
		if (IsLeft(*p))
		{
			Push_SeqStack(stack, p);
			
		}
		else if(IsRight(*p))
		{
			//如果是右括号，分两种情况，栈为空代表匹配失败，栈不为空从栈中弹出一个左括号
			if (IsEmpty_SeqStack(stack))
			{
				//打印错误信息
				PrintError(str, "Error:没有匹配到左括号", p);
			}
			else
			{
				Pop_SeqStack(stack);
			}
		}
		++p;
	}

	//判断栈是否为空，如果为空，代表匹配完毕，如果不为空，代表栈中的左括号没有匹配到右括号
	while (!IsEmpty_SeqStack(stack))
	{
		PrintError(str, "Error:没有匹配到右括号", (char *)Top_SeqStack(stack));
		Pop_SeqStack(stack);
	}
}

int main()
{
	test();
	return 0;
}