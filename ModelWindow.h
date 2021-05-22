#pragma once
#include <sstream>
/**
 * \brief Класс ModelWindow для работы с окнами
 */
class ModelWindow
{
private:
	std::string title;
	unsigned int _x;
	unsigned int _y;
	unsigned int height;
	unsigned int width;
	std::string color;
	bool show, border;

	static constexpr int MAX_HEIGHT = 1080;
	static constexpr int MAX_WIDTH = 1920;

	std::string getTitle() const;
	unsigned int getX() const;
	unsigned int getY() const;
	unsigned int getHeight() const;
	unsigned int getWidth() const;
	std::string getColor() const;
	bool getShow() const;
	bool getBorder() const;

public:
	/**
	* \brief Конструктор по умолчанию
	*/
	ModelWindow() = default;
	/**
	* \brief Параметризованный конструктор
	*/
	ModelWindow(const std::string title, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height, const std::string colorCode= "000000", const bool show = true, const bool border = true);
	/**
	* \brief Деструктор по умолчанию
	*/
	~ModelWindow() = default;	

	/**
	* \brief сеттер заголовка
	*/
	void setTitle(const std::string title);
	/**
	* \brief сеттер координаты х
	*/
	void setX(const unsigned int x);
	/**
	* \brief сеттер координаты у
	*/
	void setY(const unsigned int y);
	/**
	* \brief сеттер высоты
	*/
	void setHeight(const unsigned int height);
	/**
	* \brief сеттер ширины
	*/
	void setWidth(const unsigned width);
	/**
	* \brief сеттер цвета окна
	*/
	void setColor(const std::string colorCode);
	/**
	* \brief сеттер установки видимости
	*/
	void setShow(const bool show);
	/**
	* \brief сеттер рамки
	*/
	void setBorder(const bool border);
	
	/**
	* \brief метод сдвига окна по горизонтали
	*/
	void moveHorisontal(const int delta=0);
	/**
	* \brief метод сдвига окна по вертикали
	*/
	void moveVertical(const int delta=0);
	/**
	* \brief смена размеров окна
	*/
	void changeFormat(const unsigned int height, const unsigned int width);
	/**
	* \brief смена режима видимости
	*/
	void changeVisible(const bool visible);
	/**
	* \brief чекер режима видимости
	*/
	bool isVisible() const;

	/**
	* \brief Перегруженный оператор ввода
	*/
	friend std::istream& operator>> (std::istream& in, ModelWindow& m);

	/**
	* \brief Перегруженный оператор вывода
	*/
	friend std::ostream& operator<< (std::ostream& out, const  ModelWindow& m);
};