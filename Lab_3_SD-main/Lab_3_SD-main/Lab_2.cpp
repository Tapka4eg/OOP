#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

#include "Vector.h"
#include "Matrix.h"
#include "Fraction.h"
#include "Phone.h"

int main()
{
	std::cout << "Task 1" << "\n";
	/*Написать классы Vector и Matrix для хранения и обработки одномерных и двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1:
	Преобразование: 2D → 1D. Двумерный массив 5х3 вещественных чисел необходимо выложить в один ряд по элементам слева направо и снизу вверх.
	Инициализация: заполнить массив числами x[i][j] = sin(i–j) + cos(i+j).
	Вывод на экран: на каждый элемент массива отвести 14 позиций.
	В коде отразить следующее:
	1) Выделение и освобождение динамической памяти производить в конструкторах и деструкторах классов, соответственно.
	2) В классе Vector перегрузить оператор индексации []. В классе Matrix добавить методы T at(int i, int j) const и setAt(int i, int j, T val), которые
	позволяют получить и установить значение элемента массива с индексом [i][j], T – это тип элементов массива по варианту (int или double).
	3) Перегрузить операторы инкремента и декремента (как префиксного, так ипостфиксного). Смысл инкремента / декремента всего массива заключается в
	инкременте / декременте каждого элемента массива.*/

	Matrix array2D(5, 3);
	Vector array1D(15);

	for (int i = 0; i < array2D.getRows(); i++) 
	{
		for (int j = 0; j < array2D.getCols(); j++) 
		{
			array2D.setAt(i, j, (sin(i - j) + cos(i + j)));
		}
	}
	array2D.printFormated();
	int k = 0;
	for (int i = array2D.getRows() - 1; i >= 0; i--)
	{
		for (int j = 0; j < array2D.getCols(); j++)
		{
			array1D[k] = array2D.at(i, j);
			k++;
		}
	}
	array1D.printFormated();
	array2D--;
	--array2D;
	array2D.printFormated();
	array2D++;
	++array2D;
	array2D.printFormated();
	array1D.printFormated();
	array1D--;
	--array1D;
	array1D.printFormated();
	array1D++;
	++array1D;
	array1D.printFormated();


	std::cout << "Task 2" << "\n";
	/*Написать класс Fraction для представления обыкновенных дробей(как отношения двух целых чисел x / y).
	Перегрузить операторы + , -, *, / для дробей.Реализовать метод void reduce() для сокращения дроби, а также статические методы :
	1) int gcd(int n, int m) - функция для нахождения наибольшего общего делителя чисел n и m;
	2) void printAsFraction(double decimal_fraction)
	3) void printAsFraction(char* decimal_fraction)
	перегруженные методы вывода десятичной дроби в виде обыкновенной
	(например, при значении decimal_fraction = 0.43 на экране должно вывестись 43 / 100, при 0.25 – 1 / 4 и т.д.).
	Также реализовать в виде статического члена класса счетчик всех созданных на данный момент в программе экземпляров дробей.*/

	Fraction a(1, 2);
	Fraction b(2, 3);
	Fraction c = a + b;
	Fraction d = a - b;
	Fraction e = a * b;
	Fraction f = a / b;
	a.printFraction();
	b.printFraction();
	c.printFraction();
	d.printFraction();
	e.printFraction();
	f.printFraction();
	std::cout << "\n";
	char test1[] = "0.25";
	double test2 = 0.25;
	Fraction::printAsFraction(test1);
	Fraction::printAsFraction(test2);
	std::cout << "Total fractions: " << a.getTotalFractions() << "\n";

	std::cout << "Task 3" << "\n";
	/*Написать собственный класс, в соответствии с вариантом.Продемонстрировать в коде инкапсуляцию данных, применение конструкторов без параметров и с параметрами
	для инициализации данных.Класс должен содержать метод serialize() для сохранения данных класса в файл и метод deserialize() для чтения данных класса 
	из файла по умолчанию в текущей директории, а также перегруженные методы serialize(const std::string & filename) и deserialize(const std::string & filename) 
	для работы с файлом с указанным в параметре именем.
	Класс ТЕЛЕФОН.
	Данные: модель, номер телефона, последний набранный номер, остаток на счету.
	Создать два телефона в куче. Установить данные первого телефона с помощью сеттеров, второго – в конструкторе с параметрами. В главной функции проимитировать десять
	звонков – позвонить по нескольку раз на 3 номера, в том числе на номер другого телефона в программе. За каждую минуту разговора снимается 0,5 руб. Вывести всю
	информацию о телефонах после проведенных звонков.
	*/
	Phone* phone1 = new Phone("Xiaomi Redmi Note 7", "+38(071)396-84-69", "none", 150);
	Phone* phone2 = new Phone();
	phone2->setModel("Samsung J1 Ace");
	phone2->setNumber("+38(066)962-31-81");
	phone2->setLastNuber("none");
	phone2->setBill(100);

	phone1->call(phone2->getNumber(), 15);
	phone2->call(phone1->getNumber(), 10);
	phone1->call(phone2->getNumber(), 60);
	phone2->call(phone1->getNumber(), 30);
	phone1->getInfo();
	phone2->getInfo();

	phone1->call("+75(09)629-06-52", 15);
	phone2->call("+1(67)227-73-69", 10);
	phone1->call("+75(09)629-06-52", 3600);
	phone2->call("+1(67)227-73-69", 3600);
	
	phone1->call(phone2->getNumber(), 15);
	phone2->call(phone1->getNumber(), 10);

	phone1->getInfo();
	phone2->getInfo();
}
