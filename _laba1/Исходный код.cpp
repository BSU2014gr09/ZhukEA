//28. ������������� ������ ����� ������ ����� � ������, ������ � �� ������� ����� ���������� �������, ������� �� ������.
#include <iostream>
#include <conio.h>
using namespace std;
#include "head.h"
int main(){
	setlocale(0, "");
	char * str = locate_str(len);
	while(true) {
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
	
	return 0;
}