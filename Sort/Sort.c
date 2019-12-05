#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
//时间： O(N^2)
//空间： O(1)
//稳定性：稳定
//适合场景：接近有序的序列， 时间复杂度趋近于O(N), 
//         对于有序的序列， 时间复杂度O(N)
void InsertSort(int* a, int n)
{
	assert(a);
	int i;
	for (i = 0; i < n - 1; ++i)
	{
		//单个元素的排序
		//找到已经排好序的最后一个元素的位置
		int end = i;
		//把end + 1 位置的元素插入到合适的位置
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		//找到合适的位置
		a[end + 1] = tmp;
	}
	
}

// 时间： O(N^1.3 ~ N^2)
// 空间： O(1)
// 稳定性：不稳定
void ShellSort(int* a, int n)
{
	int gap = n;
	int i;
	//int num;
	//for (; gap >= 1; gap -= num) // 预排序的次数
	//for (num = 0; num < gap; ++num)  // 待排序的组别
	while (gap > 1)
	{
		//gap  > 1  ---> 预排序过程
		// gap = 1  ---> 排序过程
		gap = gap / 3 + 1;  //保证最后一次gap为1的插入排序
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
	
	
}

void  Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 时间： O(N^2)
// 空间： O(1)
// 稳定性：可以变成稳定的
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//每次选一个最大的和最小的，放到相应的位置
		int i, max, min;
		max = min = begin;
		//小的先第一个， 大的选最后一个
		for (i = begin; i <= end; ++i)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] >= a[max])
				max = i;
		}
		//min --> begin    max ---> end
		Swap(&a[begin], &a[min]);
		//判断最大元素的位置是否发生变化
		if (max == begin)
			max = min;
		Swap(&a[end], &a[max]);
		begin++;
		--end;
	}
	
}

void ShiftDown(int* a, int n, int root)
{
	int child = root * 2 + 1;
	int parent = root;
	while (child < n){
		if (child + 1 < n){
			if (a[child] < a[child + 1]){
				child += 1;
			}
		}	
		if (a[parent] < a[child]){
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			//parent = parent * 2 + 1;
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//建堆, 最后一棵子树开始： (n - 2) / 2
	int i,end;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(a, n, i);
	}
	//排序: 1. swap   2.shiftdown
	end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		ShiftDown(a, end, 0);
		--end;
	}
	
}
//时间：O(N ~  N^2)
//空间：O(1)
//稳定性：稳定
void BubbleSort(int* a, int n)
{
	for (int i = n; i > 0; i--)
	{
		int flag = 0;
		for (int j = 1; j < i; j++)
		{
			if (a[j - 1] > a[j])
			{
				//flag: 标记一次的冒泡过程是否发生元素交换
				flag = 1;
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
			
		}
		//如果没有发生元素交换，提前结束
		if (flag == 0)
			break;
	}
}

//三数取中法: 保证每次的划分均衡
int getMid(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
			return mid;
		else
		{
			// mid > left, right
			if (a[left] > a[right])
				return left;
			else
				return right;
		}
	}
	else
	{
		// mid <= left
		if (a[left] < a[right])
			return left;
		else
		{
			//left >= right, mid
			if (a[mid] > a[right])
				return mid;
			else
				return right;
		}
	}
}

//快排的一次排序：确定基准值的位置
int PartSort(int* a, int left, int right)
{
	//三数取中
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int key = a[left];
	int start = left;
	//寻找大小元素交换
	while (left < right)
	{
		// 先从右边找小于key的值
		while (left < right && a[right] >= key)
			--right;
		//从左边找大于key的值
		while (left < right && a[left] <= key)
			++left;

		Swap(&a[left], &a[right]);
	}

	//key的位置确定: left right相遇的位置
	Swap(&a[start], &a[left]);
	return left;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int key = a[left];
	while (left < right)
	{
		//从右边找小
		while (left < right && a[right] >= key)
			--right;
		//填坑
		a[left] = a[right];
		//从左找大的
		while (left < right && a[left] <= key)
			++left;
		//填坑
		a[right] = a[left];
	}
	//存放key
	a[left] = key;
	return left;
}

//前后指针
int PartSort3(int* a, int left, int right)
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	//最后一个小于key的位置
	int prev = left;
	//下一个小于key的位置
	int cur = left + 1;
	int key = a[left];
	while (cur <= right)
	{
		// 如果下一个小于key的位置于上一个小于key的位置不连续
		// 说明中间有大于key的值，进行交换，大-->向后移动， 小 <---向前移动
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[prev], &a[left]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	//小区间优化： 小区间不调用递归
	else if (right - left + 1 < 5)
	{
		InsertSort(a + left, right - left + 1);
	}
	else{
		/*int mid = PartSort(a, left, right);*/
		//int mid = PartSort2(a, left, right);
		int mid = PartSort3(a, left, right);

		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
	
}

void QuickSortNoR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	if (left < right)
	{
		StackPush(&st, right);
		StackPush(&st, left);
	}
	while (StackEmpty(&st) == 0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		//划分当前区间
		int mid = PartSort3(a, begin, end);
		//划分左右子区间
		if (begin < mid - 1)
		{
			StackPush(&st, mid - 1);
			StackPush(&st, begin);
		}
		if (mid + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, mid + 1);
		}
	}

}

//时间： N * logN
//空间： N + logN ~ N
//稳定性：稳定

