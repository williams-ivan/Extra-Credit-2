//Rational Arithmetic I
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Rational
{
	// Declaration of overloaded stream insertion operator
	friend ostream & operator << (ostream &, Rational r);
private:
	int numerator, denominator;
public:
	// Constructor builds a rational number n/d
	Rational(int n, int d) :numerator(n), denominator(d)
	{
		reduce();
	}
	Rational operator+(Rational r);
	Rational operator-(Rational r);
	Rational operator*(Rational r);
	Rational operator/(Rational r);
private:
	// This member function transforms a rational number into
	// reduced form where the numerator and denominator have 1
	// as greatest common factor
	void reduce();
};

//************************************************************
// This member function transforms a rational number into *
// reduced form where the numerator and denominator have 1 *
// as greatest common factor. *
//************************************************************
void Rational::reduce()
{
	bool negative = (numerator < 0) != (denominator < 0);
	numerator = abs(numerator);
	denominator = abs(denominator);
	int factor = 2;
	while (factor <= min(numerator, denominator))
	{
		if (numerator % factor == 0 && denominator % factor == 0)
		{
			numerator = numerator / factor;
			denominator = denominator / factor;
			continue;
		}
		factor++;
	}
	if (negative)
		numerator = -numerator;
}

//************************************************
// Overloaded stream insertion operator *
//************************************************
ostream & operator << (ostream &out, Rational r)
{
	out << r.numerator << "/" << r.denominator;
	return out;
}

Rational Rational::operator+(Rational r) {
	int n = (this->numerator * r.denominator) + (r.numerator * this->denominator), d = this->denominator * r.denominator; //calculates the numerator and the denominator for the new fraction
	return Rational(n, d); //returns the sum of the fractions
}

Rational Rational::operator-(Rational r) {
	int n = (this->numerator * r.denominator) - (r.numerator * this->denominator), d = this->denominator * r.denominator; //calculates the numerator and the denominator for the new fraction
	return Rational(n, d); //returns the sum of the fractions
}

Rational Rational::operator*(Rational r) {
	int n = this->numerator * r.numerator, d = this->denominator * r.denominator; //calculates the numerator and the denominator for the new fraction
	return Rational(n, d); //returns the sum of the fractions
}

Rational Rational::operator/(Rational r) {
	int n = this->numerator * r.denominator, d = this->denominator * r.numerator; //calculates the numerator and the denominator for the new fraction
	return Rational(n, d); //returns the sum of the fractions
}

int main()
{
	//cout << Rational(6, -12);
	//below outputs all of the arithmetic equations for the fractions
	cout << Rational(2, 3) << " + " << Rational(2, 10) << " = " << Rational(2, 3) + Rational(2, 10) << endl;
	cout << Rational(2, 3) << " - " << Rational(2, 10) << " = " << Rational(2, 3) - Rational(2, 10) << endl;
	cout << Rational(2, 3) << " * " << Rational(2, 10) << " = " << Rational(2, 3) * Rational(2, 10) << endl;
	cout << Rational(2, 3) << " / " << Rational(2, 10) << " = " << Rational(2, 3) / Rational(2, 10) << endl;
	cin.ignore();
	return 0;
}