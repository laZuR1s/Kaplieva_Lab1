#include <iostream>
#include<Windows.h>
#include<iomanip>

#define SQR(x) ((x)*(x)) // ������ ��� ���������� �������� �����
int main()
{
	SetConsoleOutputCP(1251);
	double x1, y1, x2, y2, x3, y3;

	std::cout << "������� ���������� ���� ����� �� ��������� \n";

	std::cout << "1-�� �����(x,y): \n";
	std::cin >> x1 >> y1;

	std::cout << "2-�� �����(x,y): \n";
	std::cin >> x2 >> y2;

	std::cout << "3-�� �����(x,y): \n";
	std::cin >> x3 >> y3;

	double a = sqrt(SQR(x1 - x2) + SQR(y1 - y2)); // ���������� ����� ������ ������������
	double b = sqrt(SQR(x2 - x3) + SQR(y2 - y3));
	double c = sqrt(SQR(x1 - x3) + SQR(y1 - y3));

	double eps = 10e-10; // �������� �������� 

	if (a > b)
		std::swap(a, b);
	if (b > c)
		std::swap(b, c); // ����� ������� �������. � ����� ������ ������� "�" ����� ����� �������

	if (a + b > c + eps) // �������� ������������� ������������
	{
		if (SQR(c) + eps < SQR(a) + SQR(b))
		{
			std::cout << "\n����������� ������������� \n\n";
			if (a != b && b != c && a != c)
			{
				double p = (a + b + c) / 2; // ���������� �������������

				double S = sqrt(p * SQR(p - a) * SQR(p - b) * SQR(p - c)); // ���������� ������� ����� ������� ������

				double H = 2 * S / c; // ���������� ������ 

				if (H < S && H < c) // ���������� � ������� �����������
				{
					std::cout << std::setw(20) << std::left << "������ ����� : " << H << '\n';
					if (S < c)
					{
						std::cout << std::setw(20) << std::left << "������� �����: " << S << '\n';
						std::cout << std::setw(20) << std::left << "������� �������: " << c << '\n';
					}
					else
					{
						std::cout << std::setw(20) << std::left << "������� �������: " << c << '\n';
						std::cout << std::setw(20) << std::left << "������� �����: " << S << '\n';
					}
				}
				if (S < H && S < c)
				{
					std::cout << std::setw(20) << std::left << "������� �����: " << S << '\n';
					if (H < c)
					{
						std::cout << std::setw(20) << std::left << "������ ����� : " << H;
						std::cout << std::setw(20) << std::left << "������� �������: " << c << '\n';
					}
					else
					{
						std::cout << std::setw(20) << std::left << "������� �������: " << c << '\n';
						std::cout << std::setw(20) << std::left << "������ ����� : " << H;
					}
				}
				if (c < S && c < H)
				{
					std::cout << std::setw(20) << std::left << "������� �������: " << c << '\n';
					if (S < H)
					{
						std::cout << std::setw(20) << std::left << "������� �����: " << S << '\n';
						std::cout << std::setw(20) << std::left << "������ ����� : " << H << '\n';
					}
					else
					{
						std::cout << std::setw(20) << std::left << "������ ����� : " << H << '\n';
						std::cout << std::setw(20) << std::left << "������� �����: " << S << '\n';
					}
				}
			}
			else
				std::cout << "\n����������� �� �������������";



		}
		else
			std::cout << "\n����������� �� �������������";

	}
	else
		std::cout << "\n���������� ��������� �����������";

	std::cin.ignore(std::cin.rdbuf()->in_avail()).get();
	return 0;
}