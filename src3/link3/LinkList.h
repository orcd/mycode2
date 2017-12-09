#include <stdlib.h>

struct LinkNode
{
	struct LinkNode *next;
};

struct LinkList
{
	struct LinkNode header;
	int size;
};

//初始化
void * Init_LinkList();
//按位置插入
void PushByPos_LinkList(void *_list, int pos, struct LinkNode *data);
//头部插入
void PushFront_LinkList(void *_list, struct LinkNode *data);
//尾部插入
void PushBack_LinkList(void *_list, struct LinkNode *data);
//值前插入
void PushByVal_LinkList(void *_list, struct LinkNode *oldval, struct LinkNode *newval, int(*compare)(void *, void *));
//按位置删除
void RemoveByPos_LinkList(void *_list, int pos);
//头部删除
void RemoveFront_LinkList(void *_list);
//尾部删除
void RemoveBack_LinkList(void *_list);
//按值删除
void RemoveByVal_LinkList(void *_list, struct LinkNode *data, int (*compare)(void *, void *));
//获取位置上的值 
void * GetByPos_LinkList(void *_list, int pos);
//遍历
void Foreach_LinkList(void *_list, void(*print)(void *));
//销毁
void Destroy_LinkList(void *_list);