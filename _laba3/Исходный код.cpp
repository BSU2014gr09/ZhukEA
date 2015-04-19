#include <iostream>
#include <conio.h>
using namespace std;
//void SimplifyNumeral(int in_pt, int nmr, int dnr) // 5 144/36
//{
//	cout << in_pt << " " << nmr << "/" << dnr << " is equals ";
//	while (nmr > dnr)
//	{
//		if (nmr % dnr == 0)
//		{
//			nmr /= dnr;
//			in_pt += nmr;
//			cout << in_pt << endl;
//			break;
//		}
//	}
//	/*while (nmr < dnr)
//	{
//
//	}*/
//}
struct mixed_numeral
{	
	int integral_part;
	int numerator;
	int denominator;
	mixed_numeral() : integral_part(0), numerator(0), denominator(0)
	{}
	mixed_numeral(int i_pa, int nm, int dm) : integral_part(i_pa), numerator(nm), denominator(dm)
	{}
	void getMnum()
	{
		cout << "Enter the integer part : "; cin >> integral_part;
		cout << "Enter the numerator : "; cin >> numerator;
		cout << "Enter the denominator : "; cin >> denominator;
	}
	void showMnum()
	{
		cout << integral_part << " " << numerator << "/" << denominator << endl;
	}
	mixed_numeral operator+(mixed_numeral) const;
	mixed_numeral operator-(mixed_numeral) const;
	mixed_numeral operator*(mixed_numeral) const;
	mixed_numeral operator/(mixed_numeral) const;
};
mixed_numeral mixed_numeral::operator+(mixed_numeral num2) const
{
	int i_p = integral_part + num2.integral_part;
	int n = numerator*num2.denominator + num2.numerator*denominator;
	int d = denominator*num2.denominator;
	return mixed_numeral(i_p,n,d);
}
mixed_numeral mixed_numeral::operator-(mixed_numeral num2) const
{
	int i_p = integral_part - num2.integral_part;
	int n = numerator*num2.denominator - num2.numerator*denominator;
	int d = denominator*num2.denominator;
	return mixed_numeral(i_p, n, d);
}
mixed_numeral mixed_numeral::operator*(mixed_numeral num2) const
{
	int i_p = 0;
	int n = (denominator*integral_part + numerator)*(num2.denominator*num2.integral_part + num2.numerator);
	int d = denominator + num2.denominator;
	return mixed_numeral(i_p,n, d);
}
mixed_numeral mixed_numeral::operator/(mixed_numeral num2) const
{
	int i_p = 0;
	int n = (integral_part*denominator + numerator)*num2.denominator;
	int d = denominator*(num2.integral_part*num2.denominator + num2.numerator);
	return mixed_numeral(i_p, n, d);
}
int main()
{
	mixed_numeral num1, num2, num_sum, num_diff, num_mult,num_div;
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
			
			cout << "Enter the first mixed numeral : " << endl;
			num1.getMnum();
			num1.showMnum();
			cout << "Enter the second mixed numeral : " << endl;
			num2.getMnum();
			num2.showMnum();
			num_sum = num1 + num2;
			cout << "The result mixed numeral is ";
			num_sum.showMnum();
			break;
		}
		case '2':
		{
			cout << "Enter the first mixed numeral : " << endl;
			num1.getMnum();
			num1.showMnum();
			cout << "Enter the second mixed numeral : " << endl;
			num2.getMnum();
			num2.showMnum();
			num_diff = num1 - num2;
			cout << "The result mixed numeral is ";
			num_diff.showMnum();
			break;
		}
		case '3':
		{
			cout << "Enter the first mixed numeral : " << endl;
			num1.getMnum();
			num1.showMnum();
			cout << "Enter the second mixed numeral : " << endl;
			num2.getMnum();
			num2.showMnum();
			num_mult = num1*num2;
			cout << "The result mixed numeral is ";
			num_mult.showMnum();
			break;
		}
		case '4':
		{
			cout << "Enter the first mixed numeral : " << endl;
			num1.getMnum();
			num1.showMnum();
			cout << "Enter the second mixed numeral : " << endl;
			num2.getMnum();
			num2.showMnum();
			num_div = num1/num2;
			cout << "The result mixed numeral is ";
			num_div.showMnum();
			break;
		}
		default:
			break;
		}
	}
	return 0;
}