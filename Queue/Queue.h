
//������ʵ�ֶ���
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
//��β����Ԫ��
void QueuePush(Queue* q, DataType x);
//��ͷɾ��Ԫ��
void QueuePop(Queue* q);
//��ȡ��ͷԪ��
DataType QueueFront(Queue* q);
//��ȡ��βԪ��
DataType QueueBack(Queue* q);

int QueueEmpty(Queue* q);
int QueueSize(Queue* q);

void QueuePrint(Queue* q);