void  _MergeSort(int* a, int left, int right, int* tmp)
{
	//区间只剩一个元素，不需要分解和归并
	if (left >= right)
		return;
	//分解
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//归并 [left, mid] ,  [mid + 1, right]
	int begin1 = left, end1 = mid, 
		begin2 = mid + 1, end2 = right;   // begin1  ~  end2  ->left ~ right
	int tmpindex = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		// <: 不稳定
		// <= : 稳定
		if (a[begin1] <= a[begin2])
		{
			tmp[tmpindex++] = a[begin1++];
		}
		else
		{
			tmp[tmpindex++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[tmpindex++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[tmpindex++] = a[begin2++];
	}

	//拷贝到原有数组对应区间
	memcpy(a + left, tmp + left, (right - left + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(int));
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//时间： O(max(N, 范围))
//空间： O(范围）
void CountSort(int* a, int n)
{
	//范围： 0  ~ 最大值   90   100
	//范围： 最小值  ~  最大值
	int min = a[0], max = a[0];
	int i;
	//获取数据的范围
	for (i = 1; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	//
	int range = max - min + 1;
	int* CountArr = (int*)malloc(sizeof(int)* range);
	memset(CountArr, 0, sizeof(int)* range);
	//计数
	for (i = 0; i < n; ++i)
	{
		CountArr[a[i] - min]++;
	}
	//排序
	int index = 0;
	for (i = 0; i < range; ++i)
	{
		while (CountArr[i]--)
		{
			a[index++] = i + min;
		}	
	}
}

void PrintArray(int* a, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void testInsertSort()
{
	int a[10] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void testShellSort()
{
	int a[10] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void testSelectSort()
{
	int a[10] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void testHeapSort()
{
	int a[10] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void testBubbleSort()
{
	int a[10] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void testQuickSort()
{
	int a[10] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	QuickSortNoR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void testMergeSort()
{
	int a[10] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void testCountSort()
{
	int a[10] = { 1, 10, 8, 9, 3, 2, 4, 5, 7, 6 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	CountSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

//int main()
//{
//	int n;
//	qsort(values, 6, sizeof(int), compare);
//
//}
void testSort()
{
	srand(time(NULL));
	int i, num;
	scanf("%d", &num);

	int* arr1 = (int*)malloc(sizeof(int)* num);
	int* arr2 = (int*)malloc(sizeof(int)* num);
	int* arr3 = (int*)malloc(sizeof(int)* num);
	int* arr4 = (int*)malloc(sizeof(int)* num);
	int* arr5 = (int*)malloc(sizeof(int)* num);
	int* arr6 = (int*)malloc(sizeof(int)* num);
	int* arr7 = (int*)malloc(sizeof(int)* num);
	int* arr8 = (int*)malloc(sizeof(int)* num);

	for (i = 0; i < num; ++i)
	{
		arr1[i] = rand();
	}
	memcpy(arr2, arr1, sizeof(int)* num);
	memcpy(arr3, arr1, sizeof(int)* num);
	memcpy(arr4, arr1, sizeof(int)* num);
	memcpy(arr5, arr1, sizeof(int)* num);
	memcpy(arr6, arr1, sizeof(int)* num);
	memcpy(arr7, arr6, sizeof(int)* num);
	memcpy(arr8, arr6, sizeof(int)* num);

	size_t begin1, end1, begin2, end2, begin3, end3,
		begin4, end4, begin5, end5, begin6, end6, begin8, end8;

	//PrintArray(arr1, num);

	begin1 = clock();
	InsertSort(arr1, num);
	end1 = clock();
	printf("InsertSort: %d\n", end1 - begin1);
	//PrintArray(arr1, num);


	//PrintArray(arr2, num);

	begin2 = clock();
	ShellSort(arr2, num);
	end2 = clock();
	printf("ShellSort: %d\n", end2 - begin2);
	//PrintArray(arr2, num);

	begin1 = clock();
	InsertSort(arr2, num);
	end1 = clock();
	printf("InsertSort: %d\n", end1 - begin1);

	begin3 = clock();
	SelectSort(arr3, num);
	end3 = clock();
	printf("SelectSort: %d\n", end3 - begin3);

	/*begin3 = clock();
	SelectSort(arr3, num);
	end3 = clock();
	printf("SelectSort: %d\n", end3 - begin3);*/

	begin4 = clock();
	HeapSort(arr4, num);
	end4 = clock();
	printf("HeapSort: %d\n", end4 - begin4);

	begin5 = clock();
	BubbleSort(arr5, num);
	end5 = clock();
	printf("BubbleSort: %d\n", end5 - begin5);

	/*begin5 = clock();
	BubbleSort(arr5, num);
	end5 = clock();
	printf("BubbleSort: %d\n", end5 - begin5);
	*/
	begin6 = clock();
	QuickSort(arr6, 0, num - 1);
	end6 = clock();
	printf("QuickSort: %d\n", end6 - begin6);

	//begin6 = clock();
	//QuickSort(arr6, 0, num - 1);
	////qsort(arr6, num, sizeof(int), compare);
	//end6 = clock();
	//printf("QuickSort: %d\n", end6 - begin6);

	begin6 = clock();
	QuickSortNoR(arr7, 0, num - 1);
	//qsort(arr6, num, sizeof(int), compare);
	end6 = clock();
	printf("QuickSortNoR: %d\n", end6 - begin6);

	begin8 = clock();
	MergeSort(arr8, num);
	end8 = clock();
	printf("MergeSort: %d\n", end8 - begin8);
	

}



int main()
{
	/*testInsertSort();
	testShellSort();*/
	
	//testSelectSort();
	//testHeapSort();
	//testBubbleSort();
	//testQuickSort();
	//testMergeSort();
	testCountSort();

	//testSort();
	return 0;
}