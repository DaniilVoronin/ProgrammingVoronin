#include <iostream>
#include "GeometricFigure.h"

using namespace std;

// функция вывода меню

void menu()
{
	cout << "1 - Circle, 2 - Rectangle, 3 - Triagle. Enter: 0 to End" << endl;
	cout << "Enter num for test " << endl;
}

int main() {
	while (true)
	{
		auto circle = Сircle();
		auto rectangle = Rectangle();
		auto triagle = Triagle();
		int i;
		menu();
		cin >> i;
		switch (i)
		{
		case 1:
		{
			cin >> circle;
			circle.getArea();
			circle.getPerimeter();
			cout << circle;
			break;
		}
		case 2:
		{
			cin >> rectangle;
			rectangle.getArea();
			rectangle.getPerimeter();
			cout << rectangle;
			break;
		}
		case 3:
		{
			cin >> triagle;
			triagle.getArea();
			triagle.getPerimeter();
			cout << triagle;
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
}