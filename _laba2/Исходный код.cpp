//26.� ������� �(N, �) ������� ������� ������.
#include <iostream>
#include <conio.h>
#include <memory>
using namespace std;
#include "head.h"
int main()
{
	int N = 5, M = 4;
	setlocale(0, "");
	int**arr = locate_array(N);
    menu(arr);
	return 0;
}