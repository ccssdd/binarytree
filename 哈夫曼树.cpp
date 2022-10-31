#include<iostream>
#include<cstring>
using namespace std;
template<class T>
struct treenode
{
	T parent;
	T lc;
	T rc;
	T w;
};
template<class T>
class htree
{
protected:
	treenode<T>* hufftree;
	int length;
public:
	htree(int n)
	{
		int total = 2 * n - 1;
		hufftree = new treenode<T>[total];
		if (!hufftree)
		{
			cout << "init fail" << endl;
		}
		length = 0;
		int i;
		int weight = 0;
		for (i = 0; i < n; i++)
		{
			hufftree[i].parent = 0;
			hufftree[i].lc = 0;
			hufftree[i].rc = 0;
			cout << "please enter thr weight of" << i << endl;
			cin >> weight;
			hufftree[i].w = weight;
			length++;
		}
		for(;i < total;i++)
		{
			hufftree[i].parent = 0;
			hufftree[i].lc = 0;
			hufftree[i].rc = 0;
			hufftree[i].w = 9999;
			length++;
		}
	}
	void select(int pos,T &min1,T &min2)
	{
		int i = 0;
		T m1,m2;
		T minweight;
		//find m1
		while (hufftree[i].parent != 0)
		{
			i++;
		}
		minweight = hufftree[i].w;
		m1 = i;
		while (i < pos)
		{
			if (hufftree[i].w < minweight && hufftree[i].parent == 0)
			{
				minweight = hufftree[i].w;
				m1 = i;
			}
				i++;
		}
		hufftree[m1].parent = 1;
		min1 = m1;
		//find m2
		i = 0;
		while (hufftree[i].parent != 0)
		{
			i++;
		}
		minweight = hufftree[i].w;
		m2 = i;
		while (i < pos)
		{
			if (hufftree[i].w < minweight && hufftree[i].parent == 0)
			{
				minweight = hufftree[i].w;
				m2 = i;
			}
			i++;
		}
		hufftree[m2].parent = 1;
		min2 = m2;
	}
	void createhuffmantree(int num)
	{
		if (!hufftree)
		{
			return;
		}
		int i = 0;
		T min1;
		T min2;
		for (i = num; i < length; i++)
		{
			select(i, min1, min2);
			hufftree[min1].parent = i;
			hufftree[min2].parent = i;
			hufftree[i].lc = min1;
			hufftree[i].rc = min2;
			hufftree[i].w = hufftree[min1].w + hufftree[min2].w;
		}

	}
	void output()
	{
		if (hufftree != NULL)
		{
			cout << "show the huffmantree" << endl;
			for (int i = 0; i <length; i++)
			{
				//cout << hufftree[i].lc << endl;
				//cout << hufftree[i].parent << endl;
				//cout << hufftree[i].rc << endl;
				cout << hufftree[i].w << endl;
			}
		}
	}
	int getlength()
	{
		return length;
	}
};
template<class T>
class codehuffman :public htree<T>
{
public:

};
int main(void)
{
	htree<int> t(5);
	//t.createhuffmantree(5);
	//t.output();
	//t.output();
	//int pos = t.getlength();
	//int min1;
	//int min2;
	//t.select(pos, min1, min2);
	//cout << min1 << endl;
	//cout << min2 << endl;
	return 0;
}