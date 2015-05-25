#include <iostream>
#include <conio.h>
using namespace std;
struct mixed_numeral
{	
	int integral_part;
	int numerator;
	int denominator;
	mixed_numeral() : integral_part(0), numerator(0), denominator(0)
	{}
	mixed_numeral(int i_pa, int nm, int dm) : integral_part(i_pa), numerator(nm), denominator(dm)
	{}
	mixed_numeral(int nm1, int dm1) : numerator(nm1), denominator(dm1)
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
	void showMnum_md()
	{
		cout << numerator << "/" << denominator << endl;
	}
	void transformNumerals()
	{
		cout << numerator << "/" << denominator << " is equals ";
		int in_pt = ((numerator / denominator)*denominator) / denominator;
		numerator -= (numerator / denominator)*denominator;
		cout << in_pt << " " << numerator << "/" << denominator << endl;
	}
	void SimplifyNumeral()
	{
		cout << integral_part << " " << numerator << "/" << denominator << " is equals ";
		if (numerator > denominator)
		{
			while (numerator > denominator)
			{
				if (denominator == 0)
				{
					cout << "INFINITY" << endl;
					break;
				}
				else if (numerator % denominator == 0)
				{
					numerator /= denominator;
					integral_part += numerator;
					cout << integral_part << endl;
					goto finish;
				}
				else
				{
					integral_part += numerator / denominator;
					numerator -= (numerator / denominator)*denominator;
					cout << integral_part << " " << numerator << "/" << denominator << endl;
					goto finish;
				}
			}
		}
		if (numerator == denominator)
		{
			if (numerator == 0 && denominator == 0)
			{
				cout << "undefinded" << endl;
				goto finish;
			}
			integral_part++;
			cout << integral_part << endl;
		}
		while (numerator < denominator)
		{
			if (numerator == 0)
			{
				cout << integral_part << endl;
				break;
			}
			if (denominator % numerator == 0)
			{
				denominator /= numerator;
				numerator /= numerator;
				cout << integral_part << " " << numerator << "/" << denominator << endl;
				break;
			}
			cout << integral_part << " " << numerator << "/" << denominator << endl;
			break;
		}

	finish:
		;
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
	int n = (denominator*integral_part + numerator)*(num2.denominator*num2.integral_part + num2.numerator);
	int d = denominator + num2.denominator;
	return mixed_numeral(n, d);
}
mixed_numeral mixed_numeral::operator/(mixed_numeral num2) const
{
	int i_p = 0;
	int n = (integral_part*denominator + numerator)*num2.denominator;
	int d = denominator*(num2.integral_part*num2.denominator + num2.numerator);
	return mixed_numeral(n, d);
}
int main()
{
	//transformNumerals(1789, 8);
	mixed_numeral num1, num2, num_sum, num_diff, num_mult, num_div;
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
			num1.SimplifyNumeral();
			cout << "Enter the second mixed numeral : " << endl;
			num2.getMnum();
			num2.SimplifyNumeral();
			num_sum = num1 + num2;
			cout << "The result mixed numeral is ";
			num_sum.SimplifyNumeral();
			break;
		}
		case '2':
		{
			cout << "Enter the first mixed numeral : " << endl;
			num1.getMnum();
			num1.SimplifyNumeral();
			cout << "Enter the second mixed numeral : " << endl;
			num2.getMnum();
			num2.SimplifyNumeral();
			num_diff = num1 - num2;
			cout << "The result mixed numeral is ";
			num_diff.SimplifyNumeral();
			break;
		}
		case '3':
		{
			cout << "Enter the first mixed numeral : " << endl;
			num1.getMnum();
			num1.SimplifyNumeral();
			cout << "Enter the second mixed numeral : " << endl;
			num2.getMnum();
			num2.SimplifyNumeral();
			num_mult = num1*num2;
			cout << "The result mixed numeral is ";
			num_mult.transformNumerals();
			break;
		}
		case '4':
		{
			cout << "Enter the first mixed numeral : " << endl;
			num1.getMnum();
			num1.SimplifyNumeral();
			cout << "Enter the second mixed numeral : " << endl;
			num2.getMnum();
			num2.SimplifyNumeral();
			num_div = num1/num2;
			cout << "The result mixed numeral is ";
			num_div.transformNumerals();
			break;
		}
		default:
			break;
		}
	}
	return 0;
}