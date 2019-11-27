#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>
typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* st);
void StackDestory(Stack* st);

void StackPush(Stack* st, DataType x);
void StackPop(Stack* st);

DataType StackTop(Stack* st);
size_t StackSize(Stack* st);
int StackEmpty(Stack* st);

void StackPrint(Stack* st);

//顺序表实现栈
void StackInit(Stack* st)
{
	assert(st);
	//空栈
	st->_a = NULL;
	st->_top = st->_capacity = 0;
}
void StackDestory(Stack* st){
	free(st->_a);
}

void StackPush(Stack* st, DataType x)
{
	assert(st);
	//入栈： 顺序表尾插
	//检查容量
	if (st->_top == st->_capacity)
	{
		size_t newC = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		st->_a = (DataType*)realloc(st->_a, newC * sizeof(DataType));
		st->_capacity = newC;
	}
	//插入
	st->_a[st->_top++] = x;
}
void StackPop(Stack* st)
{
	//出栈： 尾删
	assert(st);
	if (st->_top)
		--st->_top;

}

DataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top - 1];
}
size_t StackSize(Stack* st)
{
	return st->_top;
}
int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 1 : 0;
}


typedef struct {
	Stack normStack;
	Stack minStack;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack *S;
	S = (MinStack *)malloc(sizeof(MinStack));
	StackInit(&S->normStack);
	StackInit(&S->minStack);
	return S;
}

void minStackPush(MinStack* obj, int x) {
	StackPush(&obj->normStack, x);
	if (!StackSize(&obj->minStack))
		StackPush(&obj->minStack, x);
	else if (x <= StackTop(&obj->minStack)){
		StackPush(&obj->minStack, x);
	}
}

void minStackPop(MinStack* obj) {
	if (~StackEmpty(&obj->normStack))
	{
		if (StackTop(&obj->minStack) == StackTop(&obj->normStack))
			StackPop(&obj->minStack);
		StackPop(&obj->normStack);
	}

}

int minStackTop(MinStack* obj) {
	if (~StackEmpty(&obj->normStack))
		return StackTop(&obj->normStack);
	return 0;
}

int minStackGetMin(MinStack* obj) {
	if (~StackEmpty(&obj->minStack))
		return StackTop(&obj->minStack);
	return 0;
}

void minStackFree(MinStack* obj) {
	StackDestory(&obj->normStack);
	StackDestory(&obj->minStack);
	free(obj);
}

typedef struct {
	int* _a;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->_front == obj->_rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->_rear + 1) % (obj->_k + 1)
		== obj->_front;
}

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	mq->_a = (int*)malloc(sizeof(int)* (k + 1));
	mq->_front = mq->_rear = 0;
	mq->_k = k;
	return mq;

}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//队列是否已满
	if (myCircularQueueIsFull(obj))
		return false;
	//队尾插入
	obj->_a[obj->_rear] = value;
	//更新队尾指针
	obj->_rear++;
	if (obj->_rear == obj->_k + 1)
		obj->_rear = 0;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	//删除队头元素
	++obj->_front;
	if (obj->_front == obj->_k + 1)
		obj->_front = 0;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->_a[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	//rear - 1 : 最后一个元素， 队尾元素
	if (obj->_rear == 0)
		return obj->_a[obj->_k];
	else
		return obj->_a[obj->_rear - 1];
}

///** Checks whether the circular queue is empty or not. */
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//	return obj->_front == obj->_rear;
//}
//
///** Checks whether the circular queue is full or not. */
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//	return (obj->_rear + 1) % (obj->_k + 1)
//		== obj->_front;
//}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_a);
	free(obj);
}

int main()
{
	//["MinStack","push","push","push","getMin","pop","top","getMin"]
	//[[], [-2], [0], [-3], [], [], [], []]
	int ret = 0;
	MinStack* ms = minStackCreate();
	minStackPush(ms, -2);
	minStackPush(ms, 0);
	minStackPush(ms, -3);
	ret = minStackGetMin(ms);
	minStackPop(ms);
	ret = minStackTop(ms);
	ret = minStackGetMin(ms);
	return 0;
}