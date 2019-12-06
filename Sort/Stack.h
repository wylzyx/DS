#include <stdio.h>
//À≥–Ú±Ì µœ÷’ª
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
