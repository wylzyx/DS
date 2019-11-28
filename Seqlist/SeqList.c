#include "SeqList.h"
#include <assert.h>
#include <malloc.h>
void SeqListInit(SeqList* sl)
{
	assert(sl);
	sl->_array = NULL;
	sl->_size = 0;
	sl->_capacity = 0;
}

void SeqListDestory(SeqList* sl)
{
	assert(sl);
	if (sl->_array)
	{
		free(sl->_array);
		sl->_array = NULL;
		sl->_capacity = sl->_size = 0;
	}
}

void SeqListCheckCapacity(SeqList* sl)
{
	assert(sl);
	if (sl->_size == sl->_capacity)
	{
		size_t newCacacity = (sl->_capacity == 0 ? 5 : 2 * sl->_capacity);
		//malloc ����Ŀռ䣬 �������ݵ��¿ռ䣬 �ͷ�ԭ�пռ�
		//realloc:
		sl->_array = (DataType*)realloc(sl->_array, newCacacity * sizeof(DataType));
		//����ʧ��
		assert(sl->_array);
		//��������
		sl->_capacity = newCacacity;
	}
}

//��ɾ��� 
// β��
void SeqListPushBack(SeqList* sl, DataType x)
{
	/*assert(sl);
	SeqListCheckCapacity(sl);
	sl->_array[sl->_size] = x;
	++sl->_size;*/
	SeqListInsert(sl, sl->_size, x);
}
//ͷ��
void SeqListPushFront(SeqList* sl, DataType x)
{
	//assert(sl);
	////�������
	//SeqListCheckCapacity(sl);
	////�ƶ�Ԫ�أ� �Ӻ���ǰ
	//size_t end = sl->_size;
	//while (end > 0)
	//{
	//	sl->_array[end] = sl->_array[end - 1];
	//	--end;
	//}
	////����
	//sl->_array[0] = x;
	//++sl->_size;

	SeqListInsert(sl, 0, x);

}
// posǰ��
void SeqListInsert(SeqList* sl, size_t pos, DataType x)
{
	//pos : 0 --> ͷ��   _size --> β��
	// posλ�õ���Ч��
	assert(sl && pos <= sl->_size);
	SeqListCheckCapacity(sl);
	size_t end = sl->_size;
	//����ƶ�һ��λ�� :  end >= pos--> ����ѭ��
	while (end > pos)
	{
		sl->_array[end] = sl->_array[end - 1];
		--end;
	}
	//��posλ�ò���Ԫ��
	sl->_array[pos] = x;
	++sl->_size;
}

void SeqListPopBack(SeqList* sl)
{
	/*assert(sl);

	if (sl->_size > 0)
	--sl->_size;*/
	SeqListErase(sl, sl->_size - 1);
}
void SeqListPopFront(SeqList* sl)
{
	//assert(sl && sl->_size > 0);
	//size_t start = 0;
	////�ƶ�Ԫ��
	//while (start < sl->_size - 1)
	//{
	//	sl->_array[start] = sl->_array[start + 1];
	//	++start;
	//}
	//// �޸�size
	//--sl->_size;
	SeqListErase(sl, 0);
}
// ɾ����ǰpos����
void SeqListErase(SeqList* sl, size_t pos)
{
	assert(sl && pos < sl->_size);
	//�ƶ�Ԫ�أ� ǰ --> ��
	size_t start = pos + 1;
	while (start < sl->_size)
	{
		sl->_array[start - 1] = sl->_array[start];
		++start;
	}
	--sl->_size;
}

size_t SeqListFind(SeqList* sl, DataType x)
{
	assert(sl);
	for (size_t i = 0; i < sl->_size; ++i)
	{
		if (sl->_array[i] == x)
			return i;
	}
	return -1;
}

size_t SeqListModify(SeqList* sl, size_t pos, DataType x);

void SeqListPrint(SeqList* sl)
{
	assert(sl);
	for (size_t i = 0; i < sl->_size; ++i)
	{
		printf("%d ", sl->_array[i]);
		
	}
	printf("\n");
}

size_t SeqListSize(SeqList* sl)
{
	assert(sl);
	return sl->_size;
}

// a[pos]
DataType SeqListAt(SeqList* sl, size_t pos)
{
	assert(sl && pos < sl->_size);
	return sl->_array[pos];
}

void SeqListRemoveAll(SeqList* sl, DataType x)
{
	assert(sl);
	size_t index = 0;
	for (size_t i = 0; i < sl->_size; ++i)
	{
		if (sl->_array[i] != x)
		{
			sl->_array[index] = sl->_array[i];
			++index;
		}
			
	}
	sl->_size = index;
}


void SeqListBubbleSort(SeqList* sl)
{
	assert(sl);
	//����
	size_t end = sl->_size;
	while (end > 1)
	{
		//��������
		int flag = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (sl->_array[i - 1] > sl->_array[i])
			{
				flag = 1;
				DataType tmp = sl->_array[i - 1];
				sl->_array[i - 1] = sl->_array[i];
				//��������и����Ԫ��
				sl->_array[i] = tmp;
			}
		}
		if (flag == 0)
			break;

		--end;
	}
	
}
int SeqListBinaryFind(SeqList* sl, DataType x)
{
	assert(sl);
	size_t start = 0; 
	size_t end = sl->_size - 1;
	while (start <= end)
	{
		size_t mid = start + (end - start) / 2;
		if (sl->_array[mid] == x)
			return mid;
		else if (sl->_array[mid] > x)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return -1;
}
