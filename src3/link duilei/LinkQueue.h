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

//��ʼ��
void * Init_LinkQueue();
//��� 
void Push_LinkQueue(void *_queue, void *data);
//����
void * Pop_LinkQueue(void *_queue);
//����
void * Front_LinkQueue(void *_queue);
//��β
void * Back_LinkQueue(void *_queue);
//���д�С
int Size_LinkQueue(void *_queue);
//�ж϶���Ϊ��
int IsEmpty_LinkQueue(void *_queue);
//����
void Destroy_LinkQueue(void *_queue);