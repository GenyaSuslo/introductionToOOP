#include "String.h"

// //////////////////////////////////////////////////////////

////////орпеделение класса- Class definition /////////////

//:: Scope operator(оператор разрешения видимости)
// открытие {} и закрытие скобок созадет область видимости и формирует пространство имен
//scope::name
//namespace::name  сначала название именного пространства и потом имя что хотим достатать
int String::get_size()const
{
	return size;
}

const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//			Constructors
// при помощи explicit мы только объявляем метод
// ключевое слово explicit можно использовать только внутри класса
String::String(int size/* = 80*/) :size(size), str(new char[size] {})
{
	cout << "DefConstructor: \t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1) //конструктор для ввода строки
{
	//strlen возвращает размер в символах, по этому +1,т.к. у нас в байтах

	for (size_t i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "SinglArgConstructor:\t" << this << endl;
}
String::String(const String& other) : String(other.size)
{
	//DeepCopy
	cout << "CopyConstructor: \t" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)	//конструктор переноса
{
	//Shaloow Copy
	/*this->size = other.size;
	this->str = other.str;*/
	other.size = 0;
	other.str = 0;
	cout << "MoveConstructor: \t" << this << endl;
}

String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}

//			Operators

String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[]this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];

	cout << "CopyAssignment: \t" << this << endl;

	return *this;
}

String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssigment:\t" << this << endl;
	return *this;
}
char String::operator[](int i) const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
//			Methods
void String::print()
{
	cout << "Size: \t" << size << endl;
	cout << "Str:\t" << str << endl;
}


//			Перегрузка за Классом

String operator+(const String& left, const String& right)
{
	/*const int a = 2;
	a = 3;*/
	String cat(left.get_size() + right.get_size() - 1);

	for (int i = 0; i < left.get_size(); i++)
	{
		/*cat.get_str()[i] = left.get_str()[i];*/
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		/*cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
		cat[i + left.get_size() - 1] = right[i];
	}

	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}


////////определение класса- Class definition /////////////
//////////////////////////////////////////////////////////
