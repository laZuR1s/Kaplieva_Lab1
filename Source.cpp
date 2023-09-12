#include <iostream>
#include<Windows.h>
#include<iomanip>
#define SQR(x) ((x)*(x)) // Макрос для вычисления квадрата числа
int main()
{
	SetConsoleOutputCP(1251);
	double x1, y1, x2, y2, x3, y3;

	std::cout << "Введите координаты трех точек на плоскости \n";

	std::cout << "1-ая точка(x,y): \n";
	std::cin >> x1 >> y1;

	std::cout << "2-ая точка(x,y): \n";
	std::cin >> x2 >> y2;

	std::cout << "3-ая точка(x,y): \n";
	std::cin >> x3 >> y3;

	double a = sqrt(SQR(x1 - x2) + SQR(y1 - y2)); // Вычисление длины сторон треугольника
	double b = sqrt(SQR(x2 - x3) + SQR(y2 - y3));
	double c = sqrt(SQR(x1 - x3) + SQR(y1 - y3));

	double eps = 10e-10; // Значение эпсилона 

	if (a > b)
		std::swap(a, b);
	if (b > c)
		std::swap(b, c); // Поиск большей стороны. В таком случае сторона "с" будет самой длинной

	if (a + b > c + eps) // Проверка существования треугольника
	{
		if (SQR(c) + eps < SQR(a) + SQR(b))
		{
			std::cout << "\nТреугольник остроугольный \n\n";
			if (a != b && b != c && a != c)
			{
				double p = (a + b + c) / 2; // Вычисление полупериметра

				double S = sqrt(p * SQR(p - a) * SQR(p - b) * SQR(p - c)); // Вычисление площади через формулу Герона

				double H = 2 * S / c; // Вычисление высоты 

				if (H < S && H < c) // Выстановка в порядке возрастания
				{
					std::cout << std::setw(20) << std::left << "Высота равна : " << H << '\n';
					if (S < c)
					{
						std::cout << std::setw(20) << std::left << "Площадь равна: " << S << '\n';
						std::cout << std::setw(20) << std::left << "Большая сторона: " << c << '\n';
					}
					else
					{
						std::cout << std::setw(20) << std::left << "Большая сторона: " << c << '\n';
						std::cout << std::setw(20) << std::left << "Площадь равна: " << S << '\n';
					}
				}
				if (S < H && S < c)
				{
					std::cout << std::setw(20) << std::left << "Площадь равна: " << S << '\n';
					if (H < c)
					{
						std::cout << std::setw(20) << std::left << "Высота равна : " << H;
						std::cout << std::setw(20) << std::left << "Большая сторона: " << c << '\n';
					}
					else
					{
						std::cout << std::setw(20) << std::left << "Большая сторона: " << c << '\n';
						std::cout << std::setw(20) << std::left << "Высота равна : " << H;
					}
				}
				if (c < S && c < H)
				{
					std::cout << std::setw(20) << std::left << "Большая сторона: " << c << '\n';
					if (S < H)
					{
						std::cout << std::setw(20) << std::left << "Площадь равна: " << S << '\n';
						std::cout << std::setw(20) << std::left << "Высота равна : " << H << '\n';
					}
					else
					{
						std::cout << std::setw(20) << std::left << "Высота равна : " << H << '\n';
						std::cout << std::setw(20) << std::left << "Площадь равна: " << S << '\n';
					}
				}
			}
			else
				std::cout << "\nТреугольник не разностронний";



		}
		else
			std::cout << "\nТреугольник не остроугольный";

	}
	else
		std::cout << "\nНевозможно построить треугольник";

	std::cin.ignore(std::cin.rdbuf()->in_avail()).get();
	return 0;
}