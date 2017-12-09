#include "LinkList.h"
#include <stdio.h>

struct Person
{
	struct LinkNode node;
	char name[20];
	int age;
};

int compare(void *d1, void *d2)
{
	struct Person *p1 = (struct Person *)d1;
	struct Person *p2 = (struct Person *)d2;
	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void print(void *data)
{
	struct Person *p = (struct Person *)data;
	printf("%s,%d\n", p->name, p->age);
}

int main()
{
	struct Person p1 = { NULL, "a", 18 };
	struct Person p2 = { NULL, "b", 19 };
	struct Person p3 = { NULL, "c", 20 };
	struct Person p4 = { NULL, "d", 21 };
	struct Person p5 = { NULL, "e", 22 };

	void *list = Init_LinkList();

	PushByPos_LinkList(list, 0, &p1); // 18
	PushFront_LinkList(list, &p2); // 19, 18
	PushBack_LinkList(list, &p3); //19,18,20
	PushByVal_LinkList(list, &p1, &p4, compare); //19,21,18, 20
	PushByPos_LinkList(list, 2, &p5); // 19, 21, 22, 18, 20

	Foreach_LinkList(list, print);// 19, 21, 22, 18, 20
	printf("-----------------------------------\n");

	RemoveFront_LinkList(list);
	Foreach_LinkList(list, print);//  21, 22, 18, 20
	printf("-----------------------------------\n");

	RemoveBack_LinkList(list);
	Foreach_LinkList(list, print);//  21, 22, 18
	printf("-----------------------------------\n");

	RemoveByPos_LinkList(list, 1);
	Foreach_LinkList(list, print);//  21,  18
	printf("-----------------------------------\n");

	struct Person *p = (struct Person *)GetByPos_LinkList(list, 1);
	printf("%s,%d\n", p->name, p->age); // 18
	printf("-----------------------------------\n");

	RemoveByVal_LinkList(list, &p1, compare);
	Foreach_LinkList(list, print);//  21
	printf("-----------------------------------\n");

	Destroy_LinkList(list);
	return 0;
}