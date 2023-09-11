#pragma once

#include<iostream>
using namespace std;
#define tab "\t"
#define delimeter "---------------------------------------"



//////////////////////////////////////////////////////////
////////объ€вление класса- Class declaration /////////////
//////////////////////////////////////////////////////////
class String
{
	int size; //размер указывать лучше в байтах
	char* str; //адрес строки в динамической пам€ти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//			Constructors

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//			Operators

	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i) const;
	char& operator[](int i);
	//			Methods
	void print();
};

std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);

//////////////////////////////////////////////////////////
////////объ€вление класса- Class declaration /////////////
//////////////////////////////////////////////////////////
