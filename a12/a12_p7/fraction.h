// simple class for fractions

#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {
	private:						// internal implementation is hidden
		int num;					// numerator
		int den;					// denominator

		int gcd(int a, int b);		// calculates the gcd of a and b
		int lcm(int a, int b);

	public:
		Fraction();					// empty constructor
		Fraction(int, int = 1); 	// constructor taking values for fractions 
									// and integers. Denominator by default is 1
		
		// Overloaded operator friend functions to work with Fraction instance
		friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
		friend std::istream& operator>>(std::istream &in, Fraction &f);

		friend Fraction operator*(const Fraction& firstFrac, 
								  const Fraction& secondFrac);
		friend Fraction operator/(const Fraction& firstFrac,
								  const Fraction& secondFrac);

		// Overloaded operator methods to work with Fraction instance
		Fraction operator+(const Fraction& secondFrac);
		Fraction operator-(const Fraction& secondFrac);
		
		Fraction& operator=(const Fraction& obj);

		bool operator>(const Fraction& secondFrac);
		bool operator<(const Fraction& secondFrac);
		
};

#endif /* FRACTION_H_ */