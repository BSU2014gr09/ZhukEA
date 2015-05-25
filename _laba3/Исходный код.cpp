#include <iostream>
#include <conio.h>
using namespace std;
struct mixed_fraction
{
	int integer_part;
	int numerator;
	int denominator;
	void get_fract()
	{
		cout << "Enter mixed fractions" << endl;
		cout << "Enter integer part : "; cin >> integer_part;
		cout << "Enter numerator : "; cin >> numerator;
		cout << "Enter denominator : "; cin >> denominator;
	}
	void show_fract()
	{
		if (integer_part == 0)
			cout << numerator << "/" << denominator << endl;
		else
		cout << integer_part << " " << numerator << "/" << denominator << endl;
	}
};

mixed_fraction sum(mixed_fraction fract1, mixed_fraction fract2)
{
	mixed_fraction fract3;
	fract3.integer_part = fract1.integer_part + fract2.integer_part;
	fract3.denominator = fract1.denominator*fract2.denominator;
	fract3.numerator = fract1.numerator*fract2.denominator + fract2.numerator*fract1.denominator;
	cout << "Summary of this fractions is equals ";
	fract3.show_fract();
	return fract3;
}
mixed_fraction diff(mixed_fraction fract1, mixed_fraction fract2)
{
	mixed_fraction fract3;
	fract3.integer_part = fract1.integer_part - fract2.integer_part;
	fract3.denominator = fract1.denominator*fract2.denominator;
	fract3.numerator = fract1.numerator*fract2.denominator - fract2.numerator*fract1.denominator;
	cout << "Differense between this fractions is equals ";
	fract3.show_fract();
	return fract3;
}
mixed_fraction mult(mixed_fraction fract1, mixed_fraction fract2)
{
	mixed_fraction fract3;
	fract3.integer_part = fract1.integer_part*fract2.integer_part;
	fract3.denominator = fract1.denominator*fract2.denominator;
	fract3.numerator = fract1.integer_part*fract2.numerator*fract1.denominator + fract2.integer_part*fract1.numerator*fract2.denominator + fract1.numerator*fract2.numerator;
	cout << "Multiplication of this fractions is equals ";
	fract3.show_fract();
	return fract3;
}
mixed_fraction div(mixed_fraction fract1, mixed_fraction fract2)
{
	mixed_fraction fract3;
	fract3.integer_part = 0;
	fract3.denominator = fract1.denominator*(fract2.integer_part*fract2.denominator + fract2.numerator);
	fract3.numerator = (fract1.integer_part*fract1.denominator + fract1.numerator)*fract2.denominator;
	cout << "Division of this fractions is equals ";
	fract3.show_fract();
	return fract3;
}
int main()
{
	mixed_fraction a,b;
	
	while (true)
	{
		char k;
		cout << "What operation do you want to do ? " << endl
			<< "0 - I don't understand whats going on here.Plese close it!" << endl
			<< "1 - addition" << endl
			<< "2 - substraction" << endl
			<< "3 - multiplication" << endl
			<< "4 - devision " << endl;
		k = _getch();
		system("cls");
		switch (k)
		{
		case '0':
		{
			return 0;
		}
		case '1':
		{
			a.get_fract();
			a.show_fract();
			b.get_fract();
			b.show_fract();
			sum(a, b);
			break;
		}
		case '2':
		{
			a.get_fract();
			a.show_fract();
			b.get_fract();
			b.show_fract();
			diff(a, b);
			break;
		}
		case '3':
		{
			a.get_fract();
			a.show_fract();
			b.get_fract();
			b.show_fract();
			mult(a, b);
			break;
		}
		case '4':
		{
			a.get_fract();
			a.show_fract();
			b.get_fract();
			b.show_fract();
			div(a, b);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}