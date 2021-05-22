#include "ModelWindow.h"

ModelWindow::ModelWindow(const std::string title, const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height, const std::string colorCode, const bool show, const bool border)
{
	if ((y + height) > MAX_HEIGHT) throw "Height value is too big";
	if ((width + x) > MAX_WIDTH) throw "Width value is too big";
	setTitle(title);
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
	setColor(colorCode);
	setShow(show);
	setBorder(border);
}

void ModelWindow::setTitle(const std::string title)
{
	this->title = title;
}

void ModelWindow::setX(const unsigned int x)
{
	this->_x = x;
}

void ModelWindow::setY(const unsigned int y)
{
	this->_y = y;
}

void ModelWindow::setHeight(const unsigned int height)
{
	this->height = height;
}

void ModelWindow::setWidth(const unsigned width)
{
	this->width = width;
}

void ModelWindow::setColor(const std::string colorCode)
{
	this->color = colorCode;
}

void ModelWindow::setShow(const bool show)
{
	this->show = show;
}

void ModelWindow::setBorder(const bool border)
{
	this->border = border;
}

void ModelWindow::moveHorisontal(const int delta)
{
	if ((getX() + getWidth() + delta) > MAX_WIDTH | (getX() + delta) < 0) throw "Delta x value is too big";
	setX(getX() + delta);
}

void ModelWindow::moveVertical(const int delta)
{
	if ((getY() + getHeight() + delta) > MAX_HEIGHT | (getY() + delta) < 0) throw "Delta y value is too big";
	setY(getY() + delta);
}

void ModelWindow::changeFormat(const unsigned int height, const unsigned int width)
{
	if ((getY() + height) > MAX_HEIGHT) throw "Height value is too big";
	if ((getX() + width) > MAX_WIDTH ) throw "Width value is too big";
	setHeight(height);
	setWidth(width);
}

void ModelWindow::changeVisible(const bool visible)
{
	setShow(visible);
}

bool ModelWindow::isVisible() const
{
	return getShow();
}

std::string ModelWindow::getTitle() const
{
	return this->title;
}

unsigned int ModelWindow::getX() const
{
	return this->_x;
}

unsigned int ModelWindow::getY() const
{
	return this->_y;
}

unsigned int ModelWindow::getHeight() const
{
	return this->height;
}

unsigned int ModelWindow::getWidth() const
{
	return this->width;
}

std::string ModelWindow::getColor() const
{
	return this->color;
}

bool ModelWindow::getShow() const
{
	return this->show;
}

bool ModelWindow::getBorder() const
{
	return this->border;
}

std::istream& operator>>(std::istream& in, ModelWindow& m)
{
	std::string title, color;
	unsigned int x, y, height, width;	
	bool show, border;
	in >> title >> x >> y >> width >> height >> color >> show >> border;
	m = ModelWindow(title, x, y, width, height, color, show, border);
	return in;
}

std::ostream& operator<<(std::ostream& out, const ModelWindow& m)
{
	std::string visible, border;
	visible = m.isVisible() ? "Yes" : "No";
	border = m.getBorder() ? "Yes" : "No";
	out << "Coord of high-left angle: " << m.getX() << "," << m.getY() << std::endl
		<< "Window rate: " << m.getWidth() << " X " << m.getHeight() << " px" << std::endl
		<< "BG color HEX code:  #" << m.getColor() << std::endl
		<< "Is visible: " << visible << std::endl
		<< "With border: " << border << std::endl;
	return out;
}
