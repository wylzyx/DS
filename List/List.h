typedef int DataType;

typedef struct ListNode
{
	DataType _data;
	struct ListNode* _next;
	//新增
	struct ListNode* _prev;
} ListNode;

typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* lst);
void ListDestory(List* lst);

ListNode* CreatListNode(DataType x);

void ListPushBack(List* lst, DataType x); 
void ListPushFront(List* lst, DataType x);
void ListPopBack(List* lst);
void ListPopFront(List* lst);
//在pos前面插入数据
void ListInsert(List* lst, ListNode* pos, DataType x);
void ListErase(List* lst, ListNode* pos);

void ListPrint(List* lst);

