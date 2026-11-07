 //栈的初始化


#include<stdio.h>
#include <cstdlib>
#define MAXSIZE = 100;
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int top;
} Stack; 

//栈的初始化
void initstack(Stack* s) {
	s->top = -1;
}
//判断是或否为空 
int isEmpty(Stack* s) {
	if (*s == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}	

}//入栈
int push(Stack* s, ElemType e)
{
	if (s->top >= MAXSIZE - 1)
	{
		printf("满了");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}
//出栈(本质是覆盖）
ElemType pop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}
//获取栈顶元素
ElemType getpop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];

	return 1;
}




//栈的顺序结构初始化之动态内存分配
typedef struct {
	ElemType* data;//注意是指针，和上面的不一样了
	int top;
}Stack;
Stack* initStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;
	return s;
}




 

//栈的链式结构实现
typedef int ElemType;
typedef struct stack
{
	ElemType data;
	struct stack * next;
}Stack;




//栈的顺序结构
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

//初始化
void initQueue(Queue *Q)
{

	Q->front = 0;
	Q->rear = 0;
}
int isEmpty(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		printf("空");
		return 1;
	}
	else {
		return 0;
	}
}
//出队
ElemType dequeue(Queue* Q) {
	if (Q->front == Q->rear)
	{
		printf("空");
		return 0;
	}
	ElemType e = Q->data[Q->front];
	Q->front++;
	return e;
}
//入队
int queueFull(Queue* Q)
{
	if (Q->front > 0)
	{
		int step = Q->front;
		for (int i = Q->front;i <= rear;i++)
		{
			Q->data[i - stemp] = Q->data[i];
		}
		Q->front = 0;
		Q->rear = Q->rear - stemp;
		return 1;
	}else
	{
		printf("真的满了");
		return 0;
	}
}
//队列的链式结构
typedef struct QueueNode
{
	ElemType data;
struct QueueNode* next;
}QueueNode;
typedef struct
{
	QueueNode* front;
	QueueNode* rear;
}Queue;
//先建立结点，然后再建立一个结构体，结构体里面是两个节点。


//队列的初始化
Queue* initQueue()
{
	Queue* e = (Queue*)malloc(sizeof(Queue));
	QueueNode* node =(QueueNode*) malloc(sizeof(QueueNode));
	node->data = 0;
	node->next = NULL;
	e->front = node;
	e->rear = node;
	return e;
}
//入队
void equeue(Queue* q, ElemType e)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;
	q->rear->next = node;
	q->rear = node;
}

//出队
int deque(Queue* q, ElemType* e)
{
	QueueNode* node = q->front->next;
	q->front->next = node->next;
	*e = node->data;
	if (node == q->rear)//剩下一个元素的时候
	{
		q->rear = q->front;
	}
	free(node);
	return 1;
}

