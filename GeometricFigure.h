#pragma once
#include <sstream>

/**
* \brief Класс геометрическая фигура
*/
class GeometricFigure {

protected:
	/**
	* \brief Конструктор 
	*/
	GeometricFigure() = default;
	/**
	* \brief Деструктор 
	*/
	~GeometricFigure() = default;
	/**
	* \brief Периметр
	*/
	double perimeter = 0;
	/**
	* \brief Площадь
	*/
	double area = 0;
	/**
	* \brief метод проверки ввода
	*/
	double checkValue(const double value) const;
	/**
	* \brief метод проверки ввода angle
	*/
	double checkAngle(double value) const;


public:
	/**
	* \brief виртуальное объявление метода нахождения периметра
	*/
	virtual double getPerimeter() = 0;
	/**
	* \brief виртуальное объявление метода нахождения площади
	*/
	virtual double getArea() = 0;
	/**
	* \brief Перегруженный оператор вывода
	*/
	friend std::ostream& operator<< (std::ostream& out, const GeometricFigure& geometricFigure);

};

/**
* \brief Класс круг
*/
class Сircle : public GeometricFigure {

private:
	/**
	* \brief радиус круга
	*/
	double R;

public:
	/**
	* \brief Конструктор по умолчанию
	*/
	Сircle() = default;
	/**
	* \brief Конструктор параметризованный
	*/
	Сircle(const double R);
	/**
	* \brief Конструктор копирования
	*/
	Сircle(const Сircle& circle);
	/**
	* \brief Деструктор
	*/
	~Сircle() = default;
	/**
	* \brief метод нахождения периметра
	*/
	double getPerimeter() override;
	/**
	* \brief метод нахождения площади
	*/
	double getArea() override;
	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Сircle& circle);


};

/**
* \brief Класс прямоугольник
*/
class Rectangle : public GeometricFigure {

private:
	/**
	* \brief  поля - стороны прямоугольника
	*/
	double a, b;
public:
	/**
	* \brief Конструктор по умолчанию
	*/
	Rectangle() = default;
	/**
	* \brief Конструктор параметризованный
	*/
	Rectangle(double a, double b);
	/**
	* \brief Конструктор копирования
	*/
	Rectangle(const Rectangle& rectangle);
	/**
	* \brief Деструктор
	*/
	~Rectangle() = default;
	/**
	* \brief метод нахождения периметра
	*/
	double getPerimeter() override;
	/**
	* \brief метод нахождения площади
	*/
	double getArea() override;
	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Rectangle& rectangle);
};

/**
* \brief Класс треугольник
*/
class Triagle : public GeometricFigure {

private:
	/**
	* \brief  сторона, высота и угол
	*/
	double a, h, angle;

public:
	/**
	* \brief Конструктор по умолчанию
	*/
	Triagle() = default;
	/**
	* \brief Конструктор параметризованный
	*/
	Triagle(double a, double h, double angle);
	/**
	* \brief Конструктор копирования
	*/
	Triagle(const Triagle& r);
	/**
	* \brief Деструктор
	*/
	~Triagle() = default;
	/**
	* \brief метод нахождения периметра
	*/
	double getPerimeter() override;
	/**
	* \brief метод нахождения площади
	*/
	double getArea() override;
	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Triagle& triagle);
};