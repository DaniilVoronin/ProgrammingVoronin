#include <iostream>

using namespace std;

class ModelWindow {
public:
	/**
		* \brief конструктор по умолчанию
		*/
	ModelWindow() {

	}
	/**
		* \brief конструктор формы
		* \param heading заголовок, x , y height высота, length длина, color цвет, stateVisibility состояни видимости, stateFrame состояние окна
		*/
	ModelWindow(string heading, int x, int y, int height, int length, string color, string stateVisibility, string stateFrame) {

	}
	/**
		* \brief деструктор по умолчанию
		*/
	~ModelWindow() {

	}
	/**
		* \brief геттер
		* \return Возвращает x
		*/
	int GetX() const {

	}
	/**
		* \brief геттер
		* \return Возвращает y
		*/
	int GetY() const {

	}
	/**
		* \brief геттер
		* \return Возвращает Height
		*/
	int GetHeight() const {

	}
	/**
		* \brief геттер
		* \return Возвращает Length
		*/
	int GetLength() const {

	}
	/**
		* \brief геттер
		* \return Возвращает Heading
		*/
	string GetHeading() const {

	}
	/**
		* \brief геттер
		* \return Возвращает Color
		*/
	string GetColor() const {

	}
	/**
		* \brief геттер
		* \return Возвращает StateVisibility
		*/
	string GetStateVisibility() const {

	}
	/**
		* \brief геттер
		* \return Возвращает StateFrame
		*/
	string GetStateFrame() const {

	}
	/**
		* \brief сеттер цвета
		* \param color
		*/
	void SetColor(const string color) {

	}
	/**
		* \brief сеттер видимости
		* \param color
		*/
	void SetStateVisibility(const string stateVisibility) {

	}
	/**
		* \brief сеттер рамки
		* \param StateFrame
		*/
	void SetStateFrame(const string stateFrame) {

	}
	/**
		* \brief метод изменения положения рамки по x с проверкой на границы экрана
		* \param x
		*/
	void MoveWindowX(const int x) {

	}
	/**
		* \brief метод изменения положения рамки по y с проверкой на границы экрана
		* \param y
		*/
	void MoveWindowY(const int y) {

	}
private:
	string heading;
	int x;
	int y;
	int height;
	int length;
	string color;
	string stateVisibility;
	string stateFrame;
};