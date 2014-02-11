#include"Rational.h"

int main ()
{
	double pause;
	
	//Overloaded Constructors
	cout<<"Overloaded Constructors:"<<endl;
	Rational a;
	cout<<"Default: " << a << endl;
	Rational b(3);
	cout<<"b(3): " << b << endl;
	Rational c(-2,5);
	cout<<"c(-2,5): " << c << endl;
	Rational d("1/2");
	cout<<"d(\"1/2\"): " << d << endl << endl;

	//Copy Constructor
	Rational e(c);
	cout<<"Copy constructor of object initialized with ints (c(-2,5)): " << e << endl;
	Rational f(d);
	cout<<"Copy constructor of object initialized with string (d(\"1/2\")): " << f << endl << endl;

	//Overloaded Assignment Operators
	cout<<"Overloaded Assignment Operators"<<endl;
	Rational g(6,7);
	Rational j=g;
	cout<<"Int initialized object to object (g(6/7), j=g): "<<j<<endl;
	Rational k=3;
	cout<<"Int initialized object to int (k=3): "<<k<<endl;
	Rational l="5/6";
	g=l;
	cout<<"Int initialized object to string (l=\"5/6\"): "<<g<< endl;
	Rational i("4/9");
	j=i;
	cout<<"String initialized object to object (i(\"4/9\"), j=i): "<<j<<endl;
	i=3;
	cout<<"String initialized object to int (i=3): "<<i<<endl;
	i=l;
	cout<<"String initialized object to string (l=\"5/6\", i=l): "<<i<<endl<<endl;

	//Overloaded Arithemtic Operators
	Rational m(4,5);
	Rational m2("4/5");
	Rational n(2,3);
	Rational n2("2/3");
	Rational s(3,8);
	Rational s2("3/8");
	
	cout<<"Overloaded Arithemtic Operators"<<endl;
	Rational o=m+n;
	cout<<"obj(4,5) + obj(2,3): "<<o<<endl;
	Rational o2=m2+n2;
	cout<<"obj(\"4/5\") + obj(\"2/3\"): "<<o2<<endl;
	Rational p=n+3;
	cout<<"obj(2,3) + int 3: "<<p<<endl;
	Rational p2=n2+3;
	cout<<"obj(\"2/3\") + int 3: "<<p2<<endl;
	Rational r2=s+string("1/2");
	cout<<"obj(3,8) + str(\"1/2\"): "<<r2<<endl;
	Rational r=s2+string("1/2");
	cout<<"obj(\"3/8\") + str(\"1/2\"): "<<r<<endl;

	//+= operator
	cout<<"+= Operator: "<<endl;
	m+=n;
	cout<<"(4,5) += (2,3): "<<m<<endl;
	m2+=n2;
	cout<<"(\"4/5\") += (\"2/3\"): "<<m2<<endl;
	n+=3;
	cout<<"(2,3) += 3: "<<n<<endl;
	n2+=3;
	cout<<"(\"2/3\") += 3: "<<n2<<endl;
	s+=string("1/2");
	cout<<"(3,8) += (\"1/2\"): "<<s<<endl;
	s2+=string("1/2");
	cout<<"(\"3/8\") += (\"1/2\"): "<<s2<<endl;

	//Relational operators
	cout<<"Relational Operators: "<<endl;
	if(m==n)
	{
		cout<<"m==n"<<endl;
	}
	else
	{
		cout<<"m is not equal to n"<<endl;
	}
	if(m>n)
	{
		cout<<"m is greater than n"<<endl;
	}
	else
	{
		cout<<"m is not greater than n"<<endl; 
	}

	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
	for(int i=0; i<4; i++)
	{
		cout<<"a++: "<<a++<<endl;
		cout<<"++b: "<<++b<<endl;
	}

	//Double conversion function
	Rational doubl(4,5);
	double doub=double(doubl);
	cout<<"double conversion of (4/5): "<<doub<<endl;

	cin>> pause;
}
	