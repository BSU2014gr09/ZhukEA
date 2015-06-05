//20.В строке удалить все слова, содержащие заданную букву два раза.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

bool isTwoTimes(char* str, char ltr)
{
	int i = -1;
	int count = 0;
	while (str[i++]) 
		if (*(str + i) == ltr) count++;
	if (count == 2) return true;
	return false;
}
int main()
{
	char ltr;
	int size;
	char* inputFile = new char[50];
	char* outputFile = new char[50];
	cout << "Enter input file name : " << endl;
	fflush(stdin);
	cin.getline(inputFile, 50);
	ifstream fin(inputFile, ios::in);
	if (!fin) 
	{ 
		cout << "Error while connecting: " << inputFile << endl; 
		system("pause"); exit(0); 
	}
	cout << "Enter output file name : " << endl;
	fflush(stdin);
	cin.getline(outputFile, 50);
	ofstream fout(outputFile, ios::out);
	if (!fout)
	{ 
		cout << "Error while connecting: " << outputFile << endl; 
		system("pause"); exit(0);
	}
	cout << "Enter the letter : ";
	cin >> ltr;
	cout << "Enter max size of strings in file" << endl;
	cin >> size;
	while (!fin.eof())
	{
		char *temp = new char[size];
		fin.getline(temp, size);
		char *p = temp;
		while (p - temp < strlen(temp)) {
			p += strspn(p, " ,.!?:;");
			int len = strcspn(p, " ,.!?:;");
			char *word = new char[len + 1];
			strncpy(word, p, len);
			word[len] = '\0';
			if (isTwoTimes(word, ltr))
			{
				strcpy(p, p + len);
				continue;
			}
			p += len;
		}
		fout << temp << endl;
	}
}