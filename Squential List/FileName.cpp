
#include<stdio.h>//顺序表的定义
#define MAXSIZE =100
#include<stdlib.h>
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;



//顺序表初始化：
void initList(SeqList* L)
{
	L->length = 0;
}

//顺序表添加元素（在尾部）
int appendElem(SeqList* L, ElemType e)
{
	if (L->length > =MAXSIZE)
	{
		printf("顺序表已满\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}
//顺序表的遍历
void listElem(SeqList* L)
{
	for (int i = 0;i < L->length;i++)
	{
		printf("%d", L->data[i]);
	}
}
//动态分配内存地址初始化
typedef struct {
	ElemType* data;
	int length;
};

SeqList* initList(SeqList* L) {
	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L->length = 0;
	return L;
}
//顺序表的查找
int findElem(SeqList* L, ElemType e)
{
	for (int i = 0;i < L->length;i++) {
		if (L->data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}
//顺序表之删除元素
int deleteElem(SeqList* L, int pos, ElemType* e)
{
	//pos是指定的位置
	*e = L->data[pos - 1];//记录删除的元素是什么，以便后续调用
	//减一是因为比如第二个元素在数组里的下标为一。
	if (pos < L->length) {

		for (int i = pos;i < L->length;i++)
		{
			L->data[i - 1] = L->data[i];
		}
	}
	L->length--;
	return 1;
}
//顺序表之插入元素
int insertElem(SeqList* L, int pos, ElemType e)
{
	if (pos <= L->length)
	{
		for (int i = L->length;i >=(pos - 1);i--)
		{
			L->data[i + 1] = L->data[i];
		}
		L->data[pos - 1] = e;
		L->length++;
	}
	return 1;
}
//链表存储结构
typedef int Elemtype;
typedef struct node {
	ElemType data;
	struct node* next;
}Node;
// 链表初始化
Node* initList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next= NULL;
	return head;
}
int main()
{
	Node* list = initList();
	return 1;
}
//单链表--头插法(插入的是倒序)
int insertHead(Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = L->next;
	L->next = p;
 }
int main()
{
	Node* list = initList();
	insertHead(list, 10);
	insertHead(list, 20);
}
////单链表的遍历
void* listNode(Node* L)
{
	Node* p = L->next; 
	while (p->next != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	 }
	printf("\n");
}
//单链表的尾插法
Node* get_tail(Node* L)//获取尾节点
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p; 
}
Node* insertTail(Node* tail, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	return p;

}
//在指定位置插入数据
int insertNode(Node* L, int pos, ElemType e)
{
	Node* p = L;
	int i = 0;
	//找到前驱节点
	while (i < pos - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}
	}
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}




////单链表删除节点
// 1.找到要删除的节点前驱
//	 2.用指针q去记录要删除的节点（后续要释放内存）
//	 3.通过改变p的后继节点来删除节点
//	 4.释放节点空间
int deleteNode(Node* L, int pos)
{
	Node* p = L;
	int i = 0;
	while (i < pos - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}
void freeList(Node* L)
{
	Node* p = L->next;
	Node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}
//使用双指针找到倒数第k个节点
int findNodeFS(Node* L, int k)
{
	Node* fast = L->next;
	Node* slow = L->next;
	for (int i = 0;i < k;i++)
	{
		fast = fast->next;
	}
	while(fast!=NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	printf("%d", slow->data);
}
//单链表的反转
Node* reverseList(Node* head)
{
	Node* first = NULL;
	Node* second = head->next;
	Node* third;
	while (second != NULL)
	{
		third = second->next;//先交换，再后移
		second->next = first;
		first = second;
		second = third;
	}
	Node* hd = initList();
	hd->next = first;//创造了头节点
	return hd;
}


//删除中间节点（快慢指针）
int delMiddleNode(Node* head)
{
	Node* fast = head->next;//一定是next啊，因为他判断的条件是next域是null
	Node* slow = head;
	while (fast != NULL&&fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* q = slow->next; 
	free(q);
	return 1;
}
//判断链表是否有环（快慢指针，能再次相遇就是有环）
int isCycle(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
			return 1;

		}
	}
	return 0;
}
Node* findBegin(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	while (fast != NULL&&fast->next !=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			Node* p = fast;
			int count = 1;
			while (p->next != slow)
			{
				count++;
				p = p->next;
			} 
			fast = head;
			slow = head;
			for (int i = 0;i < count;i++)
			{
				fast = fast->next;
			}
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
	}
}
//双向链表
typedef struct node {
	ElemType data;
	struct node* next;
	struct node* prev;
}Node;
//头插法
int insertHead(Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = L;
	p->next = L->next;
	if (L->next != NULL)
	{
		L->next->prev = p;
	}
}
//尾插法
Node* insertTail(Node* tail, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = tail;
	tail->next = p;
	p->next = NULL;
	return p;
}
//在指定位置插入数据
int insertNode(Node* L, int pos, Elemtype e)
{
	Node* p = L;
	int i = 0;
	while (i < pos - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			return 0;
		}
	}
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->prev = p;
	q->next = p->next;
	q->next->prev = q;
	return 1;
}
int deleteNode(Node* L, int pos)
{
	Node* p = L;
	int i = 0;
	for (int i = 0;i < pos - 1;i++)
	{
		if (p->next ==NULL)
		{
			return 0;
		}
		p = p->next;
	}
	Node* q = p;
	q->next = p->next;
	q->next->prev = p;
	free(q);
	return 1;
}
//释放链表
 