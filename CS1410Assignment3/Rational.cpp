#include "Rational.h"

//Overloaded Constructors
Rational::Rational()
{
	numerator=0;
	denominator=1;
	inWords= new char;
	inWords="\0";
}
Rational::Rational(int N)
{
	numerator=N;
	denominator=1;
}
Rational::Rational(int N, int D)
{
	if(D!=0)
	{
		numerator=N;
		denominator=D;
	}
	else
	{
		cout<<"The denominator cannot equal zero, this rational numer is undefined."<<endl;
	}
}
Rational::Rational(string W)
{
	inWords = W;
}

//Copy Constructor
Rational::Rational(const Rational &obj)
{
	numerator=obj.numerator;
	denominator=obj.denominator;
	inWords = obj.inWords;
}

//Overloaded Assignment Operators
Rational& Rational::operator= (const Rational &rhs)
{
	//To keep it from copying itself (a=a)
	if(this!=&rhs)
	{		
		//Assign the numerator
		numerator=rhs.numerator;
		
		//Assign the denominator
		denominator=rhs.denominator;
		
		//Assign the inWords
		inWords=rhs.inWords;
		
		return *this;
	}
	else
	{
		return *this;
	}
}
Rational& Rational::operator= (const int N)
{
	int numer=0,denomin=1;
	if(numerator>0)
	{
		numerator= N;
		denominator=1;
	}
	else 
	{
		//Parse inWords
		/*stringstream ss(inWords);
		ss>>numerator;
		ss.ignore();
		ss>>denominator;*/

		//Set numerator and denominator
		//numerator=N;
		denominator=1;

		//Put back into a string
		stringstream s2;
		s2<<N<<"/"<<denominator;
		inWords=s2.str();
	}	
	return *this;
}
Rational& Rational::operator= (const string W)
{
	int num=0, num1=0, denom=0, denom1=0;
	//Parse inWords
	stringstream ss(inWords);
	ss>>num;
	ss.ignore();
	ss>>denom;

	//Parse W
	stringstream st(W);
	st>>num1;
	st.ignore();
	st>>denom1;

	num=num1;
	denom=denom1;

	//Put back into a string
	stringstream s2;
	s2<<num<<"/"<<denom;
	inWords=s2.str();
	return *this;
}

//Overloaded Arithmetic Binary Operators
Rational Rational::operator+(const Rational &obj)
{
	//Create temps
	int tempNum=0;
	int tempDenom=1;
	int objtempNum=0;
	int objtempDenom=1;

	//Initialized with ints
	if(numerator>0)
	{
		//Assign the temps
		tempNum=numerator*obj.denominator;
		tempDenom=denominator*obj.denominator;
		
		//Change the obj temps
		objtempNum=obj.numerator*denominator;
		objtempDenom=obj.denominator*denominator;

		//Add
		tempNum+=objtempNum;
	
		if(tempNum==0)
		{
			numerator=0;
			denominator=1;
		}
		else
		{
			//Set numerator and denominator to temps
			//numerator=tempNum;
			//denominator=tempDenom;			
		}
		//Create temps and simplify
		int& tempNumerator=tempNum;
		int& tempDenominator=tempDenom;
		Simplify(tempNumerator, tempDenominator);
		Rational a(tempNumerator, tempDenominator);
		return a;
	}
	//Initiallized with a string
	else
	{
		//parse inWords
		stringstream ss(inWords);
		ss>>tempNum;
		ss.ignore();
		ss>>tempDenom;
		
		//parse obj
		stringstream sr(obj.inWords);
		sr>>objtempNum;
		sr.ignore();
		sr>>objtempDenom;
		
		tempNum*=objtempDenom;
		objtempNum*=tempDenom;
		tempNum+=objtempNum;
		tempDenom*=objtempDenom;
		//numerator+=(objtempNum*tempDenom);
		//denominator=tempDenom*objtempDenom;

		//Create temps and simplify
		int& tempNumerator=tempNum; //numerator;
		int& tempDenominator=tempDenom;//denominator;
		Simplify(tempNumerator, tempDenominator);

		stringstream s2;
		s2<<tempNumerator<<"/"<<tempDenominator;
		inWords=s2.str();

		Rational b(inWords);
		return b;
	}			
}
Rational Rational::operator+(int N)
{
	int num=0, denom=0, newNum=0;
	if(numerator>0)
	{
		//Convert int to a fraction over denom
		N*=denominator;
		numerator+=N;

		//Create temps and simplify
		int& tempNum=numerator;
		int& tempDenom=denominator;

		Simplify(tempNum, tempDenom);	
	}
	else
	{
		stringstream ss(inWords);
		ss>>num;
		ss.ignore();
		ss>>denom;
		
		newNum=denom*N;
		newNum+=num;
		
		stringstream s2;
		s2<<newNum<<"/"<<denom;
		inWords=s2.str();	
	}	
	return *this;
}
Rational Rational::operator+(string W)
{
	int num=0, denom=0, inum=0, idenom=0;
	
	//parse W
	stringstream ss(W);
	ss>>num;
	ss.ignore();
	ss>>denom;
	cout<<"parsed W-numerator: "<<num<<endl;
	cout<<"parsed W-denominator: "<<denom<<endl;

	//parse inWords
	stringstream s2(inWords);
	s2>>inum;
	s2.ignore();
	s2>>idenom;
	cout<<"parsed inWords-numerator: "<<inum<<endl;
	cout<<"parsed inWords-denominator: "<<idenom<<endl;
	
	//initiallized with int
	if(inWords!="0/")
	{
		cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;

		//Multiply by denominators
		inum*=denom;
		idenom*=denom;
		inum+=num;
		numerator=inum;
		denominator=idenom;

		cout<<"numerator: "<<numerator<<endl;
		cout<<"denominator: "<<denominator<<endl;

		//Create temps and simplify
		int& tempNum=numerator;
		int& tempDenom=denominator;
		Simplify(tempNum, tempDenom);

		cout<<"simplified numerator: "<<numerator<<endl;
		cout<<"simplified denominator: "<<denominator<<endl;

		//Put back into a string
		stringstream st;
		st<<numerator<<"/"<<denominator;
		inWords=st.str();	
		cout<<"inWords: "<<inWords<<endl;				
	}
	
	//initiallized with string
	else 
	{
		//Multiply by denominators
		numerator*=denom;
		numerator+=num;
		denominator*=denom;

		cout<<"str numerator: "<<numerator<<endl;
		cout<<"str denominator: "<<denominator<<endl;
		
		//Create temps and simplify
		int& tempNumerator=numerator;
		int& tempDenominator=denominator;
		Simplify(tempNumerator, tempDenominator);
	}
	return *this;
}

