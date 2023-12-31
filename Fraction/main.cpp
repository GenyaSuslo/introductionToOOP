﻿#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
#define delimeter "\n------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction& operator+(Fraction left, Fraction right);
Fraction& operator-(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
class Fraction
{
	//				Data
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

	//				Constructors
	Fraction() //конструктор по умолчанию
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor: " << this << endl;
	}

	explicit Fraction(int integer) //конструктор который принимает 1 параметр
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor: " << this << endl;

	}
	Fraction(int numerator, int denominator)//конструктор который принимает 2 параметра
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
	Fraction(const Fraction& other)// конструктор копирования
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
	Fraction(double decimal)
	{
		decimal += 1e-10; //1е - это 10,10 в -10 степени это 0,0000000001, это мы прибавляем к дробному значению
		//и закрываем 9 в периоде до значащих разрядов
		integer = decimal;//е-это экспонента, а экспонента это основание системы счисления, такак как здесь 10, то система 10ная,
		//а дальше мы работаем с колличеством разрядов
		decimal -=integer;
		denominator = 1e+9; //10 в 9 степени; точность всегда будет 9 знаков после запятой
		numerator = decimal * denominator;
		reduce();
		cout << "1ArgDConstructor: /t" << this << endl;
	}


	//				Operators
	Fraction& operator=(const Fraction& other)// конструктор присваивания
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:" << this << endl;
		return *this;
	}
	Fraction& operator++() //префиксный инкремент
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
	Fraction& operator--() //префиксный декремент
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

	//				Type-cast operators
	explicit operator int() const
	{
		return integer;
	}
	explicit operator double() const
	{
		return integer+(double)numerator/denominator;
	}


	//				Methods

	Fraction& reduce()
	{
		/*int more, less, rest;
		if (numerator > denominator) more = numerator, less = denominator;
		else less = numerator, more = denominator;*/
		to_proper();
		int less = numerator;
		int more = denominator;
		int rest;
		if (less == 0)return *this;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GSD = more;//GSD-Greatest Common Divisor наибольший общий делитель
		numerator /= GSD;
		denominator /= GSD;
		return *this;
	}

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
	/*void to_proper()
	{

		if (numerator > denominator)
		{
			this->integer = integer + ((numerator - (numerator % denominator ))/ denominator);
			this->numerator = numerator % denominator;
		}
		else cout << "дробь правильная";

	}*/
	/*void to_improper()
	{
		if (integer)
		{
			this->numerator = numerator + integer * denominator;
			this->integer = 0;
		}
		else cout << "нет целой части";
	}*/
	Fraction& to_improper()//делает неправильную дробь
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()//делает дробь правильную
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	/*Fraction operator *=(Fraction right)
	{
		this->to_improper();
		right.to_improper();
		Fraction result
		(
			this->get_numerator() * right.get_numerator(),
			this->get_denominator() * right.get_denominator()
		);
		return result;

	}*/

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	//void reduce() //работает только если есть общий делитель, дальше не хватило сил
	//{
	//	int del;
	//	while (numerator != denominator)
	//	{
	//		if (numerator > denominator)
	//		{
	//			numerator -= denominator;
	//			del = numerator;
	//		}
	//		else if (denominator > numerator)
	//		{
	//			denominator -= numerator;
	//			del = denominator;
	//		}
	//		else cout << "нет НОД";
	//	}
	//	this-> numerator/del;
	//	this->denominator / del;
	//}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator -=(const Fraction& other)
	{
		return *this = *this - other;
	}

};
Fraction operator*(Fraction left, Fraction right)//передача по значению сразу скопировала объекты в функцию и их можно изменять
{
	left.to_improper();//перевели в неправильные дроби
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
//Fraction operator/( Fraction left, Fraction right)
//{
//	left.to_improper();//перевели в неправильные дроби
//	right.to_improper();
//	return Fraction
//	(
//		left.get_numerator() * right.get_denominator(),
//		left.get_denominator() * right.get_numerator()
//	).to_proper();
//}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
//Fraction GCD(Fraction left, Fraction right)
//{
//	int a = left.get_denominator(), b = right.get_denominator();
//	if ( a< b)
//	{
//		swap(a, b);
//	}
//	while (a % b != 0) {
//		a = a % b;
//		swap(a, b);
//	}
//	return b;
//}
//Fraction NOK(Fraction left, Fraction right)
//{
//	int a = left.get_denominator(), b = right.get_denominator(),NOK;
//	return a*b/GCD(left, right);
//}
Fraction& operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * left.get_denominator() + right.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction& operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()

	).to_proper().reduce();

}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction left, const Fraction right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();

}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction left, const Fraction right)
{
	//return left > right || left == right;
	return !(left < right);
}
bool  operator<=(const Fraction left, const Fraction right)//когда вызывыаем готовю функцию берем значение по константной ссылке
{
	return!(left > right);
}


