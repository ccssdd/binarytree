#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef struct treenode
{
	char data;
	treenode* lc;
	treenode* rc;
}treenode,*tree;
typedef struct stacknode
{
	stacknode* next;
	treenode* data;
};
typedef struct queuenode
{
	treenode* data;
	queuenode* next;
}queuenode;
//栈
class stack
{
private:
	stacknode* top;
public:
	stack()
	{
		top = NULL;
	}
	int length()
	{
		int length;
		if (top == NULL)
		{
			return 0;
		}
		else
		{
			for (stacknode* p = top; p != NULL; p = p->next)
			{
				length++;
			}
		}
		return length;
	}
	bool empty()
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}
	void push(treenode* x)
	{
		stacknode* p = new stacknode;
		p->data = x;
		p->next = top;
		top = p;
	}
	bool pop()
	{
		treenode* x;
		if (top == NULL)
		{
			return false;
		}
		x = top->data;
		stacknode* p = new stacknode;
		p = top;
		top = top->next;
		free(p);
		return true;
	}
	treenode* gettop()
	{
		return top->data;
	}
};
//队列
class linkqueue
{
private:
	queuenode* front,*rear;
	int length;
public:
	linkqueue()
	{
		front = rear = NULL;
		length = 0;
	}
	int size()
	{
		return length;
	}
	bool empty()
	{
		if (size() == 0)
		{
			return true;
		}
		return false;
	}
	void enqueue(treenode* value)
	{
		length++;
		queuenode* s = new queuenode;
		s->data = value;
		s->next = NULL;
		if (front == NULL)
		{
			rear = s;
			front = s;
		}
		else
		{
			rear->next = s;
			rear = s;
		}
	}
	void dequeue(treenode*& value)
	{
		queuenode* s = new queuenode;
		s = front;
		value = s->data;
		front = s->next;
		if (rear == s)
		{
			rear = front;
		}
		delete s;
		length--;
	}
};
//二叉树
class bttree
{
private:
	treenode* root;
public:
	bttree()
	{
		root = NULL;
	}
	void create(tree &t)
	{
		char x;
		cin >> x;
		if (x == '#')
		{
			t = NULL;
		}
		else
		{
			t = new treenode;
			t->data = x;
			cout << "请输入" << t->data << "的左子树";
			create(t->lc);
			cout << "请输入" << t->data << "的右子树";
			create(t->rc);
		}
	}
	//计算深度(递归)
	int height_tree(tree t)
	{
		if (t == NULL)
		{
			return 0;
		}
		int m = height_tree(t->lc);
		int n = height_tree(t->rc);
		return (m > n ? m : n )+ 1;
	}
	//计算深度（非递归）
	int height(tree t)
	{
		if (t == NULL)
		{
			return 0;
		}
		linkqueue q;
		treenode* p;
		q.enqueue(t);
		int depth = 0;
		while (!q.empty())
		{
			depth++;
			int size = q.size();
			int count = 0;
			while (count < size)
			{
				q.dequeue(p);
				count++;
				if (p->lc != NULL)
				{
					q.enqueue(p->lc);
				}
				if (p->rc != NULL)
				{
					q.enqueue(p->rc);
				}
			}
		}
		return depth;
	}
	//节点个数
	int nodenumber(tree t)
	{
		if (t == NULL)
		{
			return 0;
		}
		return nodenumber(t->lc) + nodenumber(t->rc) + 1; 
	}
	//叶节点个数
	int yenodenumber(tree t)
	{   
		int cnt = 0;
		if (t == NULL)
		{
			return 0;
		}
		if (t->lc == NULL && t->rc == NULL)
		{
			cnt++;
		}
		int m = yenodenumber(t->lc);
		int n = yenodenumber(t->rc);
		cnt += m + n;
		return cnt;
	}
	//度为1的节点个数
	int nodenumber_one(tree T)
	{
		int cnt = 0;
		if (T)
		{
			if ((T->lc== NULL && T->rc != NULL) || (T->lc != NULL && T->rc== NULL))
			{
				cnt = 1 + nodenumber_one(T->lc) + nodenumber_one(T->rc);
			}
			else
			{
				cnt = nodenumber_one(T->lc) + nodenumber_one(T->rc);
			}
		}
		return cnt;
	}
	//度为2的节点个数
	int nodenumber_two(tree t)
	{
		int cnt = 0;
		if (t)
		{
			if (t->lc != NULL && t->rc != NULL)
			{
				cnt = 1 + nodenumber_two(t->lc) + nodenumber_two(t->rc);
			}
			else
			{
				cnt =nodenumber_two(t->lc) + nodenumber_two(t->rc);
			}
		}
		return cnt;
	}
	void midshow(tree t)
	{
		if (t == NULL)
		{
			return;
		}
		if (t->lc != NULL)
			midshow(t->lc);
		cout << t->data << " ";
		if (t->rc != NULL)
			midshow(t->rc);
	}
	//前序遍历
	void preshow(tree t)
	{
		if (t == NULL)
		{
			return;
		}
		cout << t->data << " ";
		if (t->lc != NULL)
		{
			preshow(t->lc);
		}
		if (t->rc != NULL)
			preshow(t->rc);
	}
	//前序遍历（非递归）
	void preshow_(tree t)
	{
		vector<char>vec;
		stack st;
		st.push(t);
		while (!st.empty())
		{
			treenode* p = st.gettop();
			st.pop();
			if (p != NULL)
			{
				vec.push_back(p->data);
			}
			else
			{
				continue;
			}
			if(p->lc!=NULL)
			st.push(p->lc);
			if(p->rc!=NULL)
			st.push(p->rc);
		}
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << endl;
		}
	}
	void lastshow(tree t)
	{
		if (t == NULL)
		{
			return;
		}
		if (t->lc != NULL)
			lastshow(t->lc);
		if (t->rc != NULL)
			lastshow(t->rc);
		cout << t->data << " ";
	}
	void levelshow(tree t)
	{
		linkqueue templinkqueue;
		tree p;
		templinkqueue.enqueue(t);
		while (!templinkqueue.empty())
		{
			templinkqueue.dequeue(p);
			cout << p->data;
			if (p->lc != NULL)
			{
			  templinkqueue.enqueue(p->lc);
	     	}
			if (p->rc != NULL)
			{
			  templinkqueue.enqueue(p->rc);
			}
		}
	}
};
int main(void)
{
	tree t;
	bttree x;
	x.create(t);
	//cout << x.nodenumber_two(t) << endl;
	//cout << x.height(t) << endl;
	x.preshow_(t);
	//cout << x.nodenumber_one(t);
	//x.levelshow(t);
	return 0;
}