//Overloaded Compound Assignment Operators
Rational& Rational::operator+= (const Rational &obj)
{
	*this=*this+obj;
	return *this;
}
Rational& Rational::operator+=(int num)
{
	*this=*this+num;
	return *this;
}
Rational& Rational::operator+=(string W)
{
	*this = *this + W;
	return *this;	
}

//Relational Operators
bool Rational::operator==(const Rational &obj)
{	
	if (numerator==obj.numerator)
	{
		if(denominator==obj.denominator)
		{
			if(inWords==obj.inWords)
			{
				return true;
			}
		}
	}
	return false;		
}
bool Rational::operator>(const Rational &obj)
{
	float objFrac, Frac;
	
	//Find the float value of the fractions
	objFrac=(float)obj.numerator/obj.denominator;
	Frac=(float)numerator/denominator;
	
	//Compare
	if(Frac>objFrac)
	{
		return true;
	}
	return false;
}

//Prefix Operator
Rational &Rational::operator++()
{
	//Create temps
	int& tempNum=numerator;
	int& tempDenom=denominator;
	
	//Increment
	numerator+=denominator;

	//Simplify
	Simplify(tempNum, tempDenom);
	
	return *this;	
}

//Postfix operator
Rational Rational::operator++(int)
{
	Rational temp(numerator, denominator);
		
	//Increment
	numerator+=denominator;

	//Create temps
	int& tempNum=numerator;
	int& tempDenom=denominator;

	stringstream s2;
	s2<<tempNum<<"/"<<tempDenom;
	temp=s2.str();

	//Simplify
	temp.Simplify(tempNum, tempDenom);
	
	return temp;	
}

//Rational Object to Double
Rational::operator double()
{
	double convert;

	//Cast the fraction as a double
	convert=(double)numerator/(double)denominator;
	
	return convert;
}

//Insertion and Extraction Operators
ostream &operator << (ostream &strm, Rational &obj) 
{
	//Establish << as Cout function
	obj.Cout(strm) ;
	
	return strm ;
}
void Rational::Cout(ostream &out)
{
	int num, denom;
	if(inWords.length()>1)
	{
		//parse
		stringstream ss(inWords);
		ss>>num;
		ss.ignore();
		ss>>denom;

		if(denom==1)
		{
			out<< num<< endl;	
		}
		else
		{
			out << inWords << endl;	
		}
	}	
	else if(denominator!=1)
	{
		out << numerator << "/" << denominator << endl;
	}
	else if(denominator==1)
	{
		out << numerator << endl;
	}
}

istream &operator>> (istream &strm, Rational &obj)
{
	//Create temps
	int &tempNum=obj.numerator;
	int &tempDenom=obj.denominator;

	//Get cin inputs
	cout<<"Please input the Numerator: ";
	strm>>obj.numerator;
	cout<<"Please input the Denominator: ";
	strm>>obj.denominator;

	obj.Simplify (tempNum, tempDenom);
	
	return strm;
}

//Destructor
Rational::~Rational(void)
{
}

/*Rational operator+(int lhs, Rational &rhs)
{
	cout << "Inside the overloading + operator -- Outside of the class " << endl ;
	int newNum, newDenom, num, denom;

	//Add the integer and the Rational object
	if(rhs.inWords=="/0")
	{		
		lhs*=rhs.denominator;
		newNum= rhs.numerator+lhs;
		newDenom=rhs.denominator;

		int &tempNum=newNum;
		int &tempDenom=newDenom;

		rhs.Simplify (tempNum, tempDenom);
		Rational a(tempNum, tempDenom);
		
		return a;
	}
	else 
	{
		stringstream ss(rhs.inWords);
		ss>>num;
		ss.ignore();
		ss>>denom;

		lhs*=denom;
		num+=lhs;

		int &tempNum=num;
		int &tempDenom=denom;

		rhs.Simplify (tempNum, tempDenom);
		stringstream sr;
		sr<<tempNum<<"/"<<tempDenom;
		rhs.inWords=sr.str();

		Rational b(rhs.inWords);
		return b;
	}
}*/