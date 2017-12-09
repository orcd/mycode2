#include "DynamicArray.h"
#include <stdio.h>

typedef struct _Person
{
	char name[20];
	int age;
}Person;

void print(void *data)
{
	Person *p = (Person *)data;
	printf("%s,%d\n", p->name, p->age);
}

int compare(void *d1, void *d2)
{
	Person *p1 = (Person *)d1;
	Person *p2 = (Person *)d2;
	return p1->age == p2->age && (strcmp(p1->name, p2->name) == 0);
}
int main()
{
	Person p1 = { "zhangsan",18 };
	Person p2 = { "lisi", 19 };
	Person p3 = { "wangwu",20 };
	Person p4 = { "zhaoliu",21 };

	void *array = Init_DynamicArray();
	


	PushByPos_DynamicArray(array, 0, &p1); //18
	PushByPos_DynamicArray(array, 0, &p2); 
	Foreach_DynamicArray(array, print);// 19,18
	printf("-________________________-\n");
	PushBack_DynamicArray(array, &p3); //19,18,20
	PushFront_DynamicArray(array, &p4); //21,19,18,20
	Foreach_DynamicArray(array, print);
	printf("-________________________-\n");
	RemoveByPos_DynamicArray(array, 3); //21,19,18
	Person p5 = { "lisi",19 };
	RemoveByVal_DynamicArray(array, &p5, compare); //21,18
	Foreach_DynamicArray(array, print);
	printf("-________________________-\n");
	Person *data = (Person *)GetByPos_DynamicArray(array, 1);
	printf("data: %s,%d\n", data->name, data->age);
	printf("-________________________-\n");
	RemoveFront_DynamicArray(array); //20
	RemoveBack_DynamicArray(array); //
	Foreach_DynamicArray(array, print);

	Destroy_DynamicArray(array);
}