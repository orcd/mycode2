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

//��ʼ��
void * Init_LinkList();
//��λ�ò���
void PushByPos_LinkList(void *_list, int pos, struct LinkNode *data);
//ͷ������
void PushFront_LinkList(void *_list, struct LinkNode *data);
//β������
void PushBack_LinkList(void *_list, struct LinkNode *data);
//ֵǰ����
void PushByVal_LinkList(void *_list, struct LinkNode *oldval, struct LinkNode *newval, int(*compare)(void *, void *));
//��λ��ɾ��
void RemoveByPos_LinkList(void *_list, int pos);
//ͷ��ɾ��
void RemoveFront_LinkList(void *_list);
//β��ɾ��
void RemoveBack_LinkList(void *_list);
//��ֵɾ��
void RemoveByVal_LinkList(void *_list, struct LinkNode *data, int (*compare)(void *, void *));
//��ȡλ���ϵ�ֵ 
void * GetByPos_LinkList(void *_list, int pos);
//����
void Foreach_LinkList(void *_list, void(*print)(void *));
//����
void Destroy_LinkList(void *_list);