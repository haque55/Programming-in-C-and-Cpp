#include <iostream>
#include "fraction.h"

Fraction::Fraction() {
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d) {
	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b) {
	// Implementing Euclid's Algorithm to calculate GCD
	if (a == b){
        return a;
    } else if (a > b) {
		return gcd(a-b, b);
	} else return gcd(a, b - a);
}

int Fraction::lcm(int a, int b) {
	return a * b / gcd(a, b);
}

std::ostream& operator<<(std::ostream &out, const Fraction &f) {
	out << f.num << "/" << f.den;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction &f) {
	char temp;
	in >> f.num >> temp >> f.den;
	// Check if denominator is 0 or the division sign isn't correct
	if (f.den == 0 || temp != '/') {
		std::cout << "Input error! Denominator set to 1.\n";
		f.den = 1;
	}
	return in; 
}

Fraction Fraction::operator+(const Fraction& secondFrac) {
	return Fraction((*this).num * lcm((*this).den, secondFrac.den) / 
					(*this).den + secondFrac.num * 
					lcm((*this).den, secondFrac.den) / secondFrac.den, 
					lcm((*this).den, secondFrac.den));
}

Fraction Fraction::operator-(const Fraction& secondFrac) {
	return Fraction((*this).num * lcm((*this).den, secondFrac.den) / 
					(*this).den - secondFrac.num * 
					lcm((*this).den, secondFrac.den) / secondFrac.den, 
					lcm((*this).den, secondFrac.den));
}

Fraction operator*(const Fraction& firstFrac, const Fraction& secondFrac) {
	// Multiply numerators together and denominators together
	return Fraction(firstFrac.num * secondFrac.num,
					firstFrac.den * secondFrac.den);
}

Fraction operator/(const Fraction& firstFrac, const Fraction& secondFrac) {
	// Multiply first numerator with second denominator
	// and multiply first denominator with second numerator
	return Fraction(firstFrac.num * secondFrac.den,
					firstFrac.den * secondFrac.num);
}

Fraction& Fraction::operator=(const Fraction& obj) {
    num = obj.num;
    den = obj.den;
    return *this;
}

bool Fraction::operator>(const Fraction& secondFrac) {
	// Calculate first fraction by casting and assigning it as double to first
	double first = ((double) (*this).num) / (*this).den;
	// Calculate second fraction by casting and assigning it as double to second
	double second = ((double) secondFrac.num) / secondFrac.den;
    return (first > second);
}

bool Fraction::operator<(const Fraction& secondFrac) {
	// Calculate first fraction by casting and assigning it as double to first
	double first = ((double) (*this).num) / (*this).den;
	// Calculate second fraction by casting and assigning it as double to second
	double second = ((double) secondFrac.num) / secondFrac.den;
    return (first < second);
}