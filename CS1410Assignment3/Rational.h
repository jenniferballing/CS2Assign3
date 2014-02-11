#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;

class Rational
{
	int numerator;
	int denominator;
	string inWords;
	
	void Simplify(int &num, int &denom) 
	{ 
		int gcd=ComputeGCD(num,denom); 
		num=num/gcd; denom=denom/gcd; 
	}
	int ComputeGCD(int num, int denom) 
	{
		int remainder= denom % num; 
		
		while (remainder != 0) 
		{ 
			denom = num; 
			num = remainder; 
			remainder= denom % num; 
		} return num; 
	} 
		
	public:
		//Constructors
		Rational(void);
		Rational(int);
		Rational(int, int);
		Rational (string W);

		//Copy Constructor
		Rational(const Rational &);
		
		//Assignment Operators
		Rational& operator= (const Rational&);
		Rational& operator= (const int);
		Rational& operator= (const string);
		
		//Addition Operators
		Rational operator+(const Rational &);
		Rational operator+(int);
		Rational operator+(string);

		//Compound Assignment Operators
		Rational& operator+= (const Rational &);
		Rational& operator+=(int);
		Rational& operator+=(string);

		//Conditional Operators
		bool operator==(const Rational &);
		bool operator>(const Rational &);
		
		//Increment Operators
		Rational& operator++();
		Rational operator++(int);

		//Convert Object to Double
		operator double();

		//Insertion and Extraction
		void Cout (ostream & out);
		friend Rational operator+(int lhs, Rational &rhs);
		friend ostream &operator<<(ostream &strm, Rational &obj);
		friend istream &operator >> (istream &strm, Rational &obj);

		//Destructor
		~Rational(void);
};

//Outside Overloaded Functions
ostream &operator<<(ostream &strm, Rational &obj);
istream &operator>>(istream &strm, Rational &obj);
Rational operator+(int lhs, Rational &rhs);
#endif

