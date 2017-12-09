#include <stdlib.h>

struct LinkNode
{
	struct LinkNode *next;
};

struct LinkQueue
{
	struct LinkNode header;
	int size;
	struct LinkNode *rear;
};

//初始化
void * Init_LinkQueue();
//入队 
void Push_LinkQueue(void *_queue, void *data);
//出队
void * Pop_LinkQueue(void *_queue);
//队首
void * Front_LinkQueue(void *_queue);
//队尾
void * Back_LinkQueue(void *_queue);
//队列大小
int Size_LinkQueue(void *_queue);
//判断队列为空
int IsEmpty_LinkQueue(void *_queue);
//销毁
void Destroy_LinkQueue(void *_queue);