#pragma once
#include <iostream>
using namespace std;
//桶  使用两次模运算

#define P 7
#define  NULL_DATA -1
#define BUCK_SIZE  4
#define ElemType int

typedef struct buck_node
{
	int Value[BUCK_SIZE];
	struct buck_node* next;
}buck_node;

typedef buck_node hashtable[P];
typedef buck_node* _Ptr;

int _hash(int x)
{
	return x % P;
}

void init(hashtable &ht)
{
	for (int i = 0; i < P; i++)
	{
		for (int l = 0; l < BUCK_SIZE; l++)
			ht[i].Value[l] = NULL_DATA;
		ht[i].next = NULL;
	}
}

_Ptr _BuyNode(_Ptr N = NULL)
{
	_Ptr s = new buck_node;
	s->next = N;
	for (int i = 0; i < BUCK_SIZE; ++i)
		s->Value[i] = NULL_DATA;
	return s;
}

bool BuckFull(_Ptr s)
{
	for (int i = 0; i < BUCK_SIZE; ++i)
	{
		if (s->Value[i] == NULL_DATA)
			return false;
	}
	return true;
}

void insert_new_element(hashtable& ht, ElemType new_element)
{
	int index = _hash(new_element);
	int pos = new_element % BUCK_SIZE;

	_Ptr p = &ht[index];
	_Ptr r = p;
	while (p)
	{
		while (p->Value[pos] == NULL_DATA)
		{
			p->Value[pos] = new_element;
			return;
		}
		r = p;
		p = p->next;
	}

	p = (p == &ht[index]) ? p : _BuyNode();
	p->Value[pos] = new_element;
	r->next = p == &ht[index] ? NULL : p;
}

ElemType* Find(hashtable& h, ElemType v)
{
	int index = _hash(v);
	int pos = v % BUCK_SIZE;

	_Ptr p = &h[index];
	while (p)
	{
		if (p->Value[pos] == v)
			return &(p->Value[pos]);
		p = p->next;
	}

	cout <<v <<"  :查询无此数据！" << endl;
	exit(1);
}

void  Erase(hashtable& h, ElemType v)
{
	int index = _hash(v);
	int pos = v % BUCK_SIZE;

	_Ptr p = &h[index];
	while (p)
	{
		if (p->Value[pos] == v)
			p->Value[pos] = NULL_DATA;
		p = p->next;
	}

}

void clear(hashtable& h)
{
	_Ptr p;
	_Ptr cur;
	for (int i = 0; i < P; ++i)
	{
		p= &h[i];
		cur = p->next;
		while (cur)
		{
			p->next = cur->next;
			delete cur;
			cur = NULL;
		}
		for (int j = 0; j < BUCK_SIZE; ++j)
			p->Value[j] = NULL_DATA;
	}
}

void showhashtable(hashtable& h)
{
	for (int l = 0; l < P; l++)
	{
		cout << "Key=" << l << "->:";
		for (int i = 0; i < BUCK_SIZE; i++)
			cout << h[l].Value[i] << " ";

		cout << endl << "	";
		_Ptr s = h[l].next;
		while (s)
		{
			for (int i = 0; i < BUCK_SIZE; i++)
				cout << s->Value[i] << " ";

			cout << endl << "	";
			s = s->next;
		}
		cout << endl;
	}
}
