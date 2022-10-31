#include<iostream>
using namespace std;
//朴素办法找到中序前驱
//typedef struct treenode
//{
//	int data;
//	struct treenode* lchild, * rchild;
//}treenode,*tree;
//treenode* p;
//treenode* pre = NULL;
//treenode* final = NULL;
//bool inittree(tree &t)
//{
//	t->lchild = NULL;
//	t->rchild = NULL;
//	t->data = {};
//	return true;
//}
//void finalpre(tree t)
//{
//	finalpre(t->lchild);
//	visit(t);
//	finalpre(t->rchild);
//}
//void visit(treenode* q)
//{
//	if (q == p)
//	{
//		final == pre;
//	}
//	else
//	{
//		pre = q;
//	}
//}
//typedef struct treenode
//{
//	char data;
//	treenode* lc, *rc;
//	int ltag;
//	int rtag;
//}treenode,*tree;
//treenode* pre = NULL;
//class threadtree
//{
//private:
//	treenode* root;
//public:
//	threadtree()
//	{
//		root = NULL;
//	}
////建立二叉树
//	void creattree(tree&t)
//	{
//		char x;
//		cin >> x;
//		if (x == '#')
//		{
//			t = NULL;
//		}
//		else
//		{
//			t = new treenode;
//			t->data = x;
//			t->ltag = 0;
//			t->rtag = 0;
//			cout << "请输入" << t->data << "的左子树" << endl;
//			creattree(t->lc);
//			cout << "请输入" << t->data << "的右子树" << endl;
//			creattree(t->rc);
//		}
//	}
//
////打印
//	void output(tree t)
//	{
//		if (t == NULL)
//			return;
//		if (t->lc != NULL)
//			output(t->lc);
//			cout << t->data<<" ";
//		if(t->rc!=NULL)
//			output(t->rc);
//    }
////二叉树线索化(中序)
//	void visit(treenode*&p)
//	{
//		if (p->lc == NULL)
//		{
//			p->lc = pre;
//			p->ltag = 1;
//		}
//		if (pre != NULL && pre->rc == NULL)
//		{
//			pre->rc = p;
//			pre->rtag = 1;
//		}
//		pre = p;
//	}
//	void inthread(tree& t)
//	{
//		if (t != NULL)
//		{
//			inthread(t->lc);
//			visit(t);
//			inthread(t->rc);
//		}
//	}
//	/*void inthread(tree &p,treenode* &pre)
//	{
//		if (p != NULL)
//		{
//			inthread(p->lc, pre);
//			if (p->lc == NULL)
//			{
//				p->lc = pre;
//				p->ltag = 1;
//			}
//			if (pre != NULL && pre->rc == NULL)
//			{
//				pre->rc = p;
//				pre->rtag = 1;
//			}
//			pre = p;
//			inthread(p->rc, pre);
//		}
//	}*/
//	void creatthreadtree(tree& t)
//	{   
//		pre = NULL;
//		if (t != NULL)
//		{
//			inthread(t);
//			//inthread(t,pre);
//			if (pre->rc == NULL)
//			{
//				pre->rtag = 1;
//			}
//		}
//	}
//	//线索化（后序）
//	void inthread_last(tree& t)
//	{
//		if (t != NULL)
//		{
//			inthread_last(t->lc);
//			inthread_last(t->rc);
//			visit(t);
//		}
//	}
//	void createthreadtree_last(tree& t)
//	{
//		pre = NULL;
//		if (t != NULL)
//		{
//			inthread_last(t);
//			if (pre->rc == NULL)
//			{
//				pre->rc = NULL;
//			}
//		}
//	}
////线索化（先序）
//	void inthread_first(tree &t)
//	{
//		if (t != NULL)
//		{
//			visit(t);
//			if(t->ltag==0)
//			inthread(t->lc);
//			inthread(t->rc);
//		}
//	}
//	void createthreadtree_first(tree& t)
//	{
//		pre = NULL;
//		if (t != NULL)
//		{
//			inthread_first(t);
//			if (pre->rc ==NULL)
//			{
//				pre->rtag = 1;
//			}
//		}
//	}
//	//寻找先序后继
//	treenode* nextnode_first(treenode* t)
//	{
//		if (t->rtag == 1)
//		{
//			return t->rc;
//		}
//		else
//		{
//			if (t->lc!=NULL&&t->ltag==0)
//			{
//				return t->lc;
//			}
//			else
//			{
//				return t->rc;
//			}
//		}
//	}
//	//先序后继遍历
//	void inorder2(tree t)
//	{
//		for (tree p = t; p != NULL; p = nextnode_first(p))
//		{
//			cout << p->data << endl;
//		}
//	}
//	//寻找中序前驱
//	treenode* lastnode(tree& t)
//	{
//		tree p = t;
//		while (p->rtag == 0)
//		{
//			p = p->rc;
//		}
//		return p;
//	}
//	treenode* prenode(treenode* t)
//	{
//		if (t->ltag == 0)
//		{
//			return lastnode(t->lc);
//		}
//		else
//			return t->lc;
//	}
//	//中序前驱遍历
//	void inorder1(tree t)
//	{
//		for (tree p = lastnode(t); p != NULL; p = prenode(p))
//		{
//			cout << p->data << endl;
//		}
//	}
//	//寻找中序后继
//	treenode* firstnode(tree&t )
//	{
//		tree p = t;
//		while (p->ltag == 0)
//		{
//			p = p->lc;
//		}
//		return p;
//	}
//	treenode* nextnode(treenode* t)
//	{
//		if (t->rtag == 1)
//		{
//			return t->rc;
//		}
//		else
//		{
//			return firstnode(t->rc);
//		}
//	}
//
//	//中序后继遍历（非递归）
//	void inorder(tree t)
//	{
//		for (tree p = firstnode(t); p != NULL; p = nextnode(p))
//		{
//			cout << p->data << endl;
//		}
//	}
//	//寻找后续前驱
//	treenode* prenode_last(tree t)
//	{
//		if (t->ltag == 1)
//		{
//			return t->lc;
//		}
//		else
//		{
//			if (t->rc == NULL)
//			{
//				return t->lc;
//			}
//			else
//			{
//				return t->rc;
//			}
//		}
//	}
//	//后序前驱遍历
//	void inorder3(tree t)
//	{
//		for (tree p = t; p != NULL; p = prenode_last(p))
//		{
//			cout << p->data << endl;
//		}
//	}
//};
//
//
//int main(void)
//{
//	tree t;
//	threadtree a;
//	a.creattree(t);
//	//a.creatthreadtree(t);
//	//a.inorder1(t);
//	a.createthreadtree_first(t);
//	a.inorder2(t);
//	//a.inorder2(t);
//	//a.createthreadtree_last(t);
//	//a.inorder3(t);
//	//a.output(t);
//	//a.creatthreadtree(t);
//	//a.inorder(t);
//	return 0;
//}