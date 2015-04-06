//28. Преобразовать каждое слово чётной длины в строке, удалив в нём стоящие рядом одинаковые символы, оставив по одному.
#include <iostream>
#include <conio.h>
using namespace std;
#include "head.h"
int main(){
	setlocale(0, "");
	char * str = locate_str(len);
	while(true) {
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
	
	return 0;
}