#include "head.h"
#include <iostream>
#include <conio.h>
using namespace std;
int N = 5, M = 4;
int ** locate_array(int n)
{
	return new int *[n];
}
void init_array(int**arr, int n, int m)
{
	for (int i = 0; i < n; ++i)
		*(arr+i) = new int[m];
}
void enter_array(int**arr, int n, int m)
{
	cout << "Enter the matrix :" << endl;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			//cin >> arr[i][j];
			if (i % 2 == 0 || i == 0) *(*(arr + i) + j) = 0;
			else *(*(arr + i) + j) = i;
}
void print_array(int**arr, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << *(*(arr + i) + j) << " ";
		}
		cout << endl;
	}
}
void clear_memory(int**arr, int n)
{
	for (int i = 0; i < n; ++i) delete[] arr[i];
	delete[] arr;
}
void null_string_array(int**arr, int &n, int m)
{
	for (int i = 0; i<n; i++)
	{
		bool flag = true;
		for (int j = 0; j < m; j++)
			if (*(*(arr + i) + j) != 0)
				 flag = false;
		if (flag == true)
		{
			for (int k = i; k < n - 1; k++)
			{
				for (int j = 0; j < m; j++)
				{
					*(*(arr + k) + j) = *(*(arr + k + 1) + j);
				}
			}
			n--;
			i = 0;
		}
	}
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
int menu(int**arr){
	while (true) {
		char k;
		cout << "0 - Узнать условие "  << endl
			 << "1 - Получить решение" << endl
			 << "2 - Выйти"			   << endl;
		k = _getch();
		system("cls");
		switch (k)
		{
		case '0': {
			cout << "В массиве А(N, М) удалить нулевые строки." << endl;
			break;
		}
		case '1':{
			check();
			init_array(arr, N, M);
			enter_array(arr, N, M);
			print_array(arr, N, M);
			null_string_array(arr, N, M);
			cout << endl << endl;
			print_array(arr, N, M);
			clear_memory(arr, N);
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