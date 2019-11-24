typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapEmptyInit(Heap* hp);
void ShiftDown(HPDataType* a, int n, int root);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
// ∂—≈≈–Ú
void HeapSort(int* a, int n);
void TestHeap();