#include "String.h"
//--------------------------------------------------------------//



#define BASE_CHECK
#define CALLING_CONSTRUCTORS
void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	String str(5);
	str.print();

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	cout << delimeter << endl;
	String str2 = "World";
	cout << str2 << endl;

	cout << delimeter << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimeter << endl;

	String str4;
	str4 = str1 + str2;
	cout << str4 << endl;

	String str5 = str4;
	cout << str5 << endl;
#endif  BASE_CHECK

	
}