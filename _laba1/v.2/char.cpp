#define _CRT_SECURE_NO_WARNINGS
#include "schar.h"
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
char* locate_char(int len)
{
	return new char[len];
}
void delete_char(char* str)
{
	delete[] str;
}
void init_char(char* str, int len)
{
	cout << "Enter string: " << endl;
	cin.getline(str, len);
}
char* ptr_char(char* word, int len)
{
	while (len--)
	{
		if (*word == *(word + 1)) return word;
		word++;
	}
	return nullptr;
}
void transform_char(char* str)
{
	int count = 0;
	while (*(str - 1))
	{
		int len = strcspn(str, " ,.!&?{}()/'|\'\"");
		if (len % 2 == 0)
		{
			char * change = ptr_char(str, len);
			if (change)
			{
				strcpy(change, change + 1);
				count++;
				len--;
			}
			else str += len + 1;
		}
		else str += len + 1;

	}
}
int menu(char*str,int len){
	while (true) {
		char k;
		cout << "0 - Узнать условие " << endl
			<< "1 - Получить решение" << endl
			<< "2 - Выйти" << endl;
		k = _getch();
		system("cls");
		switch (k)
		{
		case '0': {
			cout << "Преобразовать каждое слово чётной длины в строке, удалив в нём стоящие рядом одинаковые символы, оставив по одному." << endl;
			break;
		}
		case '1':{
			init_char(str, len);
			transform_char(str);
			cout << str << "\n";
			break;
		}
		case '2': {
			return 0;
		}
		default:
			break;
		}
	}

}