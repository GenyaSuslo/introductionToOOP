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
	Fraction& operator++()//перфиксный инкремент
	{
		integer++;
		return *this;
	}
	Fraction& operator++(int)// постфиксный инкремент
	{
		Fraction old = *this;
		integer++;
		return *this;
	}
	Fraction& operator--()//перфиксный декремент
	{
		integer--;
		return *this;
	}
	Fraction& operator--(int)// постфиксный декремент
	{
		Fraction old = *this;
		integer--;
		return *this;
	}
	Fraction& operator+=(const Fraction other)
	{
		
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
	void to_proper()
	{
		
		if (numerator > denominator)
		{
			this->integer = integer + ((numerator - (numerator % denominator ))/ denominator);
			this->numerator = numerator % denominator;
		}
		else cout << "дробь правильная";
		
	}
	void to_improper()
	{
		if (integer)
		{
			this->numerator = numerator + integer * denominator;
			this->integer = 0;
		}
		else cout << "нет целой части";
	}
	void reduce()
	{
		int del;
		while (numerator != denominator)
		{
			if (numerator > denominator)
			{
				numerator -= denominator;
				del = numerator;
			}
			else if (denominator > numerator)
			{
				denominator -= numerator;
				del = denominator;
			}
			else cout << "нет НОД";
		}
		this-> numerator/del;
		this->denominator / del;
	}
		
};

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, " ");

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
	A.to_proper();
	A.print();
	Fraction B(2, 2, 7);
	B.to_improper();
	B.print();
	B.to_proper();
	B.print();
	Fraction C(2, 12, 49);
	C.reduce();
	C.print();


}
