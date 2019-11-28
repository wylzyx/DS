#include "SeqList.h"

void testSeqList()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	/*SeqListInsert(&s, 0, 0);
	SeqListInsert(&s, 3, 100);

	SeqListInsert(&s, 5, 5);
	SeqListPrint(&s);*/

	//SeqListPopBack(&s);  // 123
	//SeqListPrint(&s);
	//SeqListPopBack(&s);  // 12
	//SeqListPrint(&s);
	//SeqListPopFront(&s); // 2
	//SeqListPrint(&s);
	//SeqListPopBack(&s);
	//SeqListPrint(&s);
	
	//SeqListPopFront(&s);
	/*SeqListPushFront(&s, 0);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);*/
	/*SeqListPopFront(&s);
	SeqListPrint(&s);*/
	//SeqListErase(&s, 0);  // 2 3 4
	//SeqListPrint(&s);
	//SeqListErase(&s, 1);  // 2 4
	//SeqListPrint(&s);
	//SeqListErase(&s, 1);  // 2
	//SeqListPrint(&s);
	//SeqListErase(&s, 0); // 
	//SeqListPrint(&s);
	//s._size = -1;
	//printf("%u\n", SeqListSize(&s));

	

	SeqListDestory(&s);

}

void testSeqL2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	/*SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);*/
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	printf("%d\n", SeqListBinaryFind(&s, 1));
	printf("%d\n", SeqListBinaryFind(&s, 100));
	//SeqListRemoveAll(&s, 1);
	//SeqListPrint(&s);
	SeqListDestory(&s);
}

int main()
{
	/*SeqList s;
	s._size = 0;*/
	//testSeqList();
	testSeqL2();
	//SeqListInit(s);
	return 0;
}