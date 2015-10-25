#pragma once
#include <iostream>
using namespace std;

#define P 7
#define  NULL_DATA -1
#define BUCK_SIZE  3
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

_Ptr _BuyNode(_Ptr N, int x)
{
	_Ptr s = new buck_node;
	s->next = N;
	s->Value[0] = x;
	for (int i = 1; i < BUCK_SIZE; ++i)
		s->Value[i] = NULL_DATA;
	return s;
}

void insert_new_element(hashtable& ht, int new_element)
{
	int index = _hash(new_element);
	_Ptr p = ht[index].next;

	if (ht[index].next == NULL)
	{
		_Ptr s = _BuyNode(NULL, new_element);
		ht[index].next = s;
	}

	for (int i = 0; i < BUCK_SIZE; i++)
	{
		if (ht[index].Value[i] == NULL_DATA)
		{
			ht[index].Value[i] = new_element;
			return;
		}
	}


	while (p->next != NULL)
		p = p->next;
	_Ptr s;
	for (int i = 0; i < BUCK_SIZE; i++)
		if (p->Value[i] == NULL_DATA)
		{
			p->Value[i] = new_element;
			return;
		}
	s = _BuyNode(p->next, new_element);
	p->next = s;


}

void showhashtable(hashtable& h)
{
	for (int l = 0; l < P; l++)
	{
		cout << "Key=" << l << "->:";
		for (int i = 0; i < BUCK_SIZE; i++)
		{
			if (h[l].Value[i] != NULL_DATA)
				cout << h[l].Value[i] << " ";
		}
		cout << endl << "	";
		_Ptr s = h[l].next;
		while (s)
		{
			for (int i = 0; i < BUCK_SIZE; i++)
			{
				if (h[l].Value[i] != NULL_DATA)
					cout << s->Value[i] << " ";
			}
			cout << endl << "	";
			s = s->next;
		}
		cout << endl;
	}
}

