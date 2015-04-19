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
			while (str[j++]) *(str + j) = *(str + j + 1); // а встроенной ф-ции нету для такого действия????
		}
	}
}
void delete_str(char * str){ //ненужная ф-ция. Больше ресурсов тратится на ее вызов, чем на улучшение кода
	delete[] str;
}
char* locate_str(int len){
	return new char[len]; //нет проверки на успешность выделения памяти!!!
}
void init_str(char * str, int len){
	cout << "Enter the string :" << endl;
	cin.getline(str, len);
}
void print_str(char * str, int len){  //ненужная ф-ция. Больше ресурсов тратится на ее вызов, чем на улучшение кода. Более того, неясно зачем int len 
	cout << str << endl;
}
void another_trans(char * str){
	char * p = strtok(str, " "); // а почему разделители только пробелы????
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
void check(){ // что за заглушка? Семь раз подумай - один раз сделай commit!!!!!!!!!!!!!!
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
		cout << "0 - Óçíàòü óñëîâèå " << endl
			<< "1 - Ïîëó÷èòü ðåøåíèå" << endl
			<< "2 - Âûéòè" << endl;
		k = _getch();
		system("cls");
		switch (k)
		{
		case '0': {
			cout << "Ïðåîáðàçîâàòü êàæäîå ñëîâî ÷¸òíîé äëèíû â ñòðîêå, óäàëèâ â í¸ì ñòîÿùèå ðÿäîì îäèíàêîâûå ñèìâîëû, îñòàâèâ ïî îäíîìó." << endl;
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
