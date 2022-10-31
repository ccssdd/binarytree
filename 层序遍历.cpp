//#include <stdio.h>
//#include <malloc.h>
//typedef struct treenode
//{
//	int data;
//	struct treenode* lchild, * rchild;
//} treenode, * tree;
//typedef struct queuenode
//{
//	treenode* data;
//	struct queuenode* next;
//} queuenode;
//typedef struct
//{
//	queuenode* front;
//	queuenode* rear;
//} linkqueue;
//
//bool initqueue(linkqueue& q)
//{
//	q.front = NULL;
//	q.rear = NULL;
//	return true;
//}
//bool init_tree(tree& root)
//{
//	root = (treenode*)malloc(sizeof(treenode));
//	root->data = {};
//	root->lchild = NULL;
//	root->rchild = NULL;
//	return true;
//}
//bool emptyqueue(linkqueue q)
//{
//	if (q.front == NULL)
//	{
//		return true;
//	}
//	return false;
//}
//bool enqueue(linkqueue& q, treenode* x)
//{
//	queuenode* s = (queuenode*)malloc(sizeof(queuenode));
//	s->data = x;
//	s->next = NULL;
//	if (q.front == NULL)
//	{
//		q.front = s;
//		q.rear = s;
//	}
//	else
//	{
//		q.rear->next = s;
//		q.rear = s;
//	}
//	return true;
//}
//bool dequeue(linkqueue& q, tree& x)
//{
//	queuenode* s = q.front;
//	if (emptyqueue(q))
//	{
//		return false;
//	}
//	x = s->data;
//	q.front = s->next;
//	if (q.rear == s)
//	{
//		q.rear = q.front;
//	}
//	free(s);
//	return true;
//}
//void creattree(tree& t)
//{
//	int x;
//	scanf_s("%d", &x);
//	if (x == 9999)
//	{
//		t = NULL;
//	}
//	else
//	{
//		t = (treenode*)malloc(sizeof(treenode));
//		t->data = x;
//		creattree(t->lchild);
//		creattree(t->rchild);
//	}
//}
//
//void levelorder(tree t)
//{
//	linkqueue q;
//	initqueue(q);
//	tree p;
//	enqueue(q, t);
//	while (!emptyqueue(q))
//	{
//		dequeue(q, p);
//		printf("%d", p->data);
//		if (p->lchild != NULL)
//		{
//			enqueue(q, p->lchild);
//		}
//		if (p->rchild != NULL)
//		{
//			enqueue(q, p->rchild);
//		}
//	}
//}
//
//int main()
//{
//	tree t;
//	init_tree(t);
//	creattree(t);
//	levelorder(t);
//
//	return 0;
//}
