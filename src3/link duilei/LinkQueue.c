#include "LinkQueue.h"

//初始化
void * Init_LinkQueue()
{
	struct LinkQueue *queue = (struct LinkQueue *)malloc(sizeof(struct LinkQueue));
	queue->header.next = NULL;
	queue->size = 0;
	queue->rear = &queue->header;
	return queue;
}
//入队 
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
//出队
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
//队首
void * Front_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	if (queue->size == 0)
		return NULL;
	return queue->header.next;
}
//队尾
void * Back_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	if (queue->size == 0)
		return NULL;
	return queue->rear;
}
//队列大小
int Size_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	return queue->size;
}
//判断队列为空
int IsEmpty_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	return !queue->size;
}
//销毁
void Destroy_LinkQueue(void *_queue)
{
	if (NULL == _queue)
		return NULL;
	struct LinkQueue *queue = (struct LinkQueue *)_queue;
	free(queue);
}