#define _CRT_SECURE_NO_WARNINGS
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
void delete_str(char * str){
	delete[] str;
}
char* locate_str(int len){
	return new char[len];
}
void init_str(char * str, int len){
	cout << "Enter the string :" << endl;
	cin.getline(str, len);
}
void print_str(char * str, int len){
	cout << str << endl;
}
void another_trans(char * str){
	char * p = strtok(str, " ");
	int i = 0;
	while (p){
		if (strlen(p) % 2 == 0){
			_delete_chars(p);
			cout << p << " ";
		}
		p = strtok(0, " ");
	}
	cout << endl;
}
void check(){
	int *a;
	while (false){
		a = new (std::nothrow) int[999];
		if (a == 0){
			cout << "out of memory";
			break;
		}
	}
}
int menu(char*str){
	while (true) {
		char k;
		cout << "0 - ������ ������� " << endl
			<< "1 - �������� �������" << endl
			<< "2 - �����" << endl;
		k = _getch();
		system("cls");
		switch (k)
		{
		case '0': {
			cout << "������������� ������ ����� ������ ����� � ������, ������ � �� ������� ����� ���������� �������, ������� �� ������." << endl;
			break;
		}
		case '1':{
			init_str(str, len);
			another_trans(str);
			delete_str(str);
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