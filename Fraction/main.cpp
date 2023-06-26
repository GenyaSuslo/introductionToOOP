#include<iostream>

using namespace std;

class Fraction
{
	//Data
	int integer; //целая часть
	int numerator; // числитель
	int denominator; //знаменатель

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//			Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor: " << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor: " << this << endl;

	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "SinglArgConstructor: " << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)//конструкторы равнозначны
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);//так как могут написать 0, сразу вызываем функцию с условием защиты
		cout << "TripleConstructor: \t " << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor: \t" << this << endl;
	}


	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}
	//Methods
	void print()const
	{
		if (integer)cout << integer;//если есть целая часть выводим ее на экран
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	void to_proper(const Fraction& other)
	{
		
		if (numerator > denominator)
		{
			this->integer = this->integer + (this->numerator - (this->numerator % this->denominator) / this->denominator);
		}
		cout << other.print;

	}
	void to_improper()
	{
		if (integer)
		{

		}

	}
};

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(0, " ");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;//default constructor
	A.print();

	//double b = 5;
	//cout << b << endl; 
	Fraction B = 5;
	B.print();
	//double c = 0.5;
	//cout << c << endl;
	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C;//CopyConstructor
	E.print();

	Fraction F;
	F = D;
	F.print();
#endif CONSTRUCTORS_CHECK

	Fraction A(2, 23, 7);
	A.print();


}
