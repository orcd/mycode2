#include "LinkList.h"

//��ʼ��
void * Init_LinkList()
{
	struct LinkList *list = (struct LinkList *)malloc(sizeof(struct LinkList));
	list->header.next = NULL;
	list->size = 0;
	return list;
}
//��λ�ò���
void PushByPos_LinkList(void *_list, int pos, struct LinkNode *data)
{
	if (NULL == _list)
		return;
	if (NULL == data)
		return;
	struct LinkList *list = (struct LinkList *)_list;
	if (pos < 0 || pos > list->size)
		pos = list->size;
	struct LinkNode *p = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		p = p->next;
	}

	data->next = p->next;
	p->next = data;

	++list->size;
}
//ͷ������
void PushFront_LinkList(void *_list, struct LinkNode *data)
{
	if (NULL == _list)
		return;
	PushByPos_LinkList(_list, 0, data);
}
//β������
void PushBack_LinkList(void *_list, struct LinkNode *data)
{
	if (NULL == _list)
		return;
	struct LinkList *list = (struct LinkList *)_list;
	PushByPos_LinkList(list, list->size, data);
}
//ֵǰ����
void PushByVal_LinkList(void *_list, struct LinkNode *oldval, struct LinkNode *newval, int(*compare)(void *, void *))
{
	if (NULL == _list)
		return;
	if (NULL == oldval)
		return;
	if (NULL == newval)
		return;
	if (NULL == compare)
		return;
	struct LinkList *list = (struct LinkList *)_list;
	struct LinkNode *p = &list->header;
	while (p->next)
	{
		if (compare(p->next, oldval))
		{
			newval->next = p->next;
			p->next = newval;
			++list->size;
			break;
		}
		p = p->next;
	}

}
//��λ��ɾ��
void RemoveByPos_LinkList(void *_list, int pos)
{
	if (NULL == _list)
		return;
	struct LinkList *list = (struct LinkList *)_list;
	if (pos < 0 || pos >= list->size)
		return;
	struct LinkNode *p = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		p = p->next;
	}
	p->next = p->next->next;
	--list->size;
}
//ͷ��ɾ��
void RemoveFront_LinkList(void *_list)
{
	if (NULL == _list)
		return;
	RemoveByPos_LinkList(_list, 0);
}
//β��ɾ��
void RemoveBack_LinkList(void *_list)
{
	if (NULL == _list)
		return;
	struct LinkList *list = (struct LinkList *)_list;
	RemoveByPos_LinkList(_list, list->size - 1);
}
//��ֵɾ��
void RemoveByVal_LinkList(void *_list, struct LinkNode *data, int(*compare)(void *, void *))
{
	if (NULL == _list)
		return;
	if (NULL == data)
		return;
	struct LinkList *list = (struct LinkList *)_list;
	if (list->size == 0)
		return;
	struct LinkNode *p = &list->header;
	while (p->next)
	{
		if (compare(p->next, data))
		{
			p->next = p->next->next;
			--list->size;
			break;
		}
		p = p->next;
	}
}
//��ȡλ���ϵ�ֵ 
void * GetByPos_LinkList(void *_list, int pos)
{
	if (NULL == _list)
		return NULL;
	struct LinkList *list = (struct LinkList *)_list;
	if (pos < 0 || pos >= list->size)
		return NULL;
	struct LinkNode *p = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		p = p->next;
	}
	return p->next;
}
//����
void Foreach_LinkList(void *_list, void(*print)(void *))
{
	if (NULL == _list)
		return;
	if (NULL == print)
		return;
	struct LinkList *list = (struct LinkList *)_list;
	struct LinkNode *p = list->header.next;
	while (p)
	{
		print(p);
		p = p->next;
	}
}
//����
void Destroy_LinkList(void *_list)
{
	if (NULL == _list)
		return;
	struct LinkList *list = (struct LinkList *)_list;
	free(list);
}