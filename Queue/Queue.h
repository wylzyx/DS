
//单链表实现队列
typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);
//队尾插入元素
void QueuePush(Queue* q, DataType x);
//队头删除元素
void QueuePop(Queue* q);
//获取队头元素
DataType QueueFront(Queue* q);
//获取队尾元素
DataType QueueBack(Queue* q);

int QueueEmpty(Queue* q);
int QueueSize(Queue* q);

void QueuePrint(Queue* q);