#include<iostream>
#include<cstring>
#include<string.h>
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
		hufftree = new treenode<T>[total+1];
		if (!hufftree)
		{
			cout << "init fail" << endl;
		}
		length = 0;
		int i;
		int weight = 0;
		for (i = 0; i < n; i++)
		{
			hufftree[i].parent = -1;
			hufftree[i].lc = -1;
			hufftree[i].rc = -1;
			cout << "please enter thr weight of" << i << endl;
			cin >> weight;
			hufftree[i].w = weight;
			length++;
		}
		for(;i < total;i++)
		{
			hufftree[i].parent = -1;
			hufftree[i].lc = -1;
			hufftree[i].rc = -1;
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
		while (hufftree[i].parent != -1)
		{
			i++;
		}
		minweight = hufftree[i].w;
		m1 = i;
		for(;i < pos;i++)
		{
			if (hufftree[i].w < minweight && hufftree[i].parent == -1)
			{
				minweight = hufftree[i].w;
				m1 = i;
			}
		}
		hufftree[m1].parent = 1;
		min1 = m1;
		//find m2
		i = 0;
		while (hufftree[i].parent != -1)
		{
			i++;
		}
		minweight = hufftree[i].w;
		m2 = i;
		for(;i < pos;i++)
		{
			if (hufftree[i].w < minweight && hufftree[i].parent == -1)
			{
				minweight = hufftree[i].w;
				m2 = i;
			}
		}
		hufftree[m2].parent = 1;
		min2 = m2;
	}
	void createhuffmantree(int num)
	{
		if (!hufftree)
		{
			cout << "no exist" << endl;
		}
		int i = 0;
		T min1;
		T min2;
		for (i = num; i <length; i++)
		{
			select(i, min1, min2);
			hufftree[min1].parent = i;
			hufftree[min2].parent = i;
			hufftree[i].lc = min1;
			hufftree[i].rc = min2;
			hufftree[i].w = hufftree[min1].w + hufftree[min2].w;
		}
	}
	void huffmancoding(string huffmanCode[], int n)
	{
		int cur;
		int parent;
		//traverse
		for (int i = 0; i < n; i++)
		{
			cur = i;//current position
			parent = hufftree[i].parent;//current parent 
			while (parent != -1) 
			{
				if (hufftree[parent].lc == cur)
					huffmanCode[i] = '0' + huffmanCode[i];//current lefttree's code is '0'
				else
					huffmanCode[i] = '1' + huffmanCode[i];
			//change current node and parent node to search upwards
				cur = parent;
				parent = hufftree[parent].parent;
			}
		}
	}
	void output()
	{
		if (hufftree != NULL)
		{
			cout << "show the huffmantree" << endl;
			for (int i = 0; i <length; i++)
			{
				cout << hufftree[i].lc << " ";
				cout << hufftree[i].rc << " ";
				cout << hufftree[i].parent <<" ";
				cout << hufftree[i].w << endl;
				cout << endl;
			}
		}
	}
	int getlength()
	{
		return length;
	}
	void outputcode(int n,string s[10])
	{
		for (int i = 0; i < n; i++)
		{
			cout <<char('A' + i) << ":" << s[i] << endl;
		}
	}
};
int main(void)
{
	int n = 0;
	cin>>n;
	htree<int> t(n);
	t.createhuffmantree(n);
	t.output();
	string huffmancode[10];
	//DDDDAAABEEAAFCDAABCCCBADD
	cout << "***********" << endl;
	t.huffmancoding(huffmancode,n);
	t.outputcode(n,huffmancode);
	return 0;
}