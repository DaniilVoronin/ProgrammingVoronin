#pragma once
#include <iostream>

/**
* \brief Класс Pair для работы с парами числел
*/
class Pair
{
protected:
    int first;
    int second;
    /**
    * \brief Сеттер 1 поля
    */
    void setFirst(const int t);
    /**
    * \brief Сеттер 2 поля
    */
    void setSecond(const int t);

    /**
    * \brief Геттер 1 поля
    */
    int getFirst() const;
    /**
    * \brief Геттер 2 поля
    */
    int getSecond() const;
public:
    /**
    * \brief Параметризованный конструктор
    */
    Pair(const int first = 0, const int second = 0);
    /**
    * \brief Деструктор
    */
    virtual ~Pair() = default;

    /**
    * \brief Перегруженный оператор больше
    */
    friend bool operator>(const Pair& p1, const Pair& p2);
    /**
    * \brief Перегруженный оператор меньше
    */
    friend bool operator<(const Pair& p1, const Pair& p2);
    /**
    * \brief Перегруженный оператор равенства
    */
    friend bool operator==(const Pair& p1, const Pair& p2);
    /**
    * \brief Перегруженный оператор неравенства
    */
    friend bool operator!=(const Pair& p1, const Pair& p2);
    /**
    * \brief Перегруженный оператор ввода
    */
    friend std::istream& operator>> (std::istream& in, Pair& p);
    /**
    * \brief Перегруженный оператор вывода
    */
    friend std::ostream& operator<< (std::ostream& out, const Pair& p);
};


/**
* \brief Класс Fraction для работы с парами числел
*/
class Fraction : public Pair
{
public:
    /**
    * \brief Параметризованный конструктор
    */
    Fraction(const int intPart = 0, const int mantis = 0);
    /**
    * \brief Деструктор
    */
    ~Fraction() = default;
    /**
    * \brief Сеттер целой части числа
    */
    void setIntPart(const int t);
    /**
    * \brief Сеттер мантисы
    */
    void setMantis(const int t);
    /**
    * \brief Геттер целой части числа
    */
    int getIntPart() const;
    /**
    * \brief Геттер мантисы
    */
    int getMantis() const;
    /**
    * \brief Перегруженный оператор больше
    */
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    /**
    * \brief Перегруженный оператор меньше
    */
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    /**
    * \brief Перегруженный оператор равенства
    */
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    /**
    * \brief Перегруженный оператор неравенства
    */
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    /**
    * \brief Перегруженный оператор ввода
    */
    friend std::istream& operator>> (std::istream& in, Fraction& f);
    /**
    * \brief Перегруженный оператор вывода
    */
    friend std::ostream& operator<< (std::ostream& out, const Fraction& f);
};
