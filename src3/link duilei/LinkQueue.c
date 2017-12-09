#include "LinkQueue.h"

//��ʼ��
void * Init_LinkQueue()
{
	struct LinkQueue *queue = (struct LinkQueue *)malloc(sizeof(struct LinkQueue));
	queue->header.next = NULL;
	queue->size = 0;
	queue->rear = &queue->header;
	return queue;
}
//��� 
void Push_LinkQueue(void *_queue, void *data)
{
	if (NULL == _queue)
		return;
	if (NULL == data)
		return;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	struct LinkNode *node = (struct LinkNode *)data;

	node->next = queue->rear->next;
	queue->rear->next = node;

	queue->rear = node;
	++queue->size;
}
//����
void * Pop_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	if (queue->size == 0)
		return;
	struct LinkNode *pDel = queue->header.next;
	queue->header.next = pDel->next;

	if (queue->size == 1)
		queue->rear = &queue->header;

	--queue->size;

	return pDel;
}
//����
void * Front_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	if (queue->size == 0)
		return NULL;
	return queue->header.next;
}
//��β
void * Back_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	if (queue->size == 0)
		return NULL;
	return queue->rear;
}
//���д�С
int Size_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	return queue->size;
}
//�ж϶���Ϊ��
int IsEmpty_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	return !queue->size;
}
//����
void Destroy_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	free(queue);
}