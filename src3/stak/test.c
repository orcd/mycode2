#include <stdio.h>
#include "SeqStack.h"

struct Person
{
	char name[20];
	int age;
};

int main1()
{
	struct Person p1 = { "a", 18 };
	struct Person p2= { "b", 19 };
	struct Person p3 = { "c", 20 };
	struct Person p4 = { "d", 21 };
	struct Person p5 = { "e", 22 };

	void *stack = Init_SeqStack();

	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);

	struct Person *p = (struct Person *)Top_SeqStack(stack);
	printf("%s,%d\n", p->name, p->age);

	Pop_SeqStack(stack);

	while (!IsEmpty_SeqStack(stack))
	{
		struct Person *p = (struct Person *)Top_SeqStack(stack);
		printf("%s,%d,size=%d\n", p->name, p->age, Size_SeqStack(stack));

		Pop_SeqStack(stack);
	}

	Destroy_SeqStack(stack);
	return 0;
}