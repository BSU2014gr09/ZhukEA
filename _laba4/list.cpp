#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
#include<iostream>
#include<cstring>
using namespace std;

node * List::add(char * word)
{
	node * tmp = new node;
	node * pos = begin;
	while (pos)
	{
		if (!_stricmp(pos->word, word))
		{
			pos->amt++;
			return pos;
		}
		else pos = pos->next;
	}
	tmp->word = new char[strlen(word) + 1];
	strcpy(tmp->word, word);
	tmp->amt = 1;
	tmp->next = begin;
	begin = tmp;
	return begin;
}

void List::print(node * start)
{
	node * i = start;
	while (i)
	{
		cout << i->word << " " << i->amt << endl;
		i = i->next;
	}
}