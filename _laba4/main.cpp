#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	List text;
	ifstream in("in.txt");
	while (!in.eof())
	{
		char * str = new char[30];
		in >> str;
		char * word = new char[strlen(str) + 1];
		word = strtok(str, " ,;:.!?");
		text.add(str);
		delete[] str;
	}
	text.print(text.begin);
	system("pause");
	return 0;
}