#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include "Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}
void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;

}
//��β����Ԫ��
void QueuePush(Queue* q, DataType x)
{
	assert(q);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;

	//�ж��Ƿ�Ϊ��һ�������Ԫ��
	if (q->_front == NULL)
	{
		q->_front = q->_rear = newNode;
	}
	else
	{
		q->_rear->_next = newNode;
		q->_rear = q->_rear->_next;
	}
}
//��ͷɾ��Ԫ��
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		//ɾ��������
		free(q->_front);
		q->_front = next;
		//ɾ����Ϊ���һ��Ԫ��
		if (q->_front == NULL)
			q->_rear = NULL;
	}
}
//��ȡ��ͷԪ��
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
//��ȡ��βԪ��
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}
int QueueSize(Queue* q)
{
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		++n;
		cur = cur->_next;
	}
	return n;
}

void QueuePrint(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");

}

void testQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePrint(&q);
	/*QueuePop(&q);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);*/
	QueueDestroy(&q);


}

//int main()
//{
//	testQueue();
//	return 0;
//}

