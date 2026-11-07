#include<stdio.h>
#include<stdlib.h>


//二叉树的顺序存储结构
typedef char ElemType;
typedef struct TreeNode
{
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;

}TreeNode;
typedef TreeNode* BiTree;
//二叉树的遍历
// 
// 
// 
// 

//树的创建
void createTree(BiTree* T)
{
	ElemType ch;
	ch = str[idx++];
	if (ch == '#')//数组那里的值为#时代表这里的节点为空也就是不存在这个子树；
	{
		*T == NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
}


//1.前序遍历
void preOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}



//二叉树遍历之中序遍历

void inOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	inOrder(T->lchild);
	printf("%c", T->data);
	inOrder(T->rchild);
}
//后序遍历
//ok
void postOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c", T->data);
}

