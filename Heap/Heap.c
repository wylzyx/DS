
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "Heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	assert(hp && a);
	int i;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* n);
	for (i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}
	//调整, 从最后一棵子树开始调整
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(hp->_a, n, i);
	}

	hp->_size = hp->_capacity = n;
}
void HeapEmptyInit(Heap* hp)
{
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

void Swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void ShiftDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//当前节点是否有孩子
	while (child < n)
	{
		//是否有右孩子，如果有，两者中选最大
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		//孩子是否大于父亲
		if (a[child] > a[parent])
		{
			//交换孩子和父亲的值
			Swap(&a[child], &a[parent]);
			//更新下一次调整的位置
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			//以parent为根的子树已经是一个大堆，结束调整
			break;
		}
	}
}

void shiftUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	//while (parent >= 0)
	while (child > 0)
	{
		//判断孩子是否大于父亲
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void HeapDestory(Heap* hp)
{
	if (hp->_a)
	{
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	//检查容量
	if (hp->_size == hp->_capacity)
	{
		int newC = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, newC * sizeof(HPDataType));
		hp->_capacity = newC;
	}
	//1 .尾插，  2. 向上调整
	hp->_a[hp->_size] = x;
	++hp->_size;

	shiftUp(hp->_a, hp->_size, hp->_size - 1);
}

//删除堆顶元素， 最值
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp) == 0)
	{
		//交换: a[0] <--> a[size - 1]
		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		//尾删
		--hp->_size;
		ShiftDown(hp->_a, hp->_size, 0);
	}
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp && hp->_size);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
// 堆排序
void HeapSort(int* a, int n)
{
	//建堆
	int i, end;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(a, n, i);
	}
	//堆排序
	end = n - 1;
	while (end > 0)
	{
		//交换
		Swap(&a[0], &a[end]);
		//从堆顶向下调整
		ShiftDown(a, end, 0);
		--end;
	}
	
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	//建大堆，调整之后： hp->_a[] = {8，7，6，5，1，3};
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);

}

void TestHeap2()
{
	Heap hp;
	HeapEmptyInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);
	HeapPush(&hp, 5);
	HeapPush(&hp, 6);
	HeapPush(&hp, 7); 
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
}

void TestHeapSort()
{
	int i;
	int a[] = { 1, 5, 3, 8, 7, 6 };
	for (i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	//TestHeap();
	//TestHeap2();
	TestHeapSort();
	return 0;
}