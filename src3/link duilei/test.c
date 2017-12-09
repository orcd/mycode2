#include "LinkQueue.h"
#include <stdio.h>

struct Person
{
	struct LinkNode node;
	char name[20];
	int age;
};

int main()
{
	struct Person p1 = { NULL, "a", 18 };
	struct Person p2 = { NULL, "b", 19 };
	struct Person p3 = { NULL, "c", 20 };
	struct Person p4 = { NULL, "d", 21 };
	struct Person p5 = { NULL, "e", 22 };

	void *queue = Init_LinkQueue();

	Push_LinkQueue(queue, &p1);
	Push_LinkQueue(queue, &p2);
	Push_LinkQueue(queue, &p3);
	Push_LinkQueue(queue, &p4);
	Push_LinkQueue(queue, &p5);

	while (!IsEmpty_LinkQueue(queue))
	{
		struct Person *p = (struct Person *)Front_LinkQueue(queue);
		printf("%s,%d,size=%d\n", p->name, p->age, Size_LinkQueue(queue));
		Pop_LinkQueue(queue);
	}

	Destroy_LinkQueue(queue);
	return 0;
}