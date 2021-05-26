#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//без спецификации исключений

void First(double FirstSide, double SecondSide, double ThirdSide, double &Ans) {
	if ((FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)) {
		throw 'E';
	}
	Ans = FirstSide + SecondSide + ThirdSide;
}

//со спецификацией throw();

void Second(double FirstSide, double SecondSide, double ThirdSide, double &Ans) throw() {
	if ((FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)) {
		throw 'E';
	}
	Ans = FirstSide + SecondSide + ThirdSide;
}

//с конкретной спецификацией;

void Third(double FirstSide, double SecondSide, double ThirdSide, double &Ans) throw(invalid_argument) {
	if ((FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)) {
		throw invalid_argument("Error, (FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)");
	}
	Ans = FirstSide + SecondSide + ThirdSide;	
}

//пустой класс ошибки

class MyExceptionFirst
{
};

//Спецификация с собственным реализованным исключением (пустой класс)

void ClassExceptionFirst(double FirstSide, double SecondSide, double ThirdSide, double &Ans) {
	if ((FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)) {
		throw MyExceptionFirst();
	}
	Ans = FirstSide + SecondSide + ThirdSide;	
}

 //класс ошибки с полями

class MyExceptionSecond
{
public:
	MyExceptionSecond(double data) {
		this->data = data;
	}
	double GetdataState() {
		return data;
	}
private:
	double data;
};

//Спецификация с собственным реализованным исключением (независимый класс с полями)

void ClassExceptionSecond(double FirstSide, double SecondSide, double ThirdSide, double &Ans) {
	if ((FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)) {
		throw MyExceptionSecond(0);
	}
	Ans = FirstSide + SecondSide + ThirdSide;
}

//класс наследуемый от стандартного класса ошибки

class MyExceptionThird : public exception
{
public:
	const char* what() const throw() {
		return "Error, (FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)\n";
	}
};

//Спецификация с собственным реализованным исключением (наследник от стандартного исключения с полями (exception))

void ClassExceptionThird(double FirstSide, double SecondSide, double ThirdSide, double &Ans) {
	if ((FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)) {
		throw MyExceptionThird();
	}
	Ans = FirstSide + SecondSide + ThirdSide;
}

//Функция для ввода сторон треугольника

void GetPerimeter(void(*Func)(double, double, double, double&)) {
	double FirstSide, SecondSide, ThirdSide, Ans;
	cin >> FirstSide >> SecondSide >> ThirdSide;
	Func(FirstSide, SecondSide, ThirdSide, Ans);
	cout << "Perimeter = " << Ans << endl;

}

int main()
{
	cout << "Calculate Perimeter " << endl;
	//Error_1
	try
	{
		GetPerimeter(First);
	}
	catch (char)
	{
		cout << "Error, (FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)" << endl;
	}
	//Error_2
	try
	{
		GetPerimeter(Second);
	}
	catch (char)
	{
		cout << "Error, (FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)" << endl;
	}
	//Error_3
	try
	{
		GetPerimeter(Third);
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}
	//Error_4.1
	try
	{
		GetPerimeter(ClassExceptionFirst);
	}
	catch (MyExceptionFirst)
	{
		cout << "Error, (FirstSide <= 0) || (SecondSide <= 0) || (ThirdSide <= 0)" << endl;
	}
	//Error_4.2
	try
	{
		GetPerimeter(ClassExceptionSecond);
	}
	catch (MyExceptionSecond &ex)
	{
		cout << "Exception - " << ex.GetdataState() << endl;
	}
	//Error_4.3
	try
	{
		GetPerimeter(ClassExceptionThird);
	}
	catch (MyExceptionThird &ex)
	{
		cout << ex.what() << endl;
	}
}