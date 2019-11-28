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
	size_t _size;  // ʵ�ʴ�ŵ�Ԫ�ظ���
	size_t _capacity;  //���ٿռ�Ĵ�С
}SeqList;

void SeqListInit(SeqList* sl);
void SeqListDestory(SeqList* sl);

void SeqListCheckCapacity(SeqList* sl);

//��ɾ���
void SeqListPushBack(SeqList* sl, DataType x);
void SeqListPushFront(SeqList* sl, DataType x);
// posǰ��
void SeqListInsert(SeqList* sl, size_t pos, DataType x);

void SeqListPopBack(SeqList* sl);
void SeqListPopFront(SeqList* sl);
// ɾ����ǰpos����
void SeqListErase(SeqList* sl, size_t pos);

size_t SeqListFind(SeqList* sl, DataType x);

size_t SeqListModify(SeqList* sl, size_t pos, DataType x);

void SeqListPrint(SeqList* sl);

size_t SeqListSize(SeqList* sl);

DataType SeqListAt(SeqList* sl, size_t pos);

void SeqListRemoveAll(SeqList* sl, DataType x);

void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, DataType x);




