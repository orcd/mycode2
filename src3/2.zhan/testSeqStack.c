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
		//����������ţ�ֱ��ѹջ
		if (IsLeft(*p))
		{
			Push_SeqStack(stack, p);
			
		}
		else if(IsRight(*p))
		{
			//����������ţ������������ջΪ�մ���ƥ��ʧ�ܣ�ջ��Ϊ�մ�ջ�е���һ��������
			if (IsEmpty_SeqStack(stack))
			{
				//��ӡ������Ϣ
				PrintError(str, "Error:û��ƥ�䵽������", p);
			}
			else
			{
				Pop_SeqStack(stack);
			}
		}
		++p;
	}

	//�ж�ջ�Ƿ�Ϊ�գ����Ϊ�գ�����ƥ����ϣ������Ϊ�գ�����ջ�е�������û��ƥ�䵽������
	while (!IsEmpty_SeqStack(stack))
	{
		PrintError(str, "Error:û��ƥ�䵽������", (char *)Top_SeqStack(stack));
		Pop_SeqStack(stack);
	}
}

int main()
{
	test();
	return 0;
}