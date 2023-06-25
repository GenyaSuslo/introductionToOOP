#include<iostream>

using namespace std;

#define delimiter "\n----------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x(void)const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this-> x = x;
	}
	void set_y(double y)
	{
		this-> y = y;
	}
	//				Constructor:
	
	/*Point()
	{
		x = y = double();	// type() - это значение по умолчанию для заданного типа
							// т.о. мы якобы вызываем конструктор по умолчанию для заданного типа
		cout << "DefaultConstructor: \t\t" << this << endl;//всегда можем определить адрес объекта
	}*/

	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor: \t"<<this<<endl;
	}*/
	
	Point(double x=0,double y=0) //более универсальный
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}
	//				Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;

	}

	//				Methods:
	double distance(const Point& other)const //константный метод который не изменяет объект для которого вызывается
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;

	}
	void print()
	{
		cout << "X = " << x << "\t Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B) //передаче по константной ссылке,чтобы не изменить значение
{
	
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);

}


//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHEK

void main()
{
	setlocale(0, "");
#ifdef STRUCT_POINT
	//type name;
	int a;//объявление переменной 'а' типа int
	Point A;// объявление переменной 'А' типа Point
	//создание объекта 'A'  структуры Point
	//создание экземпляра 'А' структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;

#endif//STRUST_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << "A:\t " << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "B:\t " << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;

	cout << "расстояние от точки 'А' до точки 'Б':\t " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "расстояние от точки 'Б' до точки 'А':\t " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "расстояние от точки 'А' до точки 'Б':\t " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "расстояние от точки 'Б' до точки 'А':\t " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK
	
#ifdef CONSTRUCTOR_CHEK
	Point A;// default constructor
	A.print();

	Point B = 5; //Single-argument constructor, конструктор с 1м параметром
	B.print();
	Point C(2, 3);
	C.print();
	Point D = C;	//CopyConstructor
	D.print();
	Point E;
	E = D;		//CopyAssigment
	E.print();
#endif CONSTRUCTOR_CHEK

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
}