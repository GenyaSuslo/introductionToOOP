#include<iostream>
using namespace std;

class String
{
	int size; //размер указывать лучше в байтах
	char* str; //адрес строки в динамической памяти
public:

	const char* get_str()const
	{
		return str;
	}

	//			Constructors

	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor: \t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;//strlen возвращает размер в символах, по этому +1,т.к. у нас в байтах
		this->str = new char[size] {};
		for (size_t i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" <<this <<endl;
	
	}

	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//			Methods
	void print()
	{
		cout << "Size: \t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");

	String str;
	str.print();
	String str1 = "Hello";
	cout << str1 << endl;
	
}