﻿#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
#include <iostream>
#include <conio.h>
using namespace std;
void  _delete_chars(char * str){
	int i = 0, j = 0;
	while (str[i++]){
		if (*(str + i + 1) == *(str + i)){
			int j = i;
			while (str[j++]) *(str + j) = *(str + j + 1);
		}
	}
}
char* locate_str(int len){
	return new char[len];
}
void init_str(char * str, int len){
	cout << "Enter the string :" << endl;
	cin.getline(str, len);
}
void another_trans(char * str){
	char * p = strtok(str, " ,.!?-:;()");
	int i = 0;
	while (p){
		if (strlen(p) % 2 == 0){
			_delete_chars(p);
			cout << p << " ";
		}
		p = strtok(0, " ,.!?-:;()");
	}
	cout << endl;
}
/*void check(){
	int *a;
	while (false){
		a = new (std::nothrow) int[999];
		if (a == 0){
			cout << "out of memory";
			break;
		}
	}
}*/
int menu(char*str){
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
			init_str(str, len);
			another_trans(str);
			delete[] str;
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