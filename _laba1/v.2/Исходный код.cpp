//Преобразовать каждое слово чётной длины в строке, удалив в нём стоящие рядом одинаковые символы, оставив по одному.
#include <iostream>
#include <cstring>
#include "schar.h"
using namespace std;

void main()
{
	setlocale(0, "");
	char* str = locate_char(128);
	/*init_char(str, 128);
	transform_char(str);*/
	menu(str,128);
	delete[] str;
	/*cout << str << endl;*/
}