#include <stdio.h>
#include "SeqStack.h"
#include <stdbool.h>


struct BiNode
{
	char data;
	struct BiNode *lChild;
	struct BiNode *rChild;
};

//二叉树递归遍历
void Foreach(struct BiNode *root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	Foreach(root->lChild);
	Foreach(root->rChild);
}

//求叶子节点数
int num = 0;

void CalcNodeCount(struct BiNode *root)
{
	if (NULL == root)
		return;
	if (root->lChild == NULL && root->rChild == NULL)
		num++;
	CalcNodeCount(root->lChild);
	CalcNodeCount(root->rChild);
}

//求树的高度
int CalcTreeHeight(struct BiNode *root)
{
	if (NULL == root)
		return 0;
	int lHeight = CalcTreeHeight(root->lChild);
	int rHeight = CalcTreeHeight(root->rChild);
	return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}
//拷贝二叉树
struct BiNode * CopyTree(struct BiNode *root)
{
	if (NULL == root)
		return NULL;
	struct BiNode * lChild = CopyTree(root->lChild);
	struct BiNode * rChild = CopyTree(root->rChild);
	struct BiNode *newNode = (struct BiNode *)malloc(sizeof(struct BiNode));
	newNode->data = root->data;
	newNode->lChild = lChild;
	newNode->rChild = rChild;
	return newNode;
}

//释放二叉树
void FreeTree(struct BiNode *root)
{
	if (NULL == root)
		return;
	FreeTree(root->lChild);
	FreeTree(root->rChild);
	free(root);
	root = NULL;
}

struct Info
{
	struct BiNode *node;
	bool flag;
};

struct Info * CreateInfo(struct BiNode *node)
{
	struct Info *info = (struct Info *)malloc(sizeof(struct Info));
	info->node = node;
	info->flag = false;
	return info;
}

//非递归遍历
void NoRecursive(struct BiNode *root)
{
	void *stack = Init_SeqStack(); //初始化栈
	//把根节点加上false属性入栈
	struct Info *info = CreateInfo(root);
	

	Push_SeqStack(stack, info);
	//循环从栈中弹出元素，直到栈为空
	while (!IsEmpty_SeqStack(stack))
	{
		//弹出元素
		struct Info *temp = (struct Info *)Top_SeqStack(stack);
		Pop_SeqStack(stack);
		//判断节点状态
		if (temp->flag)
		{
			//直接输出
			printf("%c ", temp->node->data);
			free(temp);
		}
		else
		{
			//把当前节点状态改为true，再放回栈中
			temp->flag = true;
			Push_SeqStack(stack, temp);
			//把右子节点入栈
			if (temp->node->rChild != NULL)
			{
				Push_SeqStack(stack, CreateInfo(temp->node->rChild));
			}
			//把左子节点入栈
			if (temp->node->lChild != NULL)
			{
				Push_SeqStack(stack, CreateInfo(temp->node->lChild));
			}
		}
	}

}

int main()
{
	struct BiNode node1 = { 'A', NULL, NULL };
	struct BiNode node2 = { 'B', NULL, NULL };
	struct BiNode node3 = { 'C', NULL, NULL };
	struct BiNode node4 = { 'D', NULL, NULL };
	struct BiNode node5 = { 'E', NULL, NULL };
	struct BiNode node6 = { 'F', NULL, NULL };
	struct BiNode node7 = { 'G', NULL, NULL };
	struct BiNode node8 = { 'H', NULL, NULL };

	node1.lChild = &node2;
	node1.rChild = &node6;

	node2.rChild = &node3;

	node3.lChild = &node4;
	node3.rChild = &node5;

	node6.rChild = &node7;

	node7.lChild = &node8;

	//Foreach(&node1);
	//CalcNodeCount(&node1);
	//printf("num=%d\n", num);

	//int height = CalcTreeHeight(&node1);
	//printf("height=%d\n", height);

	/*struct BiNode *root = CopyTree(&node1);
	Foreach(root);

	FreeTree(root);*/

	NoRecursive(&node1);
	return 0;
}