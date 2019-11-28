//#define N 100
//typedef int DataType;
//
//typedef struct SeqList
//{
//	DataType _array[N];
//}SeqList;
#include <stdio.h>
typedef int DataType;

typedef struct SeqList
{
	DataType* _array;
	size_t _size;  // 实际存放的元素个数
	size_t _capacity;  //开辟空间的大小
}SeqList;

void SeqListInit(SeqList* sl);
void SeqListDestory(SeqList* sl);

void SeqListCheckCapacity(SeqList* sl);

//增删查改
void SeqListPushBack(SeqList* sl, DataType x);
void SeqListPushFront(SeqList* sl, DataType x);
// pos前面
void SeqListInsert(SeqList* sl, size_t pos, DataType x);

void SeqListPopBack(SeqList* sl);
void SeqListPopFront(SeqList* sl);
// 删除当前pos数据
void SeqListErase(SeqList* sl, size_t pos);

size_t SeqListFind(SeqList* sl, DataType x);

size_t SeqListModify(SeqList* sl, size_t pos, DataType x);

void SeqListPrint(SeqList* sl);

size_t SeqListSize(SeqList* sl);

DataType SeqListAt(SeqList* sl, size_t pos);

void SeqListRemoveAll(SeqList* sl, DataType x);

void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, DataType x);