std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{

	if (obj.get_integer())os << obj.get_integer();//если есть целая часть выводим ее на экран
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*
	----------------------------------------
	5
	1/2
	2 3/4
	2(3/4)
	----------------------------------------
	*/

	/*int integer, numerator, denominator;

	is >> integer >> numerator >> denominator;

	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
	const int SIZE = 256;
	char buffer[SIZE] = {};
	is >> buffer;
	//is.getline(buffer,SIZE);
	int number[3] = {};
	int n = 0;//счетчик полученных(введенных) чисел
	char delimiters[] = "()/";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = std::atoi(pch);
	//atoi() - ASCI-string to 'int'? принимает строку и возвращает целое число, которое содержится в этой строке
	// 
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2:
		/*obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);*/ 
		obj=Fraction(number[0], number[1]);
		break;
	case 3:
		/*obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);*/ 
		obj= Fraction(number[0], number[1], number[2]);
		break;
	
	}
	return is;

}






//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATOR_CHECK
//#define INPUT_CHECK_1
//#define INPUT_CHECK_2
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OVER
void main()
{
	setlocale(LC_ALL, "ru");

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
#ifdef ARITHMETICAL_OPERATORS_CHECK

	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();

	A.to_improper();
	A.print();

	/*Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();*/
	A *= B;
	A.print();
#endif ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATOR_CHECK
	Fraction A(1, 3);
	Fraction B(5, 10);

	cout << (A<=B) << endl;
#endif COMPARISON_OPERATOR_CHECK

	/*Fraction A(840, 3600);
	A.print();
	A.reduce();
	A.print();*/
	/*Fraction A(5, 10);
	cout << A << endl;
	A.reduce();
	cout << A << endl;*/

	/*Fraction A(3, 15, 23);
	Fraction B(2, 12, 15);
	
	
	A.print(); B.print(); D.print();
	A += B;
	A.print();
	cout << typeid(cin).name() << endl;*/
	
	#ifdef INPUT_CHECK_1
		Fraction D;
		cout << "введите правильную дробь: " << endl;
		cin >> D;
		D.reduce();
		D.print();
	#endif INPUT_CHECK_1
	#ifdef INPUT_CHECK_2
		Fraction A, B, C;
		cout << "введите три простые дроби: "; cin >> A >> B >> C;
		cout << A << "\t" << B << "\t" << C << "\t" << endl;
	#endif INPUT_CHECK_2

	#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
		Fraction A = (Fraction)5;
		cout << A << endl;
		cout << delimeter;
		Fraction B; //default constructor
		cout << delimeter;
		B = Fraction(8);
		cout << delimeter;
		cout << B << endl;
		//Fraction C(12); //explicit конструктор можно вызвать только так
		Fraction C{ 12 }; //либо так
		cout << C << endl;
	#endif CONVERSIONS_FROM_OTHER_TO_CLASS
	
	#ifdef CONVERSION_FROM_CLASS_TO_OVER
		Fraction A(2, 1, 2);
		cout << A << endl;
		int a = (int)A;
		cout << a << endl;

		Fraction B(2, 3, 4);
		cout << B << endl;
		double b = (double)B;
		cout << b << endl;
	#endif CONVERSION_FROM_CLASS_TO_OVER
	
		Fraction A = 2.77;
		cout << A << endl;
		Fraction B = 3.333;
		cout << B << endl;
}
