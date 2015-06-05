#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
	List text;
	ifstream in("in.txt");
	char * div = ",!.;?";
	while (!in.eof())
	{
		char * str = new char[30];
		in >> str;
		char * word = strtok(str, div);
		text.add(word);
		delete[] str;
	}
	text.print(text.begin);
	system("pause");
	return 0;
}